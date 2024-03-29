#include <catch2/catch.hpp>
#include "zc_log.h"

TEST_CASE("log verbose msg", "[zc_log]")
{
  zc_log_init();
  zc_set_log_level(zc_log_level_warning); // print only logs above warning

  LOG_e("Error should get printed %s", ": YES");
  zc_log(zc_log_level_warning, "Warning should get printed %s", ": YES");
  zc_log(zc_log_level_verbose, "Verbose should NOT get printed %s", ": NOPE");
}
