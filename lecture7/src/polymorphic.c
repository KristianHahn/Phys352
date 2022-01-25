#include <stdio.h>

/* ---------------------------------------------------------
   A generic pointer loop : for each element in an array of a
   given length, perform the operation pointed to by fptr. 
   Need to cast the void pointer to an type corresponding to  
   non-zero size in order to iterate ... char * is easiest. 
 ---------------------------------------------------------- */
void 
generic_array_operation( void * ptr, void (*fptr)(void *), 
			 int size_in_bytes, int length ) 
/* ---------------------------------------------------------*/
{
  for( int i=0; i<length; i++ ) {
    /* cast to (sized) char ptr */
    char * cptr = (char*)ptr; 

    /* now we can increment */
    cptr += i*size_in_bytes;   

    /* cast back to void for our function call */
    (*fptr)( (void*)cptr );   
  }
}


/* ---------------------------------------------------------
   A composite type, to contrast with the basic types
 ---------------------------------------------------------- */
typedef struct { 
  float foo;
  char bar[128];
} Thing;


/* ---------------------------------------------------------
   An integer-specific operation: integer divison
 ---------------------------------------------------------- */
void
int_operation( void * ptr ) 
/* ---------------------------------------------------------*/
{
  /* cast the void pointer to int  */
  int * iptr = (int *)ptr;
  /* then can perform integer division */
  *(iptr) /= 2; 
}

/* ---------------------------------------------------------
   A struct-specific operation: sub field string manipulation
 ---------------------------------------------------------- */
void
thing_operation( void * ptr ) 
/* ---------------------------------------------------------*/
{
  /* cast the void pointer to thing  */
  Thing * tptr = (Thing *)ptr;
  /* then can perform string manipulation on the Thing*/
  sprintf( tptr->bar, 
	   "%s's favorite number is %f", 
	   tptr->bar, tptr->foo );
}


/* ---------------------------------------------------------
   Declare two arrays, one of type int, the other of Thing.
   Use the generic_array_operations function to manipulate the
   elements of both arrays via the type-specific functions
   above.  Print out the results. 
 ---------------------------------------------------------- */
int main()  
/* ---------------------------------------------------------*/
{
  int int_array[]     = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  Thing thing_array[] = { {3.1415, "thing#1"},
			  {1.414,  "thing#2"},
			  {2.718,  "thing#3"},
			  {3.142,  "thing#4"} };

  int int_arr_len = sizeof(int_array)/sizeof(int);
  generic_array_operation( (void*)int_array, &int_operation, 
			    sizeof(int), int_arr_len);
  for( int i=0; i<int_arr_len; i++ ) 
    printf( "int_array[%d]: %d\n", i, int_array[i]);

  printf("\n");

  int thing_arr_len = sizeof(thing_array)/sizeof(Thing);
  generic_array_operation( (void*)thing_array, &thing_operation, 
			    sizeof(Thing), thing_arr_len);
  for( int i=0; i<thing_arr_len; i++ ) 
    printf( "thing_array[%d]: %s\n", i, thing_array[i].bar);
}
