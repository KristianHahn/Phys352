#include <stdio.h>

int foo = 5;

int doIt() {
  return foo--;
}

main() { 
  while( doIt() ) {
    printf( "doing it, foo = %d\n", foo);
  }
}
