#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <stddef.h>
#include <stdlib.h>

#define ARRAY(T, N)                                                            \
  typedef struct {                                                             \
    double data[N];                                                            \
  } Array_##T##_##N;                                                           \
                                                                               \
  Array_##T##_##N Array_##T##_##N##_New() { return (Array_##T##_##N){0}; }     \
                                                                               \
  double Array_##T##_##N##_At(const Array_##T##_##N *const this,               \
                              const size_t index) {                            \
    if (!(index < N))                                                          \
      exit(EXIT_FAILURE);                                                      \
    return this->data[index];                                                  \
  }                                                                            \
                                                                               \
  double *Array_##T##_##N##_AtMut(Array_##T##_##N *const this,                 \
                                  const size_t index) {                        \
    if (!(index < N))                                                          \
      exit(EXIT_FAILURE);                                                      \
    return &this->data[index];                                                 \
  }                                                                            \
                                                                               \
  const size_t Array_##T##_##N##_Size = N;

#endif
