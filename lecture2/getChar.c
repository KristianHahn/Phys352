#include <stdio.h>

main() {
  char c; 

  printf( "\nPlease input a character ...\n\n");

  c = getchar();
  printf( "Your input: ");
  putchar(c);
  putchar('\n');
}
