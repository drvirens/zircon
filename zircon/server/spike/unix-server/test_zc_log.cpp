#include "zc_log.h"
#include <catch2/catch.hpp>

TEST_CASE("log verbose msg", "[zc_log]")
{
  zc_log_init();
  zc_set_log_level(zc_log_level_warning); // print only logs above warning

  LOGE("Error should get printed %s", ": YES");
  zc_log(zc_log_level_warning, "Warning should get printed %s", ": YES");
  zc_log(zc_log_level_verbose, "Verbose should NOT get printed %s", ": NOPE");
}
