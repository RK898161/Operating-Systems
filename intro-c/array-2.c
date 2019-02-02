#include <stdio.h>

int main(int argc, char *argv[]){
  double numbers[5];
  int i;

  for (i = 0; i < 5; i++){
    numbers[i] = (double)i * 2;
    printf("Index %d has value %f at address (%p)\n", i, numbers[i], (numbers + i));
  }
  return 0;
}
