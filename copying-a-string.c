#include "copying-a-string.h"
#include <stdbool.h>
#include <stdlib.h>

char* string_copy(char* str, size_t str_len) {
  char* new = malloc(sizeof(char) * str_len);
  for (size_t i = 0; i < str_len; i++) {
    new[i] = str[i];
  } 
  return new;
}
