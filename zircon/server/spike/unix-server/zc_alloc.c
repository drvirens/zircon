#include "zc_alloc.h"

void* zc_malloc(size_t size) { return malloc(size); }

ZC_PUBLIC void zc_free(void* ptr) { free(ptr); }
