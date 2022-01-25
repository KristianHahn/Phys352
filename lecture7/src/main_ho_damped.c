/* 
   Damped HO with the RKO4 method
*/

#include <stdio.h>
#include <math.h>
#include <euler.h>
#include <stdlib.h> /* for strtod */

#include "rkO4.h"
#include "sho.h"

#ifndef MAX
#define MAX 400
#endif

#ifndef TSTEP
#define TSTEP 0.04
#endif


int main(int argc, char ** argv) { 

  int i=0;
  TwoComponent x[MAX]; /* Na = theta, Nb = omega */
  double t[MAX];
  double dt=TSTEP;
  double fparams[] = { 9.81, /* g */
                       1.0,  /* l */
                       1.0   /* q */ 
  }; 
  double errsum=0;

  if( argc != 3 ) {
    fprintf(stderr, "error: argument is <theta_i> <q>\n");
    return -1;
  }

  /* radians */
  x[0].A=strtod(argv[1],NULL), x[0].B=0.;
  t[0]=0;

  /* update q in fparams with input value */
  fparams[2] = strtod(argv[2],NULL);

  rkO4_solver_2component_fp(x,t,&ftheta,&f_damped,fparams,dt,MAX); 

  for( i=0; i<MAX; i++ ) { 
    printf( "t: %lf\ttheta: %lf\tomega: %lf\tenergy: %lf\n", 
	    t[i], x[i].A, x[i].B, total_energy((x+i),fparams) );
  }

}
