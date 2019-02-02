#include <stdio.h>

int pass_by_value(int i) {
  i = i * 2;
  return i;
}

int main(int argc, char *argv[]) {
  int i = 123;
  printf("Variable i before function call: %d\n", i);
  printf("Function returns: %d\n", pass_by_value(i));
  printf("Variable i after function call: %d\n", i);
  return 0;
}
