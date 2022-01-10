#include <stdio.h>

int foo = 5;

void doItAgain() {
  if( !foo ) return;
  printf( "doing it, foo = %d\n", --foo);
  doItAgain();
}

main() { 
  doItAgain();
}
