#include "zc_log.h"
#include "zc_server.h"
#include "zc_utils.h"

// ---------------------------------------------------------------------- Main
extern int main(int argC, char *argV[]) {
  /*
   Quick log tests
   */
  zc_log_init();
  zc_set_log_level(zc_log_level_verbose); // print only logs above warning

  zc_log(zc_log_level_verbose, "zc_log_level_verbose %s", "");
  zc_log(zc_log_level_debug, "zc_log_level_debug %s", "");
  zc_log(zc_log_level_warning, "zc_log_level_warning %s", "");
  LOGE("zc_log_level_error %s", "");
  zc_log(zc_log_level_fatal, "zc_log_level_fatal %s", "");
  zc_log(zc_log_level_max, "zc_log_level_max %s", "");

  int three = 3;
  LOGV("alex mudof music zc_log_level_debug %s for %d years", ", BOOM, ",
       three);

  /*
   Server code start
   */
  LOGV("starting...", "");
  zc_server_t *ss = zc_server_new(ZC_DEFAULT_SOCKET_PATH);
  zc_server_start(ss);
  LOGV("started! OK", "");
  return 0;
}
