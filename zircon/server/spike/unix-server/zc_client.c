#include <string.h>
#include <ev.h>
#include "zc_client.h"
#include "zc_alloc.h"
#include "zc_socket.h"
#include "zc_log.h"


ZC_PRIVATE void recv_socket_cb(struct ev_loop* loop, ev_io* w, int revents);
ZC_PRIVATE void write_socket_cb(struct ev_loop* loop, ev_io* w, int revents);


// ----------------------------------------------------------------------
// Private Declarations
struct tag_zc_client {
  uint64_t id_;
  int fd_;
};

// ----------------------------------------------------------------------
// Private Functions Declarations
ZC_PRIVATE void __common_init(zc_client_t* c, int fd);

// ---------------------------------------------------------------------- Public
// Impl

ZC_PUBLIC zc_client_t* CLIENT_alloc(int fd)
{TRACE
  zc_client_t* obj = (zc_client_t*)ZIRCON_malloc(sizeof(zc_client_t));
  if (obj) {
    memset(obj, 0, sizeof(zc_client_t));
    __common_init(obj, fd);
  }
  return obj;
}
ZC_PUBLIC void CLIENT_dealloc(zc_client_t* thiz)
{TRACE
  if (thiz) {
    SOCKET_close(thiz->fd_);
    free(thiz);
    thiz = 0;
  }
}

// ----------------------------------------------------------------------
// Private Impl
ZC_PRIVATE void __common_init(zc_client_t* c, int fd)
{TRACE
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
}
