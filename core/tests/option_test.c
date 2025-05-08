#include <assert.h>
#include <stdbool.h>

#include <core/option.h>

OPTION(int)
OPTION(double)

#define Some_New(value)                                                        \
  _Generic(value, int: Some_int_New, double: Some_double_New)(value)

#define Option_Variant(this)                                                   \
  _Generic(this,                                                               \
      Option_int *: Option_int_Variant,                                        \
      Option_double *: Option_double_Variant)(this)

#define Option_Value(this)                                                     \
  _Generic(this,                                                               \
      Option_int *: Option_int_Value,                                          \
      Option_double *: Option_double_Value)(this)

int main(void) {
  Option_int option = Some_New(256);
  assert(Option_Value(&option) == 256);
  assert(Option_Variant(&option));
  option = None_int_New();
  assert(Option_Value(&option) == None);
  assert(!Option_Variant(&option));
}
