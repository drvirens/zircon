#include <errno.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>

#include "zc_socket_t.h"
#include "zc_alloc.h"
#include "zc_assert.h"
#include "zc_global_constants.h"
#include "zc_log.h"

#define PRECONDITION(thiz_ptr)    \
  zc_assert_not_null((thiz_ptr)); \
  if (!(thiz_ptr)) {              \
    return zc_socket_err_failed;  \
  }

// ----------------------------------------------------------------------
// Private Declarations

struct tag_zc_socket {
  int fd_;
  struct sockaddr_un addr_;
  char unix_socket_path_[k_global_path_len];
  zc_socket_type type_;
};

// ----------------------------------------------------------------------
// Private Function Prototypes
ZC_PRIVATE void __pri_common_init(zc_socket_t* thiz);
ZC_PRIVATE zc_socket_error_e __pri_unix_bind_and_listen(zc_socket_t* thiz, int fd, struct sockaddr_un* sa, int backlog);
ZC_PRIVATE int __pri_basic_accept(int serversocketfd, struct sockaddr* sa, socklen_t* len);
ZC_PRIVATE zc_socket_error_e __pri_unix_accept(int serversocketfd, int *accepted_fd);

// ---------------------------------------------------------------------- Public
// API

ZC_PUBLIC zc_socket_t* new_zc_socket(zc_socket_type type)
{
  TRACE
  zc_socket_t* obj = (zc_socket_t*)zc_malloc(sizeof(zc_socket_t));
  if (obj) {
    memset(obj, 0, sizeof(zc_socket_t));
    obj->type_ = type;
    __pri_common_init(obj);
  }
  return obj;
}

ZC_PUBLIC void delete_instance(zc_socket_t* thiz)
{
  TRACE
  if (thiz) {
    unlink(thiz->unix_socket_path_);
    zc_free(thiz);
  }
}

ZC_PUBLIC zc_socket_error_e socket_create_unix_socket(zc_socket_t* thiz,
    const char* local_path,
    int* fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  // validate the path
  if (!(local_path && local_path[0] != '\0')) {
    e = zc_socket_invalid_path;
    return e;
  }
  size_t pathlen = strlen(local_path);
  if (pathlen >= k_global_path_len - 1) {
    e = zc_socket_invalid_path;
    return e;
  }

  // copy path
  strcpy(thiz->unix_socket_path_, local_path);

  //
  // ------------------------- socket
  //
  int sfd = zc_net_socket(AF_UNIX, SOCK_STREAM, 0);
  if (sfd < 0) {
    e = zc_socket_invalid_path;
    return e;
  }

  *fd = sfd;

  e = zc_socket_err_ok;

  return e;
}

ZC_PUBLIC zc_socket_error_e socket_set_reuseportaddress(zc_socket_t* thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  int reuse = 1;
  int err = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse,
      sizeof(reuse));
  if (err < 0) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return 0;
}

ZC_PUBLIC zc_socket_error_e socket_set_nonblocking(zc_socket_t* thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  int flags;
  flags = fcntl(fd, F_GETFL);
  if (flags < 0) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  flags |= O_NONBLOCK;
  int err = fcntl(fd, F_SETFL, flags);
  if (-1 == err) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return e;
}
ZC_PUBLIC zc_socket_error_e socket_set_tcpnodelay(zc_socket_t* thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;

  int val;
  int err = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val));
  if (-1 == err) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return e;
}
ZC_PUBLIC zc_socket_error_e socket_set_keepalive(zc_socket_t* thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  int oui = 1;
  int err = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &oui, sizeof(oui));
  if (-1 == err) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    return e;
  }
  e = zc_socket_err_ok;
  return e;
}
ZC_PUBLIC zc_socket_error_e socket_bind_and_listen(zc_socket_t* thiz, int fd, struct sockaddr_un* sa, int backlog)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  if (thiz->type_ == zc_socket_type_unix) {
    e = __pri_unix_bind_and_listen(thiz, fd, sa, backlog);
  }
  return e;
}
ZC_PUBLIC zc_socket_error_e socket_connect(zc_socket_t* thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  return e;
}
ZC_PUBLIC zc_socket_error_e socket_accept(zc_socket_t* thiz, int fd)
{
  TRACE
  PRECONDITION(thiz);
  zc_socket_error_e e = zc_socket_err_failed;
  int accepted_fd;
  e = __pri_unix_accept(fd, &accepted_fd);
  return e;
}
ZC_PUBLIC const char* socket_error_msg(zc_socket_t* thiz)
{
  TRACE
  char* err_was = strerror(errno);
  return (const char*)err_was;
}

#pragma mark - Private
ZC_PRIVATE void __pri_common_init(zc_socket_t* thiz){ TRACE }

ZC_PRIVATE zc_socket_error_e __pri_unix_bind_and_listen(zc_socket_t* thiz, int fd,
    struct sockaddr_un* sa, int backlog)
{
  TRACE
  zc_socket_error_e e = zc_socket_err_failed;

  memset(sa, 0, sizeof(struct sockaddr_un));
  sa->sun_family = AF_LOCAL;
  strncpy(sa->sun_path, thiz->unix_socket_path_, sizeof(sa->sun_path) - 1);

  //
  // ------------------------- access
  //
  // do we hace access to this path?
  int err = access(sa->sun_path, F_OK);
  if (0 == err) {
    LOGV("fock. error. bogus path cant access.", "");
    unlink(sa->sun_path);
    return e;
  }

  //
  // ------------------------- bind
  //
  err = zc_net_bind(fd, (struct sockaddr*)sa, sizeof(struct sockaddr_un));
  if (err < 0) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    unlink(sa->sun_path);
    return e;
  }

  //
  // ------------------------- listen
  //
  err = zc_net_listen(fd, backlog);
  if (err < 0) {
    char* err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    unlink(sa->sun_path);
    return e;
  }

  e = zc_socket_err_ok;
  return e;
}

ZC_PRIVATE int __pri_basic_accept(int serversocketfd, struct sockaddr* sa, socklen_t* len)
{
  zc_socket_error_e e = zc_socket_err_failed;
  int fd;
  while (1) {
    fd = zc_net_accept(serversocketfd, sa, len);
    if (-1 == fd) {
      if (errno == EINTR) { // sys call interuppted
        continue;
      } else {
        return fd; //-1
      }
    }
    break;
  }
  return fd;
}
ZC_PRIVATE zc_socket_error_e __pri_unix_accept(int serversocketfd, int *accepted_fd)
{
  zc_socket_error_e e = zc_socket_err_failed;
  int fd;
  struct sockaddr_un sa;
  socklen_t slen = sizeof(sa);
  fd = __pri_basic_accept(serversocketfd, (struct sockaddr*)&sa, &slen);
  if (fd == -1) {
    LOGV("error in zc_net_basic_accept", "");
    return e;
  }
  *accepted_fd = fd;
  e = zc_socket_err_ok;
  return e;
}
