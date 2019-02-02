#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 123;
  int *pointer_to_i = &i;
  printf("Variable i has addr (%p) and value %d\n", &i, i);
  printf("The pointer points to addr (%p) containing value %d\n", pointer_to_i, *pointer_to_i);
  return 0;
}
