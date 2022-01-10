#include <stdio.h>

int foo() { 
  return 5;
}

main() { 

  int foo() { 
    return 13;
  }
  printf( "foo: %d\n",foo());
}
