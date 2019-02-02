#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]){
  void *p = malloc(100);
  int *ip = (int *)p;
  *ip = 98765;
  printf("%d\n", *ip);
  exit(0);
}
