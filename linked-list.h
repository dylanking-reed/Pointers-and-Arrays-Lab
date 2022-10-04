#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_s {
  uint32_t val;
  struct Node_s* next; /* may be null */
} Node;

typedef struct List_s {
  Node* first; 
  Node* last; 
  size_t len;
} List;

List* list_new_empty();
List* list_new_with(uint32_t val, uint32_t amt);

bool list_empty(List* l);

Node* list_push_back(List* l, uint32_t val);
uint64_t list_delete_byvalue(List* l, uint32_t val);

void list_delete_first(List* l);
void list_delete_node(List* l, Node* before, Node* n);

void list_print(List* l);
void list_println(List* l);

#endif
