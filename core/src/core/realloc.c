#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <core/realloc.h>

void *core_realloc(void *const ptr, const size_t size) {
  void *const tmp = realloc(ptr, size);
  if (!tmp) {
    fprintf(stderr, "Unable to reallocate memory: %s (Requested %zu bytes)\n",
            strerror(errno), size);
    free(ptr);
    exit(EXIT_FAILURE);
  }
  return tmp;
}
