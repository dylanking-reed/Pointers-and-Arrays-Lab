#ifndef REMOVING_ODDS_H
#define REMOVING_ODDS_H
#include <stdio.h>
#include <stdint.h>

/// Prints an array of `int32_t`s with a newline.
void int32_array_println(int32_t* a, size_t a_len);

/// Prints an array of `int32_t`s.
void int32_array_print(int32_t* a, size_t a_len);

/// Pushes all evens from `a` to `out`. Returns the len of `òut`.
/// Unsafe: `out` must have capacity >= `a_len`.
size_t evens(int32_t* a, size_t a_len, int32_t* out);

#endif
