//
//  test_zc_socket.cpp
//  client
//
//  Created by Virendra Shakya on 12/19/18.
//
#include <catch2/catch.hpp>
#include <sys/socket.h>
#include <sys/un.h>

#include "zc_socket.h"

TEST_CASE("create socket", "[zc_socket_t]")
{
  zc_socket_t* s = SOCKET_alloc(zc_socket_type_unix);
  REQUIRE(s != 0);
  zc_socket_error_e e;
  int fd;
  e = SOCKET_socket_un(s, "/tmp/zircon.sock", &fd);
  REQUIRE(e == zc_socket_err_ok);

  SOCKET_dealloc(s);
}

TEST_CASE("configure socket", "[zc_socket_t]")
{
  zc_socket_t* s = SOCKET_alloc(zc_socket_type_unix);
  REQUIRE(s != 0);
  zc_socket_error_e e;
  int fd;
  e = SOCKET_socket_un(s, "/tmp/zircon.sock", &fd);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_set_nonblocking(s, fd);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_set_tcpnodelay(s, fd);
  REQUIRE(e == zc_socket_err_failed);
  e = SOCKET_set_keepalive(s, fd);
  REQUIRE(e == zc_socket_err_ok);

  SOCKET_dealloc(s);
}

TEST_CASE("bind and listen socket", "[zc_socket_t]")
{
  zc_socket_t* s = SOCKET_alloc(zc_socket_type_unix);
  REQUIRE(s != 0);
  zc_socket_error_e e;
  int fd;
  struct sockaddr_un sa;
  int backlog = 10;
  e = SOCKET_socket_un(s, "/tmp/zircon.sock", &fd);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_bind_n_listen(s, fd, &sa, backlog);
  REQUIRE(e == zc_socket_err_ok);

  SOCKET_dealloc(s);
}
TEST_CASE("accept socket", "[zc_socket_t]")
{
  zc_socket_t* s = SOCKET_alloc(zc_socket_type_unix);
  REQUIRE(s != 0);
  zc_socket_error_e e;
  int fd;
  struct sockaddr_un sa;
  int backlog = 10;
  e = SOCKET_socket_un(s, "/tmp/zircon.sock", &fd);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_bind_n_listen(s, fd, &sa, backlog);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_accept(s, fd);
  REQUIRE(e == zc_socket_err_ok);

  SOCKET_dealloc(s);
}
TEST_CASE("error msg", "[zc_socket_t]")
{
  zc_socket_t* s = SOCKET_alloc(zc_socket_type_unix);
  REQUIRE(s != 0);
  zc_socket_error_e e;
  int fd;
  struct sockaddr_un sa;
  int backlog = 10;
  e = SOCKET_socket_un(s, "/tmp/zircon.sock", &fd);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_bind_n_listen(s, fd, &sa, backlog);
  REQUIRE(e == zc_socket_err_ok);
  e = SOCKET_accept(s, fd);
  REQUIRE(e == zc_socket_err_ok);

  const char* errmsg = SOCKET_error_msg(s);
  REQUIRE(0 != errmsg);

  SOCKET_dealloc(s);
}
