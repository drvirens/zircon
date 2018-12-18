#ifndef __zc_client_h__
#define __zc_client_h__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include "zc_utils.h"

    typedef struct tag_zc_client zc_client_t;

    ZCEXPORT zc_client_t *zc_client_new();

#ifdef __cplusplus
}
#endif

#endif //__zc_client_h__
