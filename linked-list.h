#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdint.h>

typedef struct Node_s {
  uint32_t val;
  struct Node_s* next; /* may be null */
} Node;

typedef struct List_s {
  Node* first; 
  Node* last; 
  size_t len;
} List;

int list_push_back(List* l, uint32_t val);

List* list_new_with(uint32_t val, uint32_t amt);

#endif
