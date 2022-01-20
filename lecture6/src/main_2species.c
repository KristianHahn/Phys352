#include <stdio.h>
#include "euler.h"
#include "decay.h"

#ifndef MAX
#define MAX 100
#endif 

int main() { 
  int i=0;
  TwoComponent n[MAX];
  double t[MAX];
  double dt=0.05;
  double fparams[] = {1.,1.}; /* tc */

  /* set intial values */
  n[0].A=1000., n[0].B=0, t[0]=0;
  euler_solver_2component_fp(n,t,&fA,&fB,fparams,dt,MAX); 

  for( i=0; i<MAX; i++ ) { 
    printf( "%f\t%f\t%f\n", n[i].A, n[i].B, t[i]);
  }

}
