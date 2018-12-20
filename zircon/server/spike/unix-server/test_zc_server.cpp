#include "zc_server.h"
#include <catch2/catch.hpp>

TEST_CASE("server test", "[zc_server]") {
  zc_server_t *server = zc_server_new(ZC_DEFAULT_SOCKET_PATH);
  REQUIRE(server != 0);
}