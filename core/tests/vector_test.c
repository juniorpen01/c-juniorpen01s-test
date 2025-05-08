#include <assert.h>
#include <stdbool.h>

#include <core/vector.h>

VECTOR(int)
VECTOR(char)
VECTOR(double)

#define Vector_Push(this, element)                                             \
  _Generic((this),                                                             \
      Vector_int *: Vector_int_Push,                                           \
      Vector_char *: Vector_char_Push,                                         \
      Vector_double *: Vector_double_Push)(this, element)

#define Vector_At(this, index)                                                 \
  _Generic((this),                                                             \
      Vector_int *: Vector_int_At,                                             \
      Vector_char *: Vector_char_At,                                           \
      Vector_double *: Vector_double_At)(this, index)

#define Vector_Delete(this)                                                    \
  _Generic((this),                                                             \
      Vector_int *: Vector_int_Delete,                                         \
      Vector_char *: Vector_char_Delete,                                       \
      Vector_double *: Vector_double_Delete)(this)

#define Vector_Delete(this)                                                    \
  _Generic((this),                                                             \
      Vector_int *: Vector_int_Delete,                                         \
      Vector_char *: Vector_char_Delete,                                       \
      Vector_double *: Vector_double_Delete)(this)

int main(void) {
  // void compare(int i)
  Vector_int vector = Vector_int_New();
  Vector_Push(&vector, 1);
  Vector_Push(&vector, 2);
  Vector_Push(&vector, 3);
  for (size_t i = 0; i < 3; ++i) {
    assert(Vector_At(&vector, i) == (int)i + 1);
  }

  Vector_int vector2 = Vector_int_WithCapacity(3);
  Vector_Push(&vector2, 1);
  Vector_Push(&vector2, 2);
  Vector_Push(&vector2, 3);
  for (size_t i = 0; i < 3; ++i) {
    assert(Vector_At(&vector2, i) == (int)i + 1);
  }

  Vector_Delete(&vector);
  Vector_Delete(&vector2);

  Vector_char vector3 = Vector_char_WithCapacity(3);
  Vector_Push(&vector3, 1);
  Vector_Push(&vector3, 2);
  Vector_Push(&vector3, 3);
  for (size_t i = 0; i < 3; ++i) {
    assert(Vector_At(&vector3, i) == (int)i + 1);
  }
  Vector_Delete(&vector3);
  Vector_Delete(&vector3);

  Vector_double vector4 = Vector_double_WithCapacity(4);
  Vector_Push(&vector4, 1);
  Vector_Push(&vector4, 2);
  Vector_Push(&vector4, 3);
  Vector_Push(&vector4, 4);
  Vector_Push(&vector4, 5);
  for (size_t i = 0; i < vector4.size; ++i) {
    assert(Vector_At(&vector4, i) == (int)i + 1);
  }
  Vector_Delete(&vector4);
  Vector_Delete(&vector4);

  Vector_double vector5 = Vector_double_New();
  Vector_Push(&vector5, 1);
  assert(Vector_At(&vector5, 0) == 1);
  Vector_Push(&vector5, 2);
  Vector_Push(&vector5, 3);
  Vector_Push(&vector5, 4);
  Vector_Push(&vector5, 5);
  for (size_t i = 0; i < vector5.size; ++i) {
    assert(Vector_At(&vector5, i) == (int)i + 1);
  }
  Vector_Delete(&vector5);
  Vector_Delete(&vector5);
}
