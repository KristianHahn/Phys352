#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for strtod
#include "rkO4.h"
#include "sho.h"

#define MAX 30000
#define TSTEP 0.01

int main(int argc, char ** argv) { 

  if( argc != 5 ) {
    fprintf(stderr, "error: arguments are <theta_i> <q> <F_D> <W_D>\n");
    return -1;
  }

  int i=0;
  TwoComponent x[MAX]; // Na = theta, Nb = omega
  double t[MAX];
  double dt=TSTEP;
  double fparams[] = { 9.8, // g
		       9.8,  // l
		       strtod(argv[2],NULL),  // q
		       strtod(argv[3],NULL),  // F_D
		       strtod(argv[4],NULL)   // W_D
  }; 
  double errsum=0;



  // radians
  x[0].A=strtod(argv[1],NULL), x[0].B=0.;
  t[0]=0;

  rkO4_solver_2component_anglewrap_fp(x,t,&ftheta,&f_damped_driven_NL,fparams,dt,MAX); 


  // this is for gnerating data in the transient stage 
  for( i=0; i<MAX; i++ ) { 
    if( fabs(fmod(fparams[4]*t[i],(2*M_PI))) < dt/2 ) { 
      printf( "t: %f\ttheta: %f\tomega: %f\n", 
	      t[i], x[i].A, x[i].B );
    }
  }


  // this is to generate many points in the stable regime
  // run the i loop 2 times ...
  for ( int j=0; j<2; j++ ) { 
    x[0].A = x[MAX-1].A;
    x[0].B = x[MAX-1].B;
    t[0] = t[MAX-1];
    rkO4_solver_2component_anglewrap_fp(x,t,&ftheta,&f_damped_driven_NL,fparams,dt,MAX); 
    for( i=0; i<MAX; i++ ) { 
      if( fabs(fmod(fparams[4]*t[i],(2*M_PI))) < dt/2 ) { 
	printf( "t: %f\ttheta: %f\tomega: %f\n", 
		t[i], x[i].A, x[i].B );
      }
    }
  }


  
}
