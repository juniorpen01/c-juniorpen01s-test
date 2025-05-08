#ifndef CORE_OPTION_H
#define CORE_OPTION_H

typedef enum { None, Some } Variant;

#define OPTION(T)

typedef struct Option_int {
  const int value;
  const Variant variant;
} Option_int;

Option_int Some_int_New(const int value) { return (Option_int){value, Some}; }
Option_int None_int_New() { return (Option_int){.variant = None}; }

Variant Option_int_Variant(const Option_int *const this) {
  return this->variant;
}

Variant Option_int_Value(const Option_int *const this) { return this->value; }

#endif
