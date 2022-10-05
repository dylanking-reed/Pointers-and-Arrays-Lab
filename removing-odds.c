#include "removing-odds.h"


/// Prints an array of `int32_t`s with a newline.
void int32_array_println(int32_t* a, size_t a_len) {
  int32_array_print(a, a_len); printf("\n"); 
}

/// Prints an array of `int32_t`s.
void int32_array_print(int32_t* a, size_t a_len) {
  printf("{ ");
  for (size_t i = 0; i < a_len; i++) printf("%d, ", a[i]);
  printf("}");
}

/// Pushes all evens from `a` to `out`. Returns the len of `òut`.
/// Unsafe: `out` must have capacity >= `a_len`.
size_t evens(int32_t* a, size_t a_len, int32_t* out) {
  size_t out_len = 0;
  for (size_t i = 0; i < a_len; i++) {
    if (a[i] % 2 == 0) {
      out[out_len] = a[i];
      out_len += 1;
    }
  }
  return out_len;
}


