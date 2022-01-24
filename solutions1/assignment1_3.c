/*

First I dump the addresses of the a & b arrays.  Note that &a > &b: because 
a is declared first, it appears at lower in the stack (ie: at higher
address space).  The stack grows upward, so when one writes past the bounds
of b, one eventually corrupts a.

*/

#include <stdio.h>

int main() { 
  int i;
  char a[] = "hello"; 
  char b[] = "there"; 

  printf("\n\n&a: %u\n", a );
  printf("----------\n");
  for( i=0; i<6; i++ ) {
    printf("&a[%d]: %u\n", i, &(a[i]) );
  }

  printf("\n\n&b: %u\n", b );
  printf("----------\n");
  for( i=0; i<6; i++ ) {
    printf("&b[%d]: %u\n", i, &(b[i]) );
  }  

  printf("\n\n");

  printf("what strings do a and b contain?\n");
  printf ("a: %s\n", a);
  printf ("b: %s\n", b);

  printf("\n\n");
  printf("now indexing further into b ...\n");
  for( i=6; i<17; i++ ) {
    printf( "index %d, address: %u\n", i, &(b[i]) );
    b[i]='j';
  }

  printf ("a: %s\n", a);
  printf ("b: %s\n", b);
}
