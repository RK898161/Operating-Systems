#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB (KB * KB)

int main(int argc, char *argv[]){
  int mem_size;
  char *arr ;
  int i = 0;

  mem_size = atoi (argv[1]);
  printf("%d %d %d\n", mem_size, KB, MB);
  arr = (char*) malloc(mem_size * MB * sizeof(char));
  printf("Finish malloc\n");
  for (i = 0; i < mem_size * MB - 1; i++){ 
    arr[i] = 'a';
  } 
  printf("Finish initialize\n");
  while(1 == 1){  
    arr[i] = 'A';
    if (i == mem_size * MB - 1) {
      i = 0;
    }
  }
  return 0;
}
