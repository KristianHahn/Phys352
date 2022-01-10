#include <stdio.h>

main() {
  int foo=1;
  printf( "foo: %d\n", ++foo );
  printf( "foo: %d\n", foo );
  printf( "foo: %d\n", foo-- );
  printf( "foo: %d\n", foo );
}
