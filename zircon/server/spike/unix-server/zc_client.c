#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <ev.h>
#include "zc_client.h"
#include "zc_alloc.h"
#include "zc_socket.h"
#include "zc_log.h"

// ----------------------------------------------------------------------
// Private Declarations

typedef enum zc_client_flags {
  k_client_marked_shutdown     = (1 << 0),
  k_client_already_handshaked  = (1 << 1)
} zc_client_flags_e;

typedef struct zc_client_context {
  uint64_t id_;
  time_t created_at_;
  
  int fd_;
  ev_io reader_;
  ev_io writer_;
  struct ev_loop *loop_;
} zc_client_context_t;

struct zc_client {
  zc_client_context_t context_;
};

// ----------------------------------------------------------------------
// Private Functions Declarations
ZC_PRIVATE void __init(zc_client_t* thiz, int fd);
static void write_socket_cb(struct ev_loop* loop, ev_io* w, int revents);
static void recv_socket_cb(struct ev_loop* loop, ev_io* w, int revents);


// ---------------------------------------------------------------------- Public
// Impl

ZC_PUBLIC zc_client_t* CLIENT_alloc(int fd, struct ev_loop *loop)
{TRACE
  zc_client_t* obj = (zc_client_t*)ZIRCON_malloc(sizeof(zc_client_t));
  if (obj) {
    memset(obj, 0, sizeof(zc_client_t));
    obj->context_.loop_ = loop;
    __init(obj, fd);
  }
  return obj;
}
ZC_PUBLIC void CLIENT_dealloc(zc_client_t* thiz)
{TRACE
  if (thiz) {
    SOCKET_close(thiz->context_.fd_);
    free(thiz);
    thiz = 0;
  }
}

// ----------------------------------------------------------------------
// Private Impl
ZC_PRIVATE void __client_read_cb(EV_P_ ev_io *w, int revents) {TRACE
  recv_socket_cb(EV_A_ w, revents);
}
ZC_PRIVATE void __client_write_cb(EV_P_ ev_io *w, int revents) {TRACE
  write_socket_cb(EV_A_ w, revents);
}
ZC_PRIVATE void __setup_io_watchers(zc_client_t* thiz, int fd) {
  ev_io_init(&thiz->context_.reader_, __client_read_cb, fd, EV_READ);
  ev_io_init(&thiz->context_.writer_, __client_write_cb, fd, EV_WRITE);
  thiz->context_.reader_.data = thiz;
  thiz->context_.writer_.data = thiz;
  ev_io_start(thiz->context_.loop_, &thiz->context_.reader_);
  ev_io_start(thiz->context_.loop_, &thiz->context_.writer_);
}
ZC_PRIVATE void __init(zc_client_t* thiz, int fd)
{TRACE
  thiz->context_.created_at_ = time(NULL);
  thiz->context_.fd_ = fd;
  
  zc_socket_error_e e;
  e =  SOCKET_set_nonblocking(fd);
  if (e != zc_socket_err_ok) {
    LOG_v("client couldnot set nonblocking for socket", "");
  }
  e =  SOCKET_set_tcpnodelay(fd);
  if (e != zc_socket_err_ok) {
    LOG_v("client couldnot set tcpnodelay for socket", "");
  }
  e =  SOCKET_set_keepalive(fd);
  if (e != zc_socket_err_ok) {
    LOG_v("client couldnot set keepalive for socket", "");
  }
  
  __setup_io_watchers(thiz, fd);
}

#define MAX_BUF_LEN 1024
static void recv_socket_cb(struct ev_loop* loop, ev_io* w, int revents)
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

static void write_socket_cb(struct ev_loop* loop, ev_io* w, int revents)
{
  char buf[MAX_BUF_LEN] = { 0 };
  
  snprintf(buf, MAX_BUF_LEN - 1, "this is test message from libev \n");
  
    // write(w->fd,buf,strlen(buf),0);
  send(w->fd, buf, strlen(buf), 0);
  
  ev_io_stop(loop, w);
  ev_io_init(w, recv_socket_cb, w->fd, EV_READ);
  ev_io_start(loop, w);
}


