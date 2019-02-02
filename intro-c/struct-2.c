#include <stdio.h>
#include <stdlib.h>
struct point {
  int x; 
  int y;
};

int main(int argc, char *argv[]){
  struct point *p = (struct point *)malloc(sizeof(struct point));
  (*p).x = 0;
  (*p).y = 0;
  printf("The coordinates of origin is %d and %d\n", (*p).x, (*p).y);
  return 0;
}
