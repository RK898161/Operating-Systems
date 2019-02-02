#include <stdio.h>
int times2(int x);
int times5(int x);
void array_apply(int a[], int alen, int (*fp)(int));

int times5(int x) {
  return x * 5;
}

int times2(int x) {
  return  x * 2;
}

void array_apply(int a[], int alen, int (*fp)(int)){
  int i; 
  for (i = 0; i < alen; i++){
    a[i] =  (*fp)(a[i]);
    printf("New value at index %d is %d\n", i, a[i]);
  }
}

int main(int argc, char *argv[]){
  int numbers[] = {1, 2, 3};
  array_apply(numbers, 3, times2);
  array_apply(numbers, 3, times5);
  return 0;
}
