#include "finding-a-character.h"
#include <assert.h>
#include <stddef.h>
#include <stdbool.h>

char* find_character(char* str, char c) {
  for (int i = 0;true; i++){
    if (str[i] == c || str[i] == '\0') return &(str[i]);
  }
  assert(false && "Unreachable :(");
  return NULL;
}
