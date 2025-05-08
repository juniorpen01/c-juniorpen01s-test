#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>

#include <core/malloc.h>
#include <core/realloc.h>

#define VECTOR(T)                                                              \
  typedef struct Vector_##T {                                                  \
    T *data;                                                                   \
    size_t size;                                                               \
    size_t capacity;                                                           \
  } Vector_##T;                                                                \
                                                                               \
  Vector_##T Vector_##T##_New(void) {                                          \
    T *const data = core_malloc(sizeof(T));                                    \
    return (Vector_##T){data, 0, 1};                                           \
  }                                                                            \
                                                                               \
  Vector_##T Vector_##T##_WithCapacity(const size_t capacity) {                \
                                                                               \
    T *const data = core_malloc(capacity * sizeof(T));                         \
    return (Vector_##T){data, 0, capacity};                                    \
  }                                                                            \
                                                                               \
  void Vector_##T##_Delete(Vector_##T *this) {                                 \
    free(this->data);                                                          \
    this->data = NULL;                                                         \
    this->size = this->capacity = 0;                                           \
  }                                                                            \
                                                                               \
  void Vector_##T##_Push(Vector_##T *this, const T element) {                  \
    if (!(this->size < this->capacity)) {                                      \
      this->capacity *= 2;                                                     \
      this->data = core_realloc(this->data, sizeof(T) * this->capacity);       \
    }                                                                          \
    this->data[this->size++] = element;                                        \
  }                                                                            \
                                                                               \
  T Vector_##T##_At(const Vector_##T *this, const size_t index) {              \
    if (index > this->size - 1)                                                \
      exit(EXIT_FAILURE);                                                      \
    return this->data[index];                                                  \
  }                                                                            \
                                                                               \
  /*void Vector_##T##_ForEach(const Vector_##T *this, void (*callback)(T)) {   \
    for (size_t i = 0; i < this->size; ++i) {                                  \
      callback(this->data[i]);                                                 \
    }                                                                          \
  }*/

#endif
