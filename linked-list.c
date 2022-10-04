#include "linked-list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Node* node_new(uint32_t val, Node* next) {
  Node* new = (Node*)malloc(sizeof(Node)); 
  if (new == NULL) return NULL;
  new->val = val;
  new->next = next;
  return new;
}

bool list_empty(List* l) {
  assert(l != NULL);
  if (l->first == NULL) {
    assert(l->last == NULL);
    assert(l->len == 0);
    return true;
  } else {
    assert(l->last != NULL);
    assert(l->len != 0);
    return false;
  }
}

void list_add_to_empty(List* l, Node* node) {
  assert(list_empty(l));
  assert(node != NULL);
  l->first = node;
  l->last = node;
  l->len += 1;
}

List* list_new_empty() {
  List* new = (List*)malloc(sizeof(List));
  if (new == NULL) return NULL;
  new->first = NULL;
  new->last = NULL;
  new->len = 0;
  return new;
}

Node* list_push_back(List* l, uint32_t val) {
  Node* new = node_new(val, NULL); 
  if (new == NULL) return NULL;
  if (list_empty(l)) {
    list_add_to_empty(l, new);
  } else {
    l->last->next = new;
    l->last = new; 
    l->len += 1;
  }
  return new;
}

List* list_new_with(uint32_t val, uint32_t amt) {
  List* l = list_new_empty();
  for (uint32_t i = 0; i < amt; i++) {
    list_push_back(l, val); 
  }
  return l;
}

void list_delete_first(List* l) {
  if (l->first == l->last) {
    assert(l->len == 1);
    assert(l->first->next == NULL);
    l->last = NULL;
  }  
  Node* new_first = l->first->next;
  assert(l->first != NULL);
  free(l->first);
  l->first = new_first; 
  l->len -= 1; 
}


void list_delete_node(List* l, Node* before, Node* n) {
  //printf("list_delete_node(l = %p, before = %p, n = %p)\n", (void*)l, (void*)before, (void*)n);
  assert(l != NULL && n != NULL && before != n);
  if (l->first == n) {
    assert(before == NULL);
    list_delete_first(l);
    l->len -= 1;
    return;
  } else if (l->last == n) {
    assert(n->next == NULL);
    l->last = before;
    assert(before != NULL);
    before->next = NULL;
  } else {
    assert(before != NULL);
    before->next = n->next;
  } 
  free(n);
  l->len -= 1;
}

/*
uint64_t list_remove_values(List* l, uint32_t val) {
  Node* prev = NULL;
  uint64_t count = 0;
  for (Node* curr = l->first; curr != NULL; curr = curr->next) {
    // printf("curr = %p\n", (void*)curr);
    if (curr == l->last) printf("alarm!!\n");
    if (l->first == curr && curr->val == val) {
      list_delete_first(l);
      count++;
    } else if (curr->val == val) { 
      list_delete_node(l, prev, curr);	    
      count++;
    } 
    
    prev = curr;
  }
  return count;
}
*/

uint64_t list_delete_byvalue(List* l, uint32_t v) {
  Node* prev = NULL;
  uint64_t count = 0;
  for (Node* curr = l->first; curr != NULL; curr = curr->next) {
    if (curr->val == v) {
      if (l->first == curr) {
        list_delete_node(l, prev, curr); 
	curr = l->first;
      } else {
	assert(prev != NULL);
        list_delete_node(l, prev, curr); 
	curr = prev;
      }
      count++;
    } 
    prev = curr;
  }
  return count;
}


void list_free(List* l) {
  Node* next = NULL;
  for (Node* curr = l->first; curr != NULL; curr = next) {
    assert(curr != NULL);
    next = curr->next;
    free(curr);
  }
  free(l);
} 

void list_print(List* l) {
  printf("{ \n");
  for (Node* curr = l->first; curr != NULL; curr = curr->next) {
    assert(curr != NULL);
    printf("Node <%p> {%d, %p}, \n", (void*)curr, curr->val, (void*)curr->next);
  }
  printf(" }");
} 

void list_println(List* l) { list_print(l); printf("\n"); }

