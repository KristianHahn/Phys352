#include <stdio.h>
#define ARRAY_SIZE 3

main() {

  char c,carray[ARRAY_SIZE];
  int i=0,j;

  printf( "\nPlease input some characters ...\n\n");
  while( c != EOF ) { 
   c = getchar();
   if ( c == EOF ) break ;
   if ( c != '\n' ) { 
      carray[i] = c; i++; 
    } else {
      printf( "You input: ");
      for( j=0; j<ARRAY_SIZE; j++ ) {
	putchar(carray[j]);
      }
      putchar('\n'); i=0;
    }
  }
  printf("\nfini!\n");
}
