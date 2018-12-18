#ifndef __zc_alloc_h__
#define __zc_alloc_h__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include "zc_utils.h"

    ZCEXPORT void *zc_malloc(size_t size);

#ifdef __cplusplus
}
#endif

#endif //__zc_alloc_h__
