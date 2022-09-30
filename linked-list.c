#include "linked-list.h"
#include <assert.h>

Node* node_new(uint32_t val, Node* next) {
  Node* new = (Node*)malloc(sizeof(Node)); 
  if (new == NULL) return NULL;
  new->val = val;
  new->next = next;
}

bool list_empty(List* l) {
  assert(l != NULL);
  if (l->first == NULL) {
    assert(l->last == NULL);
    assert(l->size == 0);
    return true;
  } else {
    assert(l->last != NULL);
    assert(l->size != 0);
    return false;
  }
}

void list_add_to_empty(List* l, Node* node) {
  assert(list_empty(l));
  assert(node != NULL);
  l->first = node;
  l->last = node;
  l->size += 1;
}

List* list_new_empty() {
  List* new = (List*)malloc(sizeof(List));
  new->first = NULL;
  new->last = NULL;
  new->size = 0;
}

int list_push_back(List* l, uint32_t val) {
  Node* new = new_node(val, NULL); 
  if (new == NULL) return 1;
  if (list_empty(l)) {
    list_add_to_empty(l, new);
  } else {
    l->last->next = new;
    l->last = new; 
    l->size += 1;
  }
  return 0;
}

List* list_new_with(uint32_t val, uint32_t amt) {
  List* l = list_new_empty();
  for (uint32_t i = 0; i < amt; i++) {
    list_push_back(l, val); 
  }
  return l;
}

uint64_t list_remove_values(List* l, uint32_t val) {
   
}


