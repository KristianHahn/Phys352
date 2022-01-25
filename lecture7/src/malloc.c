#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) { 
  
  if( argc !=2 ) { 
    printf("need to input an array size\n");
    return -1;
  }

  unsigned len = strtoul(argv[1],NULL,10);
  printf( "allocating int array of size %d\n", len);

  /*   make an array of integers len long  */
  int* arr = (int*)malloc(len*sizeof(int));
  
  for( int i=0; i<len; i++ ) 
    arr[i] = i;
  for( int i=0; i<len; i++ ) 
    printf( "%d\n", arr[i]);
  
  free(arr);

}
