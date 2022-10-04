#include "linked-list.h"
#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("%d", a);
  return a;
}

void linked_list_test() {
  printf("Running test: linked_list_test ... \n");
  /* assertions */
  List* l = list_new_empty();   
  list_println(l);
  Node* a = list_push_back(l, 4);
  assert(list_push_back(l, 68) != NULL);
  assert(list_push_back(l, 4) != NULL);
  assert(list_push_back(l, 4) != NULL);
  assert(list_push_back(l, 70) != NULL);
  assert(list_push_back(l, 4) != NULL);
  list_println(l);
  // list_delete_node(l, NULL, a);
  list_delete_byvalue(l, 4);
  list_println(l);
  list_free(l);
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  linked_list_test();
  printf("Tests passed.\n");
  return 0;
}
