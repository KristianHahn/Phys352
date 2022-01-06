#include <stdio.h>

main() {

  char c;

  printf( "\nPlease input some characters ...\n\n");
  while( c != EOF ) { 
    c = getchar();
    if( c != '\n' && c != EOF ) { 
      printf( "Your input: ");
      putchar(c);
      putchar('\n');
    }
  }
  printf("\nfini!\n");
}
