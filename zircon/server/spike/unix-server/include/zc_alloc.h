#ifndef __zc_alloc_h__
#define __zc_alloc_h__

#ifdef __cplusplus
extern "C" {
#endif
  
#include <stdlib.h>
#include "zc_utils.h"

ZC_PUBLIC void* ZIRCON_malloc(size_t size);
ZC_PUBLIC void ZIRCON_free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif //__zc_alloc_h__
