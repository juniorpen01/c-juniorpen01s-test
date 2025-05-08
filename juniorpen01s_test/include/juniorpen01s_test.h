#ifndef TEST_C
#define TEST_C

#include <core/malloc.h>
#include <core/vector.h>

typedef void (*Test)(void);

VECTOR(Test)

#define Vector_New Vector_Test_New

Vector_Test *Tests_Get(void) {
  static Vector_Test *instance = NULL;
  if (!instance) {
    instance = core_malloc(sizeof(Vector_Test));
    *instance = Vector_New();
  }
  return instance;
}

#endif
