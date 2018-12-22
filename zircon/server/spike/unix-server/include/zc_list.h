#ifndef __zc_list_h__
#define __zc_list_h__

#include "zc_utils.h"

#if defined __cplusplus
extern "C" {
#endif
  
  typedef struct zc_list zc_list_t;
  typedef struct zc_node zc_node_t;
  
  ZC_PUBLIC zc_node_t *NODE_alloc(void *data, void(*data_deleter)(void*));
  ZC_PUBLIC void NODE_dealloc(zc_node_t *thiz);
  
  ZC_PUBLIC zc_list_t *LIST_alloc(void(*node_data_deleter)(void*));
  ZC_PUBLIC void LIST_dealloc(zc_list_t *thiz);
  ZC_PUBLIC zc_list_t *LIST_push_back(zc_list_t *thiz, void *data);
  ZC_PUBLIC zc_node_t *LIST_tail(zc_list_t *thiz);
  ZC_PUBLIC unsigned long LIST_len(zc_list_t *thiz);
  
#if defined __cplusplus
}
#endif


#endif
