#include <stdio.h>
#include <inttypes.h>

#define N 17 

void 
main() {
  int64_t foo, bar=1; 
  for( foo=N; foo>0; foo-- ) {
    bar *= foo;
  }
  printf( "%li! = %li\n", N,bar );
}

