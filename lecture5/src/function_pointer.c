#include <stdio.h>

int add( int a, int b) { 
  return a+b;
}

int main() { 
  int x=1, y=2;
  int (*f)(int,int) = &add;
  printf( "result: %d\n", (*f)(x,y) );
}
