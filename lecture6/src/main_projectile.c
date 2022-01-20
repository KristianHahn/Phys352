/* 
   Dragless projectiles with the Euler method
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for strtod */

#include "TwoComponent.h"
#include "euler.h"
#include "projectiles.h"

#ifndef MAX
#define MAX 1300
#endif

#ifndef TSTEP
#define TSTEP 0.5
#endif 

int main(int argc, char ** argv) { 

  int i=0;
  TwoComponent projx[MAX]; /* Na = x, Nb = vx */
  TwoComponent projy[MAX]; /* Na = y, Nb = vy */
  double tx[MAX], ty[MAX];
  double dt=TSTEP;
  double fparams[] = {9.81}; /* g */
  double errsum=0;

  if( argc != 3 ) {
    fprintf(stderr, "error: arguments are <vx> <vy>\n");
    return -1;
  }

  projx[0].A=0., projx[0].B=strtod(argv[1],NULL);
  projy[0].A=0., projy[0].B=strtod(argv[2],NULL);
  tx[0]=0, ty[0]=0;

  euler_solver_2component_fp(projx,tx,&fx,&fvx,fparams,dt,MAX); 
  euler_solver_2component_fp(projy,ty,&fy,&fvy,fparams,dt,MAX); 


  for( i=0; i<MAX; i++ ) { 
    printf( "t: %f\tx: %f\ty: %f\tvx: %f\tvy: %f\n", tx[i], 
	    projx[i].A, projy[i].A,
	    projx[i].B, projy[i].B );
  }

}
