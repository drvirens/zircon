#include "zc_list.h"
#include "zc_log.h"
#include "zc_utils.h"
#include "zc_alloc.h"

struct zc_node {
  struct zc_node *next_;
  struct zc_node *prev_;
  void *data_;
  void (*data_deleter_)(void */*ptr*/);
};

struct zc_list {
  zc_node_t *head_;
  zc_node_t *tail_;
  unsigned long len_;
  void (*list_clone)(void */*ptr*/);
  void (*list_delete)(void */*ptr*/);
  void (*list_lookup)(void */*ptr*/, void */*key*/);
  void (*node_data_deleter_)(void*);
};

// ------------------------------------------ node
ZC_PUBLIC zc_node_t *NODE_alloc(void *data, void(*data_deleter)(void*))
{TRACE
  zc_node_t *n;
  n = (zc_node_t *)ZIRCON_malloc(sizeof(*n));
  if (n) {
    n->next_ = NULL;
    n->prev_ = NULL;
    n->data_ = data;
    n->data_deleter_ = data_deleter;
  }
  return n;
}
ZC_PUBLIC void NODE_dealloc(zc_node_t *thiz)
{TRACE
  if (!thiz) {
    return;
  }
  if (thiz->data_deleter_) {
    (*(thiz->data_deleter_))(thiz);
  }
  thiz->data_deleter_ = NULL;
  thiz->next_ = NULL;
  thiz->prev_ = NULL;
  thiz->data_ = NULL;
  ZIRCON_free(thiz);
}

// ------------------------------------------ list
ZC_PUBLIC zc_list_t *LIST_alloc(void(*node_data_deleter)(void*))
{TRACE
  zc_list_t *ll;
  ll = (zc_list_t *)ZIRCON_malloc(sizeof(*ll));
  if (ll) {
    ll->head_ = NULL;
    ll->tail_ = NULL;
    ll->len_ = 0;
    ll->list_clone = NULL;
    ll->list_delete = NULL;
    ll->list_lookup = NULL;
  }
  return ll;
}
ZC_PUBLIC void LIST_dealloc(zc_list_t *thiz)
{TRACE
  if (thiz) {
    thiz->head_ = NULL;
    thiz->tail_ = NULL;
    thiz->len_ = 0;
    thiz->list_clone = NULL;
    thiz->list_delete = NULL;
    thiz->list_lookup = NULL;
    ZIRCON_free(thiz);
  }
}
ZC_PUBLIC zc_list_t *LIST_push_back(zc_list_t *thiz, void *data)
{TRACE
  void(*data_deleter)(void*) = thiz->node_data_deleter_;
  zc_node_t *n = NODE_alloc(data, data_deleter);
  if (!n) {
    return NULL;
  }
  if (thiz->len_ == 0) {
    thiz->head_ = thiz->tail_ = n;
  } else {
    n->prev_ = thiz->tail_;
    thiz->tail_->next_ = n;
    thiz->tail_ = n;
  }
  (thiz->len_)++;
  return thiz;
}
ZC_PUBLIC zc_node_t *LIST_tail(zc_list_t *thiz)
{TRACE
  return thiz->tail_;
}
ZC_PUBLIC unsigned long LIST_len(zc_list_t *thiz)
{TRACE
  return thiz->len_;
}
