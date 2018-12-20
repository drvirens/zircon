#include "zc_log.h"
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// ----------------------------------------------------------------------
// Private Configuration
#define ZC_MAX_LOG_MSG_LEN 1024

// ----------------------------------------------------------------------
// Private Struct Declarations
typedef struct tag_log {
  FILE *fp_;
  zc_log_level_e level_;
  char *logfile_;
} zc_log_t;

// ----------------------------------------------------------------------
// Private Functions Declarations
ZCPRIVATE void zc_log_msg(int level, const char *msg);

// ----------------------------------------------------------------------
// Private Data Members
ZCPRIVATE zc_log_t g_log = {0};

// ---------------------------------------------------------------------- Public
// Functions
ZCEXPORT void zc_log_init() { g_log.logfile_ = ""; }
ZCEXPORT void zc_log(int level, const char *fmt, ...) {

  va_list arg_list;
  char msg[ZC_MAX_LOG_MSG_LEN];

  if ((level & 0xff) < g_log.level_) {
    return;
  }

  va_start(arg_list, fmt);
  vsnprintf(msg, sizeof(msg), fmt, arg_list);
  va_end(arg_list);

  zc_log_msg(level, msg);
}

ZCEXPORT void zc_set_log_level(int level) { g_log.level_ = level; }

// ----------------------------------------------------------------------
// Private Functions
ZCPRIVATE void zc_log_msg(int level, const char *msg) {
  if (0 == g_log.logfile_) {
    g_log.logfile_ = "";
  }
  int log_to_stdout = g_log.logfile_[0] == '\0';
  FILE *fp;

  if (log_to_stdout) {
    fp = stdout;
  } else {
    fp = fopen(g_log.logfile_, "a");
  }
  if (!fp) {
    return;
  }

  level &= 0xff;

  if (level < g_log.level_) {
    printf("log filter break\n");
    return;
  }

  struct timeval tv;
  pid_t pid = getpid();

  gettimeofday(&tv, NULL);
  struct tm *tm;
  time_t rawtime;
  time(&rawtime);
  tm = localtime(&rawtime);
  char *gottime = asctime(tm);

  char processedtime[64] = {0};
  if (gottime) {
    char *start = gottime;
    char *curr = start;
    int i = 0;
    while (*curr != '\n') {
      processedtime[i++] = *curr++;
    }

    static const char *icon = "VDWEF";
    fprintf(fp, "%d:%c %s %c %s\n", (int)pid, 'S', processedtime, icon[level],
            msg);
  }

  if (!log_to_stdout && fp) {
    fclose(fp);
  }
}
