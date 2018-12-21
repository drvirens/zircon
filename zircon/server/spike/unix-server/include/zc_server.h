#ifndef __zc_server_h__
#define __zc_server_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "zc_utils.h"
// ---------------------------------------------------------------------- Public
// Declarations

typedef enum tag_error_type {
  zc_ok,
  zc_socket_error
} zc_error_type_e;

typedef struct tag_server zc_server_t;

ZC_PUBLIC zc_server_t* zc_server_new(const char* path);
ZC_PUBLIC int zc_server_start(zc_server_t* server);

#ifdef __cplusplus
}
#endif

#endif //__zc_server_h__
