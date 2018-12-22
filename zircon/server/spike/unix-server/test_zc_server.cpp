#include <catch2/catch.hpp>
#include "zc_server.h"

TEST_CASE("server test", "[zc_server]")
{
  zc_server_t* server = SERVER_alloc("/tmp/deleteanytime");
  REQUIRE(server != 0);
}
