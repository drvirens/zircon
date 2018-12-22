#include "zc_list.h"
#include "zc_log.h"
#include "zc_utils.h"


typedef struct tag_node {
  struct tag_node *next_;
  struct tag_node *prev_;
  void *data_;
} zc_node;

struct zc_list {
  zc_node *head_;
  zc_node *tail_;
  unsigned long len_;
  void (*list_clone)(void */*ptr*/);
  void (*list_delete)(void */*ptr*/);
  void (*list_lookup)(void */*ptr*/, void */*key*/);
};
