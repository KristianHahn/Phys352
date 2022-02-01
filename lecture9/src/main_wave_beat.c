#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

#define MAX_TSAMPLE 800
#define MAX_XSAMPLE 1600


int
main (int argc, char** argv)  { 

  if( argc != 3 ) { 
    printf("usage: main_wave_beat.exe <k1> <k2>\n");
    printf("\twhere k1, k2 are multipliers of 2PI\n");
    return -1;
  }
  double k1  = (2*M_PI)*strtod(argv[1],NULL);//1.1*8*(2*M_PI);
  double k2  = (2*M_PI)*strtod(argv[2],NULL);//8*(2*M_PI);

  /* c = lambda*f = omega/k */
  /* omega = 2PI*f */
  double f1 = c*k1/(2*M_PI); 
  double f2 = c*k2/(2*M_PI); 

  
  double ** yarr = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
  for ( int i=0; i<MAX_TSAMPLE; i++ ) {
    *(yarr+i) = malloc(MAX_XSAMPLE*sizeof(double));
    for ( int j=0; j<MAX_XSAMPLE; j++ ) {
      yarr[i][j] = 0;
    }
  }

  double ** yarr2 = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
  for ( int i=0; i<MAX_TSAMPLE; i++ ) {
    *(yarr2+i) = malloc(MAX_XSAMPLE*sizeof(double));
    for ( int j=0; j<MAX_XSAMPLE; j++ ) {
      yarr2[i][j] = 0;
    }
  }

  // init with full waves ...
  initialize_with_wave(yarr, MAX_XSAMPLE+1, k1, dx );
  initialize_with_wave(yarr2, MAX_XSAMPLE+1, k2, dx );

  propagate( yarr, MAX_TSAMPLE, MAX_XSAMPLE+1, r);
  propagate( yarr2, MAX_TSAMPLE, MAX_XSAMPLE+1, r);



  char fname[256];
  for( int i=0; i<MAX_TSAMPLE; i++ ) { 
    sprintf( fname, "data/wavedata_beat_t_%d.dat", i );
    FILE * f = fopen(fname, "w");
    for( int j=0; j<MAX_XSAMPLE-1; j++ ) {
      fprintf( f, "t: %lf\tx: %lf\ty: %lf\ty2: %lf\tsum: %lf\n",i*dt,j*dx,
	       yarr[i][j],yarr2[i][j],
	       yarr[i][j]+yarr2[i][j]);

    }
    fclose(f);
  }


  FILE * fts = fopen("data/timeseries_2wave_at_x_0.05.dat", "w");
  for( int i=0; i<MAX_TSAMPLE; i++ ) {
    fprintf( fts, "t: %f\tx: %f\ty: %f\ty2: %f\tsum: %f\n",i*dt,5*dx,
	     yarr[i][5],yarr2[i][5],
	     yarr[i][5]+yarr2[i][5]);
  }
  fclose(fts);


  printf("f1: %lf\n", f1);
  printf("f2: %lf\n", f2);

}
