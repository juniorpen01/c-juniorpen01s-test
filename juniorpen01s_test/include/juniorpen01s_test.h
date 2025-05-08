#ifndef TEST_C
#define TEST_C

#include <core/vector.h>

typedef void (*Test)(void);

VECTOR(Test)

typedef struct Tests {
  Vector_Test value;
} Tests;

Tests Tests_New(void) { return (Tests){Vector_Test_New()}; }

static Tests tests = Tests_New();

#endif
