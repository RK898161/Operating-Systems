#include <stdio.h>

int times4(int x) {
  return times2(x) * 2;
}

int times2(int x) {
  return  x * 2;
}

int main(int argc, char *argv[]){
  int x = 100;
  printf("Result: %d\n", times4(x));
  return 0;
}
