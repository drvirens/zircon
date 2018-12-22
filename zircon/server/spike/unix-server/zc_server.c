#include <errno.h>
#include <ev.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>

#include "zc_server.h"
#include "zc_alloc.h"
#include "zc_assert.h"
#include "zc_client.h"
#include "zc_log.h"
#include "zc_socket.h"

// ----------------------------------------------------------------------
// Private Declarations

struct tag_server {
  ev_io io_;
  struct ev_loop* evt_loop_;
  int fd_;
  struct sockaddr_un addr_;
  char* unix_socket_path_;
  zc_socket_t* socket_;
};

// SOMAXCONN = 128
#define ZC_SERVER_BACKLOG 64

#if defined DEBUG
#define MAX_ACCEPTS_PER_INVOCATION 2 //10
#else
#define MAX_ACCEPTS_PER_INVOCATION 2 //100
#endif


ZC_PRIVATE int zc_create_socket(zc_server_t* server, const char* path);
ZC_PRIVATE void __server_did_accept_client_socket(EV_P_ ev_io* io_watcher, int revents);

// ---------------------------------------------------------------------- Public
// Impl
static zc_server_t g_server;
zc_server_t* SERVER_alloc(const char* path)
{TRACE
  memset(&g_server, 0, sizeof(g_server));
  zc_server_t* s = &g_server;
  if (path && path[0] != '\0') {
    char* b = (char*)ZIRCON_malloc(strlen(path));
    if (b) {
      strcpy(b, path);
    }
    s->unix_socket_path_ = b;
  }
  return s;
}
void SERVER_dealloc(zc_server_t* thiz)
{TRACE
  if (thiz) {
  }
}

ZC_PUBLIC int SERVER_start(zc_server_t* thiz)
{TRACE
  ASSERT_is_null((thiz->evt_loop_)); // not null whoa
  thiz->evt_loop_ = EV_DEFAULT;

  int err = zc_create_socket(thiz, thiz->unix_socket_path_);
  if (err == zc_ok) {
    LOG_v("socket created.", "");
  }

  return err;
}

// ----------------------------------------------------------------------
// Private Impl
int zc_create_socket(zc_server_t* server, const char* path)
{TRACE
  int err = zc_socket_error;

  server->socket_ = SOCKET_alloc(zc_socket_type_unix);
  
  zc_socket_error_e e;

  e = SOCKET_socket_un(server->socket_, server->unix_socket_path_, &(server->fd_));

  if (e != zc_socket_err_ok) {
    LOG_v("couldnot create socket", "");
    return err;
  }
  e =  SOCKET_set_nonblocking(server->fd_);
  if (e != zc_socket_err_ok) {
    LOG_v("couldnot set nonblocking for socket", "");
  }
  e =  SOCKET_set_tcpnodelay(server->fd_);
  if (e != zc_socket_err_ok) {
    LOG_v("couldnot set tcpnodelay for socket", "");
  }
  e =  SOCKET_set_keepalive(server->fd_);
  if (e != zc_socket_err_ok) {
    LOG_v("couldnot set keepalive for socket", "");
  }
  e = SOCKET_bind_n_listen(server->socket_, server->fd_, &(server->addr_), ZC_SERVER_BACKLOG);
  if (e != zc_socket_err_ok) {
    LOG_v("couldnot bind", "");
    return err;
  }
  

  LOG_v("looping...", "");


  ev_io_init(&server->io_, __server_did_accept_client_socket, server->fd_, EV_READ);
  ev_io_start(server->evt_loop_, &server->io_);
  ev_run(server->evt_loop_, 0);

  //
  // ------------------------- close
  //
  close(server->fd_);
  
  SOCKET_dealloc(server->socket_);

  LOG_v("Looped!", "");

  return zc_ok;
}

#pragma mark-- libev callbacks
ZC_PRIVATE void __server_add_client(zc_server_t* server, zc_client_t* client) {TRACE
  
}
ZC_PRIVATE void __pri_accept_many_connections(zc_server_t* server, int sfd)
{//TRACE
  int cfd;
  int max = 1; //MAX_ACCEPTS_PER_INVOCATION;
  while (max--) {
      zc_socket_error_e e = SOCKET_accept_un(sfd, &cfd);
      if (e == zc_socket_err_failed) {
        LOG_v("error in SOCKET_accept_un", "");
        break;
      } else {
        zc_client_t* c = CLIENT_alloc(cfd);
        if (c) {
          __server_add_client(server, c);
        }
      }
  }
}
void __server_did_accept_client_socket(EV_P_ ev_io* io_watcher, int revents)
{//TRACE
  zc_server_t* server = (zc_server_t*)io_watcher;
  if (server) {
    __pri_accept_many_connections(server, io_watcher->fd);
  }
}
