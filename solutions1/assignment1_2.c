#include <stdio.h>
#define ARRAY_SIZE 3
int main() {
  int i=0,j=1;
  char c,carray[ARRAY_SIZE];
  printf( "\nPlease input some characters ...\n\n");
  while(fgets(carray, ARRAY_SIZE, stdin) != NULL ) { 
    if( j ) { printf( "You input: ");  j=0;}
    printf( "%s", carray);
    for( i=0; i<ARRAY_SIZE; i++ ) { 
      /*       this will put blank lines in between */
      if ( carray[i] == '\n' ) { j=1; printf ("\n"); break; }
      /*       this will not */
      if ( carray[i] == '\n' ) { j=1;  break; }
      else j=0;
    }
  }
  printf("\n\nfini!\n");
}

