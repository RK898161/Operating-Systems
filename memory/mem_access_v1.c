#include <stdlib.h>
#define N 50000000

int main(int argc, char *argv[]) {
  int i;
  int *A = (int *)malloc(N*sizeof(int));
  if (!A) return 1;
  for(i = 0; i < 10000; i++)
    A[i] = 0;
  return 0;
}
