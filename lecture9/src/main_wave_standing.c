#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

#define MAX_TSAMPLE 400
#define MAX_XSAMPLE 1600

/*
const double k1  = 1.1*8*(2*M_PI);
const double k2  = 8*(2*M_PI);
*/

/* c = lambda*f = omega/k 
          omega = 2PI*f 
const double f1 = c*k1/(2*M_PI); 
const double f2 = c*k2/(2*M_PI); 
*/


int
main (int argc, char** argv)  { 
  
  if( argc != 2 ) { 
    printf("usage: main_wave_standing.exe <k>\n");
    printf( "\twhere k is a multiple of 2*PI\n");
    return -1;
  }
  double kmultiplier = strtod(argv[1],NULL);
  double k = kmultiplier*(2*M_PI);
  double f = c*k/(2*M_PI);

  double ** yarr = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
  for ( int i=0; i<MAX_TSAMPLE; i++ ) {
    *(yarr+i) = malloc(MAX_XSAMPLE*sizeof(double));
    for ( int j=0; j<MAX_XSAMPLE; j++ ) {
      yarr[i][j] = 0;
    }
  }


  // init with full wave ...
  initialize_with_wave(yarr, MAX_XSAMPLE, k, dx );

  // generate the wave data
  propagate( yarr, MAX_TSAMPLE, MAX_XSAMPLE, r);



  // print timeseries for all x ...
  char fname[256];
  for( int i=0; i<MAX_TSAMPLE; i++ ) { 
    sprintf( fname, "data/standing_t_%d.dat", i );
    FILE * f = fopen(fname, "w");
    for( int j=0; j<MAX_XSAMPLE; j++ ) { 
      fprintf( f, "t: %f\tx: %f\ty: %f\n",i*dt,j*dx,yarr[i][j]);
    }
    fclose(f);
  }

  // print timeseries at x = 30% of range...
  sprintf(fname, "./data/timeseries_at_x_0.3_k_%.1lf.dat", kmultiplier);
  FILE* fts = fopen( fname, "w");
  for( int i=0; i<MAX_TSAMPLE; i++ ) { 
    int j=30; //not to MAX_XSAMPLE, that goes past 1 ...
    fprintf( fts, "t: %f\tx: %f\ty: %f\n",i*dt,j*dx,yarr[i][j]);
  }
  fclose(fts);

  printf("k: %lf\n", k);
  printf("f: %lf\n", f);


}
