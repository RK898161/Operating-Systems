#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, j;
  int multiplier = atoi(argv[1]);
  for(i = 0; i < 10000; i++)
    j = i * multiplier;
  return 0;
}
