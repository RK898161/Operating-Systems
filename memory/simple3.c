#include <stdio.h>
#include <stdlib.h>

int y;
int z = 10;

int main(int argc, char *argv[]){
  printf("location of code: %p\n", (void *) main);
  printf("location of data: %p\n", (void *) &z);
  printf("location of bss:  %p\n", (void *) &y);
  printf("location of heap: %p\n", (void *) malloc(sizeof(int)));
  printf("location of heap: %p\n", (void *) malloc(10 * sizeof(int)));
  printf("location of heap: %p\n", (void *) malloc(sizeof(float)));
  int x = 3;
  printf("location of stack (x): %p\n", (void *) &x);
  float w = 6;
  printf("location of stack (w): %p\n", (void *) &w);
  float i = 10.0;
  printf("location of stack (i): %p\n", (void *) &i);
  return 0;
}
