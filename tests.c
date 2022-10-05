#include "linked-list.h"
#include "removing-odds.h"
#include "finding-a-character.h"
#include "copying-a-string.h"
#include <stdio.h>
#include <stdint.h>
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
  list_delete_byvalue(l, 4);
  list_println(l);
  list_free(l);
  printf("PASSED\n");
}

void removing_odds_test() {
  printf("Running test: removing_odds_test ... \n");
  int32_t vals[5] = { 1, 2, 3, 4, 5, }; 
  int32_array_println(vals, 5); 
  int32_t vals_even[5];
  size_t vals_even_len = evens(vals, 5, vals_even);
  int32_array_println(vals_even, vals_even_len); 
  printf("PASSED\n");
}

void finding_a_character_test() {
  printf("Running test: finding_a_character_test ... \n");
  char* hello = "Hello, world!"; 
  char* d = &(hello[11]);  
  assert(d == find_character(hello, 'd'));
  printf("PASSED\n");
}

void copying_a_string_test() {
  printf("Running test: copying_a_string_test ... \n");
  char* hello = "hello"; 
  char* copy = string_copy(hello, 6);
  printf("%s", copy);
  free(copy);
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  linked_list_test();
  removing_odds_test();
  finding_a_character_test();
  copying_a_string_test();
  printf("Tests passed.\n");
  return 0;
}
