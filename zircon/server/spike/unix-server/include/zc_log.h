#ifndef __zc_log_h__
#define __zc_log_h__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdarg.h>
#include "zc_utils.h"

// ---------------------------------------------------------------------- Log
#define zc_log_level_raw (1 << 10)
    typedef enum tag_log_level
    {
        zc_log_level_verbose,
        zc_log_level_debug,
        zc_log_level_warning,
        zc_log_level_error,
        zc_log_level_fatal,
        zc_log_level_max
    } zc_log_level_e;

    ZCEXPORT void zc_log_init();
    ZCEXPORT void zc_set_log_level(int level);

    ZCEXPORT void zc_log(int level, const char *fmt, ...);

    #define LOGV(expr, ...) zc_log(zc_log_level_verbose, (expr), __VA_ARGS__);
    #define LOGD(expr, ...) zc_log(zc_log_level_debug, (expr), __VA_ARGS__);
    #define LOGW(expr, ...) zc_log(zc_log_level_warning, (expr), __VA_ARGS__);
    #define LOGE(expr, ...) zc_log(zc_log_level_error, (expr), __VA_ARGS__);
    #define LOGF(expr, ...) zc_log(zc_log_level_fatal, (expr), __VA_ARGS__);
  
  

#ifdef __cplusplus
}
#endif

#endif //__zc_log_h__
