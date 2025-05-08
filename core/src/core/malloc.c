#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <core/malloc.h>

void *core_malloc(const size_t size) {
  void *const ptr = malloc(size);
  if (!ptr) {
    fprintf(stderr, "Unable to allocate memory: %s (Requested %zu bytes)\n",
            strerror(errno), size);
    free(ptr);
    exit(EXIT_FAILURE);
  }
  return ptr;
}
