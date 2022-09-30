#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("%d", a);
  return a;
}

void template_test() {
  printf("Running test: template_test ... ");
  /* assertions */
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  template_test();
  printf("Tests passed.\n");
  return 0;
}
