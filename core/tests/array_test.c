#include <assert.h>
#include <core/array.h>

ARRAY(double, 900)
ARRAY(char, 16)
ARRAY(char, 17)

int main(void) {
  Array_double_900 array = Array_double_900_New();
  assert(Array_double_900_At(&array, 4) == 0);
  *Array_double_900_AtMut(&array, 501) = 69420;
  assert(Array_double_900_At(&array, 501) == 69420);
}
