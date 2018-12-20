#ifndef __zc_assert_h__
#define __zc_assert_h__ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// privates
static int g_bail = 0;
static int g_failure = 0;

#define ZC_BAIL_ON_ASSERT() g_bail = (!(g_bail));
#define ZC_TOTAL_ASSERT_FAILURES() g_failure

#ifndef assert
#define assert zc_assert_ok
#endif

#define zc_assert_not_null(condition)                                   \
  do {                                                                  \
    if ((condition) == NULL) {                                          \
      fprintf(stderr, "Zircon Assertion Ocuured: %s is NULL (%s:%d)\n", \
          #condition, __FILE__, __LINE__);                              \
      if (g_bail)                                                       \
        abort();                                                        \
    }                                                                   \
  } while (0);

#define zc_assert_null(condition)                                       \
  do {                                                                  \
    if ((condition) != NULL) {                                          \
      fprintf(stderr, "Zircon Assertion Ocuured: %s is NULL (%s:%d)\n", \
          #condition, __FILE__, __LINE__);                              \
      if (g_bail)                                                       \
        abort();                                                        \
    }                                                                   \
  } while (0);

#ifdef __cplusplus
}
#endif

#endif //__zc_assert_h__