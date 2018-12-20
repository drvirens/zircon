#include <memory.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#include "zc_socket.h"
#include "zc_log.h"
#include "zc_alloc.h"
#include "zc_assert.h"
#include "zc_global_constants.h"

#define PRECONDITION(thiz_ptr)    \
  zc_assert_not_null((thiz_ptr)); \
  if (!(thiz_ptr))                \
  {                               \
    return zc_socket_err_failed;  \
  }

// ---------------------------------------------------------------------- Private Declarations

struct tag_zc_socket
{
  int fd_;
  struct sockaddr_un addr_;
  char unix_socket_path_[k_global_path_len];
};

// ---------------------------------------------------------------------- Private Function Prototypes
ZCPRIVATE void __pri_common_init(zc_socket *thiz);

// ---------------------------------------------------------------------- Public API

ZCEXPORT zc_socket *new_instance()
{
  TRACE
  zc_socket *obj = (zc_socket *)zc_malloc(sizeof(zc_socket));
  if (obj)
  {
    memset(obj, 0, sizeof(zc_socket));
    __pri_common_init(obj);
  }
  return obj;
}

ZCEXPORT void delete_instance(zc_socket *thiz)
{
  TRACE
  if (thiz)
  {
    zc_free(thiz);
  }
}

ZCEXPORT zc_socket_error_e socket_create_unix_socket(zc_socket *thiz, const char *local_path, int *fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  //validate the path
  if (!(local_path && local_path[0] != '\0'))
  {
    e = zc_socket_invalid_path;
    return e;
  }
  size_t pathlen = strlen(local_path);
  if (pathlen >= k_global_path_len - 1)
  {
    e = zc_socket_invalid_path;
    return e;
  }

  //copy path
  strcpy(thiz->unix_socket_path_, local_path);

  //
  // ------------------------- socket
  //
  int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sfd < 0)
  {
    e = zc_socket_invalid_path;
    return e;
  }

  *fd = sfd;

  e = zc_socket_err_ok;

  return e;
}

ZCPRIVATE int zc_enable_reuse_port_address(int fd)
{

  int reuse = 1;
  int e = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuse, sizeof(reuse));
  if (e < 0)
  {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
  }

  return 0;
}

ZCEXPORT zc_socket_error_e socket_config_enable_nonblocking(zc_socket *thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  int flags;
  flags = fcntl(fd, F_GETFL);
  if (flags < 0)
  {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  flags |= O_NONBLOCK;
  int err = fcntl(fd, F_SETFL, flags);
  if (-1 == err)
  {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return e;
}
ZCEXPORT zc_socket_error_e socket_config_enable_tcpnodelay(zc_socket *thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  int val;
  int err = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val));
  if (-1 == err)
  {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return e;
}
ZCEXPORT zc_socket_error_e socket_config_enable_keepalive(zc_socket *thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  int oui = 1;
  int err = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &oui, sizeof(oui));
  if (-1 == err)
  {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return e;
}
ZCEXPORT zc_socket_error_e socket_bind_and_listen(zc_socket *thiz)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_connect(zc_socket *thiz)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT zc_socket_error_e socket_accept(zc_socket *thiz)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZCEXPORT const char *socket_error_msg(zc_socket *thiz)
{
  TRACE
  char *err_was = strerror(errno);
  return (const char *)err_was;
}

#pragma mark - Private
ZCPRIVATE void __pri_common_init(zc_socket *thiz)
{
  TRACE
}
