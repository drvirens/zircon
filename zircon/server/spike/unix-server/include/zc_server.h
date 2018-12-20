#ifndef __zc_server_h__
#define __zc_server_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "zc_utils.h"
// ---------------------------------------------------------------------- Public
// Declarations

#define ZC_DEFAULT_SOCKET_PATH "/tmp/virendra"

typedef enum tag_error_type { zc_ok, zc_socket_error } zc_error_type_e;

typedef struct tag_server zc_server_t;

ZCEXPORT zc_server_t *zc_server_new(const char *path);
ZCEXPORT int zc_server_start(zc_server_t *server);

#ifdef __cplusplus
}
#endif

#endif //__zc_server_h__
