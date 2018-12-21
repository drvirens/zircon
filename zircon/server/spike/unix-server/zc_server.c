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
  int fd_;
  struct sockaddr_un addr_;
  char* unix_socket_path_;
  ev_io io_;
  struct ev_loop* evt_loop_;
  
  zc_socket_t* socket_;
};

// SOMAXCONN = 128
#define ZC_SERVER_BACKLOG 100

ZC_PRIVATE int zc_create_socket(zc_server_t* server, const char* path);
ZC_PRIVATE void recv_socket_cb(struct ev_loop* loop, ev_io* w, int revents);
ZC_PRIVATE void write_socket_cb(struct ev_loop* loop, ev_io* w, int revents);
ZC_PRIVATE void __server_did_accept_client_socket(EV_P_ ev_io* io_watcher, int revents);

// ---------------------------------------------------------------------- Public
// Impl
static zc_server_t g_server;
zc_server_t* zc_server_new(const char* path)
{TRACE
  memset(&g_server, 0, sizeof(g_server));
  zc_server_t* s = &g_server;
  if (path && path[0] != '\0') {
    char* b = (char*)zc_malloc(strlen(path));
    if (b) {
      strcpy(b, path);
    }
    s->unix_socket_path_ = b;
  }

  return s;
}

ZC_PUBLIC int zc_server_start(zc_server_t* server)
{TRACE
  zc_assert_null((server->evt_loop_)); // not null whoa
  server->evt_loop_ = EV_DEFAULT;

  int err = zc_create_socket(server, server->unix_socket_path_);
  if (err == zc_ok) {
    LOGV("socket created.", "");
    zc_log(zc_log_level_verbose, "yoyo %s", "whoattttt");
  }

  return 0;
}

// ----------------------------------------------------------------------
// Private Impl
int zc_create_socket(zc_server_t* server, const char* path)
{TRACE
  int err = zc_socket_error;

  server->socket_ = new_zc_socket(zc_socket_type_unix);
  
  zc_socket_error_e e;
  e = socket_create_unix_socket(server->socket_, server->unix_socket_path_, &(server->fd_));
  
  //e =  socket_set_nonblocking(server->socket_, server->fd_);
  //e =  socket_set_tcpnodelay(server->socket_, server->fd_);
  //e =  socket_set_keepalive(server->socket_, server->fd_);
  
  e = socket_bind_and_listen(server->socket_, server->fd_, &(server->addr_), ZC_SERVER_BACKLOG);
  if (e != zc_socket_err_ok) {
    LOGV("couldnot bind", "");
    return err;
  }
  
  
  
  LOGV("looping...", "");

  ev_io_init(&server->io_, __server_did_accept_client_socket, server->fd_,
      EV_READ);
  ev_io_start(server->evt_loop_, &server->io_);

  ev_run(server->evt_loop_, 0);

  //
  // ------------------------- close
  //
  close(server->fd_);

  LOGV("Looped!", "");

  return zc_ok;
}

#pragma mark-- libev callbacks
void __server_did_accept_client_socket(EV_P_ ev_io* io_watcher, int revents)
{TRACE
//  int ss = io_watcher->fd;
//  int fd = zc_net_unix_accept(ss);
//  if (fd == -1) {
//    LOGV("error in zc_net_unix_accept", "");
//  }
//  zc_client_t* c = zc_client_new(fd);
}
