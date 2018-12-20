#ifndef __zc_alloc_h__
#define __zc_alloc_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "zc_utils.h"
#include <stdlib.h>

ZCEXPORT void *zc_malloc(size_t size);
ZCEXPORT void zc_free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif //__zc_alloc_h__
