#include <catch2/catch.hpp>
#include "zc_server.h"

TEST_CASE("server test", "[zc_server]")
{
    zc_server_t *server = zc_server_new(ZC_DEFAULT_SOCKET_PATH);
    REQUIRE(server != 0);
}