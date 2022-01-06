#include <stdio.h>

main() {

  char c;

  printf( "\nPlease input some characters ...\n\n");
  while( c != EOF ) { 
    c = getchar();
    printf( "\nYour input: ");
    putchar(c);
    putchar('\n'); 
  }
  printf("\nfini!\n");
}
