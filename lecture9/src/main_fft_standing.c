#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>
#include "wave.h"

#define MAX_TSAMPLE 400
#define MAX_XSAMPLE 1600




int
main (int argc, char** argv)  { 
  
  if( argc != 2 ) { 
    printf("usage: main_fft_standing.exe <k>\n");
    printf( "\twhere k is a multiple of 2*PI\n");
    return -1;
  }
  double k = strtod(argv[1],NULL);

  double *in;
  fftw_complex *out;
  fftw_plan p;
  int N = 400;

  in = (double*) fftw_malloc(sizeof(double) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

  /* read in the dat file  */
  char fname[156];
  sprintf(fname, "data/timeseries_at_x_0.3_k_%.1lf.dat", k);
  FILE * f = fopen(fname, "r");
  int i=0;
  double tmpt, tmpx, tmpy;
  while( fscanf( f, "t: %lf\tx: %lf\ty: %lf\n", &tmpt, &tmpx, &tmpy ) > 0  ) { 
    in[i++] = tmpy; 
  }

       

  fftw_execute(p);

				  
  for(i=0; i<N; i++ ) { 
    printf( "i: %d\tt: %f\tin: %f\tor: %f\toi: %f\n",
	    i,(i*dt), 
	    in[i],out[i][0], out[i][1]);
  } 

  fftw_destroy_plan(p);
  fftw_free(in); fftw_free(out);
  



}
