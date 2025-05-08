#ifndef TEST_C
#define TEST_C

#include "core/malloc.h"
#include <core/vector.h>

#define Vector Vector_Test
#define Vector_New Vector_Test_New

typedef void (*Test)(void);

VECTOR(Test)

Vector *Tests_Get(void) {
  static Vector *instance = NULL;

  if (!instance) {
    instance = core_malloc(sizeof(Vector));
    *instance = Vector_New();
  }

  return instance;
}

#undef Vector_New
#undef Vector

#endif
