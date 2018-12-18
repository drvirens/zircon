#include <memory.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ev.h>

#include "zc_server.h"
#include "zc_log.h"
#include "zc_alloc.h"

// ---------------------------------------------------------------------- Private Declarations

struct tag_server
{
  int fd_;
  struct sockaddr_un addr_;
  char *unix_socket_path_;
  ev_io io_;
  struct ev_loop *evt_loop_;
};

//SOMAXCONN = 128
#define ZC_SERVER_BACKLOG 100

ZCPRIVATE int zc_create_socket(zc_server_t *server, const char *path);
ZCPRIVATE int zc_zero_all_fields(zc_server_t *server);
ZCPRIVATE int zc_set_socket_non_blocking(int fd);
ZCPRIVATE int zc_enable_tcp_no_delay(int fd);
ZCPRIVATE int zc_enable_keep_alive(int fd);
ZCPRIVATE int zc_enable_reuse_port_address(int fd);

// ---------------------------------------------------------------------- Public Impl
static zc_server_t g_server;
zc_server_t *zc_server_new(const char *path)
{
  zc_log(zc_log_level_verbose, "this is the fmt specificer %s", "whoattttt-zc_server_new");
  zc_server_t *s = &g_server;
  zc_zero_all_fields(s);
  if (path && path[0] != '\0')
  {
    char *b = (char *)zc_malloc(strlen(path));
    if (b)
    {
      strcpy(b, path);
    }
    s->unix_socket_path_ = b;
  }

  return s;
}

ZCEXPORT int zc_server_start(zc_server_t *server)
{
  
  zc_assert (server->evt_loop_ == 0);
  server->evt_loop_ = EV_DEFAULT;
  
  int err = zc_create_socket(server, server->unix_socket_path_);
  if (err == zc_ok)
  {
    LOGV("socket created.", "");
    zc_log(zc_log_level_verbose, "yoyo %s", "whoattttt");
  }
  return 0;
}

// ---------------------------------------------------------------------- Private Impl
int zc_create_socket(zc_server_t *server, const char *path)
{
  int err = zc_socket_error;
  server->fd_ = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server->fd_ < 0)
  {
    LOGV("could not create unix socket ", "");
    return err;
  }

  zc_set_socket_non_blocking(server->fd_);
  zc_enable_tcp_no_delay(server->fd_);
  zc_enable_keep_alive(server->fd_);
#if defined DEBUG
  zc_enable_reuse_port_address(server->fd_);
#endif

  memset(&server->addr_, 0, sizeof(struct sockaddr_un));
  server->addr_.sun_family = AF_UNIX;
  strncpy(server->addr_.sun_path, path, sizeof(server->addr_.sun_path) - 1);

  // do we hace access to this path?
  err = access(server->addr_.sun_path, F_OK);
  if (0 == err)
  {
    LOGV("fock. error. bogus path cant access.", "");
    unlink(server->addr_.sun_path);
    return -1;
  }

  err = bind(server->fd_, (struct sockaddr *)&server->addr_, sizeof(struct sockaddr_un));
  if (err < 0)
  {
    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    unlink(server->addr_.sun_path);
    return -1;
  }

  err = listen(server->fd_, ZC_SERVER_BACKLOG);
  if (err < 0)
  {

    char *err_was = strerror(errno);
    LOGE("Error occured: %s", err_was);
    unlink(server->addr_.sun_path);
    return -1;
  }

  LOGV("looping...", "");

  for (;;)
  {
    int client_fd = accept(server->fd_, 0, 0);
    if (client_fd < 0)
    {
      LOGV("accept error", "");
    }
    else
    {
      //todo: do below inside client??
      //zc_set_socket_non_blocking(client_fd);
      //zc_enable_tcp_no_delay(client_fd);
      //zc_enable_keep_alive(client_fd);
    }
    char buf[256] = {0};
    ssize_t bytes;
    while ((bytes = read(client_fd, buf, 255)) > 0)
    {
      printf("read [%u] bytes: {%.*s}\n", bytes, bytes, buf);
    }
  } //end-for

  close(server->fd_);

  LOGV("Looped!", "");

  return zc_ok;
}
int zc_zero_all_fields(zc_server_t *server)
{
  memset(server, 0, sizeof(zc_server_t));
  return zc_ok;
}

ZCPRIVATE int zc_set_socket_non_blocking(int fd)
{
#if 0
  int flags;
  flags = fcntl(fd, F_GETFL);
  if (flags < 0) {
    char *err_was = strerror(errno);
    zc_log(zc_log_level_error, "Error occured: %s", err_was);
    return -1;
  }
  flags |= O_NONBLOCK;
  int e = fcntl(fd, F_SETFL, flags);
  if (-1 == e) {
    char *err_was = strerror(errno);
    zc_log(zc_log_level_error, "Error occured: %s", err_was);
  }
  return e;
#endif
  return 0;
}
ZCPRIVATE int zc_enable_tcp_no_delay(int fd)
{
#if 0
  int val;
  int e = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val));
  if (-1 == e) {
    char *err_was = strerror(errno);
    zc_log(zc_log_level_error, "Error occured: %s", err_was);
  }
  return e;
#endif
  return 0;
}
ZCPRIVATE int zc_enable_keep_alive(int fd)
{
#if 0
  int oui = 1;
  int e = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &oui, sizeof(oui));
  if (-1 == e) {
    char *err_was = strerror(errno);
    zc_log(zc_log_level_error, "Error occured: %s", err_was);
  }
  return e;
#endif
  return 0;
}
ZCPRIVATE int zc_enable_reuse_port_address(int fd)
{
#if 0
  int reuse = 1;
  int e =  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse));
  if (e < 0) {
    char *err_was = strerror(errno);
    zc_log(zc_log_level_error, "Error occured: %s", err_was);
  }
#endif
  return 0;
}
