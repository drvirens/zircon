#ifndef __zc_client_h__
#define __zc_client_h__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <ev.h>
#include "zc_utils.h"

typedef struct zc_client zc_client_t;

ZC_PUBLIC zc_client_t* CLIENT_alloc(int fd, struct ev_loop *loop);
ZC_PUBLIC void CLIENT_dealloc(zc_client_t* thiz);

#ifdef __cplusplus
}
#endif

#endif //__zc_client_h__
