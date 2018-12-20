#include <memory.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "zc_socket.h"
#include "zc_log.h"
#include "zc_alloc.h"
#include "zc_assert.h"
#include "zc_assert.h"
#include "zc_global_constants.h"

// ---------------------------------------------------------------------- Private Declarations

struct tag_zc_socket
{
  int fd_;
  struct sockaddr_un addr_;
  char unix_socket_path_[k_global_path_len];
};

// ---------------------------------------------------------------------- Private Function Prototypes

// ---------------------------------------------------------------------- Public API

ZCEXPORT zc_socket *new_instance()
{
  TRACE
  zc_socket *obj = (zc_socket *)zc_malloc(sizeof(zc_socket));
  if (obj)
  {
  }
  return obj;
}
ZCEXPORT void delete_instance(zc_socket *thiz){TRACE

}

ZCEXPORT zc_socket_error_e socket_create_unix_socket(zc_socket *thiz, const char *local_path)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_config_enable_nonblocking(zc_socket *thiz)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_config_enable_tcpnodelay(zc_socket *thiz)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_config_enable_keepalive(zc_socket *thiz)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_bind_and_listen(zc_socket *thiz)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_connect(zc_socket *thiz)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_accept(zc_socket *thiz)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT const char *socket_error_msg(zc_socket *thiz)
{
  TRACE
  return 0;
}
