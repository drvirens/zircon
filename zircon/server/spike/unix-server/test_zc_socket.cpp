//
//  test_zc_socket.cpp
//  client
//
//  Created by Virendra Shakya on 12/19/18.
//

#include <catch2/catch.hpp>
#include "zc_socket.h"

TEST_CASE("create socket", "[zc_socket]")
{
  zc_socket *s = new_instance();
  REQUIRE(s != 0);
  zc_socket_error_e e;
  e = socket_create_unix_socket(s);
  REQUIRE(e == zc_socket_err_ok);
}

TEST_CASE("configure socket", "[zc_socket]")
{
  zc_socket *s = new_instance();
  REQUIRE(s != 0);
  zc_socket_error_e e;
  e = socket_create_unix_socket(s);
  REQUIRE(e == zc_socket_err_ok);
  e = socket_config_enable_nonblocking(s);
  REQUIRE(e == zc_socket_err_ok);
  e = socket_config_enable_tcpnodelay(s);
  REQUIRE(e == zc_socket_err_ok);
  e = socket_config_enable_keepalive(s);
  REQUIRE(e == zc_socket_err_ok);
}

TEST_CASE("bind and listen socket", "[zc_socket]")
{
  zc_socket *s = new_instance();
  REQUIRE(s != 0);
  zc_socket_error_e e;
  e = socket_create_unix_socket(s);
  REQUIRE(e == zc_socket_err_ok);
}
TEST_CASE("accept socket", "[zc_socket]")
{
  zc_socket *s = new_instance();
  REQUIRE(s != 0);
  zc_socket_error_e e;
  e = socket_create_unix_socket(s);
  REQUIRE(e == zc_socket_err_ok);
}
TEST_CASE("connect socket", "[zc_socket]")
{
  zc_socket *s = new_instance();
  REQUIRE(s != 0);
  zc_socket_error_e e;
  e = socket_create_unix_socket(s);
  REQUIRE(e == zc_socket_err_ok);
}