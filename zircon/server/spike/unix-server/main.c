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
  LOG_v("starting...", "");
  
//  signal(SIGHUP, SIG_IGN);
//  signal(SIGPIPE, SIG_IGN);
  
  #define ZC_DEFAULT_SOCKET_PATH "/tmp/virendshakya"
  zc_server_t* ss = SERVER_alloc(ZC_DEFAULT_SOCKET_PATH);
  SERVER_start(ss);
  SERVER_dealloc(ss);
  LOG_v("started! OK", "");
  return 0;
}
