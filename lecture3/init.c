#include <stdio.h>


main() {
  int a=-2, b=3;

  int c  = b+=5*-++a;
  printf( "c: %d\n", c);

  /* reset a and b, confirm precedence  ... */
  a=-2; b=3;
  c = (b+=5)*(-(++a)); 
  
  printf( "vs.\n");
  printf( "c: %d\n", c);

}
