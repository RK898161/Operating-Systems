#include <stdio.h>
struct point {
  int x; 
  int y;
};

int main(int argc, char *argv[]){
  struct point origin;
  origin.x = 0;
  origin.y = 0;
  printf("The coordinates of origin is %d and %d\n", origin.x, origin.y);
  return 0;
}
