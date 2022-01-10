#include <stdio.h>

#define foo 1
#define bar 2
#define foobar foo+bar 

main() {
  int a=-2, b=3;

  int c  = b+=5*-++a;
  printf( "c: %d\n", c);

  /* check precedence  ... */
  a=-2; b=3;
  c = (b+=5)*(-(++a)); 
  
  printf( "vs.\n");
  printf( "c: %d\n", c);

}
