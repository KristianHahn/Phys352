#include <stdio.h>

int main () { 

  unsigned a[] = { 1, 2, 3, 4};

  unsigned * ptr = a;
  printf( "*ptr: 0x%016lx\n", *ptr);
  printf( "*(ptr+1): 0x%016lx\n", *(ptr+1));

  /* could cast to a new pointer ... */
  /*
    unsigned long * ptrl  = (unsigned long *)ptr;
    printf( "*ptrl: 0x%016lx\n", *(ptrl));
    printf( "*(ptrl+1): 0x%016lx\n", *(ptrl+1));
  */

  /* or just cast in place ... */
  printf( "*ptr: 0x%016lx\n", *( ((unsigned long*)ptr) + 0) );
  printf( "*(ptr+1): 0x%016lx\n", *( ((unsigned long*)ptr) + 1) );

}
