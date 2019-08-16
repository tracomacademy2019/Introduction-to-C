#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;

int main() {
  point * mypoint;

  /* Dynamically allocate a new point
     struct which mypoint points to here */
  mypoint = malloc(sizeof(mypoint));
  mypoint->x = 10;
  mypoint->y =5 ;
  printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

  free(mypoint);
  return 0;
}
