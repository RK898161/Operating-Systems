#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  volatile unsigned long long i;
  float sum; 
  int number;
  time_t start, end;
  time(&start);

  for (i = 0; i < 5000000000ULL; i++){
    sum = 999999.9 / 9939.8;
  }  

  time(&end);

  printf("Type in a  number: \n");
  scanf("%d", &number);
  printf("Number %d while the sum is %f in  %f seconds\n", number, sum, difftime(end,start));
  return 0;
}
