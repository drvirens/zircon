#include "zc_alloc.h"

void* ZIRCON_malloc(size_t size) { return malloc(size); }

ZC_PUBLIC void ZIRCON_free(void* ptr) { free(ptr); }
