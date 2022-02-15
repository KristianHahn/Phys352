#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for strtod
#include "rkO4.h"
#include "rkO2.h"
#include "lorenz.h"



#define MAX   200000
#define TSTEP 0.0001

int main(int argc, char ** argv) { 

  if( argc != 4 ) {
    fprintf(stderr, "error: arguments are <sigma> <b> <r>\n");
    return -1;
  }

  int i=0;
  FourComponent w[MAX]; // A=x,B=y,C=z
  double t[MAX];
  double dt=TSTEP;
  double fparams[] = { strtod(argv[1],NULL),  // sigma
		       strtod(argv[2],NULL),  // b
		       strtod(argv[3],NULL)   // r
  }; 

  //printf("w size: %d\n", sizeof(w));
  //printf("t size: %d\n", sizeof(t));

  //printf("sigma: %lf\tb: %lf\tr: %lf\n",fparams[0],fparams[1],fparams[2]);

  w[0].A = 1;
  w[0].B = 0;
  w[0].C = 0;


  rkO2_solver_4component_fp(w,t,
			    &fx_lorenz,&fy_lorenz,&fz_lorenz,&noop_lorenz,
			    &(fparams[0]),dt,MAX); 


  for( i=0; i<MAX; i++ ) { 
    printf( "t: %lf\tx: %lf\ty: %lf\tz: %lf\n",
	    t[i], w[i].A, w[i].B, w[i].C);
  }

}
