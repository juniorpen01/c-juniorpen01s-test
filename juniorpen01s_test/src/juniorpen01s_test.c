#include <assert.h>
#include <stdbool.h>

#include <juniorpen01s_test.h>

__attribute__((constructor)) int main(void) { assert(false); }
