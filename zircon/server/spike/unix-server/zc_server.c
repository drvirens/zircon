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
ZC_PRIVATE int zc_zero_all_fields(zc_server_t* server);
ZC_PRIVATE int zc_set_socket_non_blocking(int fd);
ZC_PRIVATE int zc_enable_tcp_no_delay(int fd);
ZC_PRIVATE int zc_enable_keep_alive(int fd);
ZC_PRIVATE int zc_enable_reuse_port_address(int fd);
ZC_PRIVATE void __server_did_accept_client_socket(EV_P_ ev_io* watcher,
    int revents);
ZC_PRIVATE void recv_socket_cb(struct ev_loop* loop, ev_io* w, int revents);
ZC_PRIVATE void write_socket_cb(struct ev_loop* loop, ev_io* w, int revents);

// ---------------------------------------------------------------------- Public
// Impl
static zc_server_t g_server;
zc_server_t* zc_server_new(const char* path)
{
  zc_log(zc_log_level_verbose, "this is the fmt specificer %s",
      "whoattttt-zc_server_new");
  zc_server_t* s = &g_server;
  zc_zero_all_fields(s);
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
{
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
{
  int err = zc_socket_error;

  server->socket_ = new_zc_socket(zc_socket_type_unix);
  
  zc_socket_error_e e;
  e = socket_create_unix_socket(server->socket_, "/tmp/zircon.sock", &(server->fd_));
  
  e =  socket_set_nonblocking(server->socket_, server->fd_);
  //e =  socket_set_tcpnodelay(server->socket_, server->fd_);
  e =  socket_set_keepalive(server->socket_, server->fd_);
  
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
int zc_zero_all_fields(zc_server_t* server)
{
  memset(server, 0, sizeof(zc_server_t));
  return zc_ok;
}

ZC_PRIVATE int zc_set_socket_non_blocking(int fd)
{
  //#if 0
  int flags;
  flags = fcntl(fd, F_GETFL);
  if (flags < 0) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return -1;
  }
  flags |= O_NONBLOCK;
  int e = fcntl(fd, F_SETFL, flags);
  if (-1 == e) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
  }
  return e;
  //#endif
  //  return 0;
}
ZC_PRIVATE int zc_enable_tcp_no_delay(int fd)
{
#if 0
  int val;
  int e = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val));
  if (-1 == e) {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
  }
  return e;
#endif
  return 0;
}
ZC_PRIVATE int zc_enable_keep_alive(int fd)
{
#if 0
  int oui = 1;
  int e = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &oui, sizeof(oui));
  if (-1 == e) {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
  }
  return e;
#endif
  return 0;
}
ZC_PRIVATE int zc_enable_reuse_port_address(int fd)
{
#if 0
  int reuse = 1;
  int e =  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse));
  if (e < 0) {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
  }
#endif
  return 0;
}

#pragma mark-- libev callbacks
int zc_net_basic_accept(int serversocketfd, struct sockaddr* sa,
    socklen_t* len)
{
  int fd;
  while (1) {
    fd = accept(serversocketfd, sa, len);
    if (-1 == fd) {
      if (errno == EINTR) { // sys call interuppted
        continue;
      }
      //        else {
      //          //fuck this noise. just fucking return
      //          return fd; //-1
      //        }
    }
    break;
  }
  return fd;
}
int zc_net_unix_accept(int serversocketfd)
{
  int fd;
  struct sockaddr_un sa;
  socklen_t slen = sizeof(sa);
  fd = zc_net_basic_accept(serversocketfd, (struct sockaddr*)&sa, &slen);
  if (fd == -1) {
    LOGV("error in zc_net_basic_accept", "");
  }
  return fd;
}

void __server_did_accept_client_socket(EV_P_ ev_io* io_watcher, int revents)
{
  LOGV("__server_did_accept_client_socket", "");

  int ss = io_watcher->fd;
  int fd = zc_net_unix_accept(ss);
  if (fd == -1) {
    LOGV("error in zc_net_unix_accept", "");
  }
  zc_client_t* c = zc_client_new(fd);

#if 0
  int fd;
  int s = io_watcher->fd;
  struct sockaddr_un sin;
  socklen_t addrlen = sizeof(struct sockaddr);
  do {
    fd = accept(s, (struct sockaddr *)&sin, &addrlen);
    if(fd > 0) {
      break;
    }
    if(errno == EAGAIN || errno == EWOULDBLOCK) {
      continue;
    }
  } while(1);
#endif
  //  zc_client_t *c = zc_client_new(fd);
  //
  //  ev_io* accept_watcher = malloc(sizeof(ev_io));
  //  memset(accept_watcher,0x00,sizeof(ev_io));
  //  ev_io_init(accept_watcher,recv_socket_cb,fd,EV_READ);
  //  ev_io_start(loop,accept_watcher);
}

#define MAX_BUF_LEN 1024
void recv_socket_cb(struct ev_loop* loop, ev_io* w, int revents)
{
  char buf[MAX_BUF_LEN];
  int ret = 0;

  do {
    ret = recv(w->fd, buf, MAX_BUF_LEN - 1, 0);
    if (ret > 0) {
      printf("recv message:'%s'", buf);
      printf("\n");
      ev_io_stop(loop, w);
      ev_io_init(w, write_socket_cb, w->fd, EV_WRITE);
      ev_io_start(loop, w);
      return;
    }

    if (ret == 0) {
      printf("remote socket closed \n");
      break;
    }

    if (errno == EAGAIN || errno == EWOULDBLOCK) {
      continue;
    }
    break;
  } while (1);

  close(w->fd);
  ev_io_stop(loop, w);
  free(w);
}

void write_socket_cb(struct ev_loop* loop, ev_io* w, int revents)
{
  char buf[MAX_BUF_LEN] = { 0 };

  snprintf(buf, MAX_BUF_LEN - 1, "this is test message from libev \n");

  // write(w->fd,buf,strlen(buf),0);
  send(w->fd, buf, strlen(buf), 0);

  ev_io_stop(loop, w);
  ev_io_init(w, recv_socket_cb, w->fd, EV_READ);
  ev_io_start(loop, w);
}
