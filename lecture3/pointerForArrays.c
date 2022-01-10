#include <stdio.h>
#define ARRAY_SIZE 4

main() {
  int foo[ARRAY_SIZE] = {1, 22, 333, 444};
  int *bar = foo;
  int *barbar = &(foo[0]);

  int i;

  printf(" ------------ foo with indices -----------\n"); 
  for( i=0; i< ARRAY_SIZE; i++ ) {
    printf("i: %d\tfoo[%d]: %d\n", i, i, foo[i]);
  }
  printf(" ------------ now with pointers -----------\n"); 
  for( i=0; i< ARRAY_SIZE; i++ ) {
    printf("i: %d\tfoo[%d]: %d\n", i, i, *bar);
    bar++;
  }
}
