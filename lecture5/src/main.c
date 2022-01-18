#include <stdio.h>
#include "euler.h"

#define MAX 100
#define FP 0

int main() { 
  int i=0;
  double n[MAX], t[MAX];
  double dt=0.05;
  double fparams[] = {1.}; /* tc */

  /* set intial values */
  n[0]=100., t[0]=0;

#ifndef FP
  /* standard */
  euler_solver(n,t,dt,MAX);   
#else  
  /* with function pointer */
  euler_solver_fp(n,t,&f,fparams,dt,MAX); 
#endif

  for( i=0; i<MAX; i++ ) { 
    printf( "%f\t%f\n", n[i], t[i]);
  }
}
