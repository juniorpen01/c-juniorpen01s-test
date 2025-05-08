#ifndef CORE_OPTION_H
#define CORE_OPTION_H

typedef enum { None, Some } Variant;

#define OPTION(T)                                                              \
                                                                               \
  typedef struct Option_##T {                                                  \
    T value;                                                                   \
    Variant variant;                                                           \
  } Option_##T;                                                                \
                                                                               \
  Option_##T Some_##T##_New(const T value) {                                   \
    return (Option_##T){value, Some};                                          \
  }                                                                            \
  Option_##T None_##T##_New() { return (Option_##T){.variant = None}; }        \
                                                                               \
  Variant Option_##T##_Variant(const Option_##T *const this) {                 \
    return this->variant;                                                      \
  }                                                                            \
                                                                               \
  T Option_##T##_Value(const Option_##T *const this) { return this->value; }

/*void Option_##T##_SetVariant(const Option_##T *const this,                   \
                             const Option_##T value) {                       \
                              \
}                                                                            \*/

#endif
