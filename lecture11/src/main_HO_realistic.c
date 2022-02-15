#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for strtod
#include "rkO4.h"
#include "sho.h"



#define MAX   20000
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
		       9.8,  // l ??? not 1 ???
		       strtod(argv[2],NULL),  // q
		       strtod(argv[3],NULL),  // F_D
		       strtod(argv[4],NULL)   // W_D
  }; 
  double errsum=0;


  // radians
  x[0].A = strtod(argv[1],NULL), x[0].B=0.;
  t[0]=0;

  //rkO4_solver_2component_anglewrap_fp(&(x[0]),t,&ftheta,&f_damped_driven,&(fparams[0]),dt,MAX); 
  rkO4_solver_2component_anglewrap_fp(&(x[0]),t,&ftheta,&f_damped_driven_NL,&(fparams[0]),dt,MAX); 


  for( i=0; i<MAX; i++ ) { 
    printf( "t: %lf\ttheta: %lf\tomega: %lf\tx: %lf\ty: %lf\n",
	    t[i], x[i].A, x[i].B, 9.8*cos(M_PI-x[i].A), 9.8*sin(M_PI-x[i].A) );
/*     if( t[i] > 20 ) {   */
/*     printf( "t: %f\ttheta: %f\tomega: %f\n", */
/* 	    t[i], x[i].Na, x[i].Nb ); */
/*     printf( "%f,%f,%f,%f,%f\n", */
/* 	    t[i], x[i].Na, x[i].Nb, 9.8*cos(3.1415-x[i].Na), -9.8*sin(3.1415-x[i].Na) ); */
/*     } */
  }

}
