#include "zc_client.h"
#include "zc_alloc.h"
#include "zc_log.h"
#include <string.h>

// ----------------------------------------------------------------------
// Private Declarations
struct tag_zc_client {
  uint64_t id_;
  int fd_;
};

// ----------------------------------------------------------------------
// Private Functions Declarations
ZCPRIVATE void __common_init(zc_client_t *c, int fd);

// ---------------------------------------------------------------------- Public
// Impl
ZCEXPORT zc_client_t *zc_client_new(int fd) {
  zc_client_t *obj = (zc_client_t *)zc_malloc(sizeof(zc_client_t));
  if (obj) {
    memset(obj, 0, sizeof(zc_client_t));
    __common_init(obj, fd);
  }
  return obj;
}

// ----------------------------------------------------------------------
// Private Impl
ZCPRIVATE void __common_init(zc_client_t *c, int fd) {}
