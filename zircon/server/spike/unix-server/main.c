//#include <signal.h>
#include "zc_log.h"
#include "zc_server.h"
#include "zc_utils.h"


// ---------------------------------------------------------------------- Main
extern int main(int argC, char* argV[])
{
  /*
   Server code start
   */
  LOGV("starting...", "");
  
//  signal(SIGHUP, SIG_IGN);
//  signal(SIGPIPE, SIG_IGN);
  
  #define ZC_DEFAULT_SOCKET_PATH "/tmp/virendshakya"
  zc_server_t* ss = zc_server_new(ZC_DEFAULT_SOCKET_PATH);
  zc_server_start(ss);
  LOGV("started! OK", "");
  return 0;
}
