#pragma once

#include <stddef.h>
#include <stdlib.h>

typedef struct {
  const double *const data;
  const size_t size, capacity;
} Vector_double;

Vector_double Vector_double_New(void);

Vector_double Vector_double_New(void) {
  const double *const data = malloc(sizeof(double));
  if (!data)
    exit(EXIT_FAILURE);
  return (Vector_double){data, 0, 1};
}
