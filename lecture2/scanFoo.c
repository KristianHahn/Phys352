#include <stdio.h>
#define ASIZE 256

main() {
  char carray[ASIZE];
  int month, day, year; 

  printf( "Input a string: " );
  
  scanf( "%s", &carray);
  printf( "You input: %s\n", carray);

  printf( "Input today's date (MM-DD-YYYY): " );

  scanf( "%d-%d-%d", &month, &day, &year);
  printf( "Today is %d/%d/%d\n", month, day, year);

}
