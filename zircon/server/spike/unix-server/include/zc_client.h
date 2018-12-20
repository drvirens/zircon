#ifndef __zc_client_h__
#define __zc_client_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "zc_utils.h"
#include <stdlib.h>

typedef struct tag_zc_client zc_client_t;

ZC_PUBLIC zc_client_t* zc_client_new(int fd);

#ifdef __cplusplus
}
#endif

#endif //__zc_client_h__
