#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for strtod
#include "logistic.h"

#define MAX 3000

int main(int argc, char ** argv) { 

  double x[MAX], xn[MAX], xnp1[MAX];
  double mu = strtod(argv[1],NULL);
  double x0 = strtod(argv[2],NULL);

  if( argc != 3 ) {
    fprintf(stderr, "error: arguments are <mu> <x0>\n");
    return -1;
  }

  x[0] = x0;
  xn[0]  = x0;
  xnp1[0] =  0;
  for (int i=1; i<MAX; i++ ) { 
    x[i] = logistic(x[i-1],mu);
  }  
  
  // for iterate
  int i = 1, count=1;
  while( i < MAX) { 
    if( i%2 ) { 
      // hold x, update y
      xn[i] = xn[i-1];
      xnp1[i] = x[count];
      count++;
    } 
    else {
      //transfer y to x
      xn[i]   = xnp1[i-1];
      xnp1[i] = xnp1[i-1];
    }
    i++;
  } 

  for( int i=0; i<MAX; i++ )  { 
    printf( "n: %d\tx: %lf\tx[n]: %lf\tx[n+1]: %lf\n", i, x[i],xn[i], xnp1[i]);
  }
}
