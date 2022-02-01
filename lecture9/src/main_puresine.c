#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define FFT_ESTIMATE 1
//#define FFT_FORWARD 1

#define SIGNAL_PERIOD 4.2666
// f = 0.2344 Hz

#define SAMPLE_DURATION 12.8 // seconds
#define SAMPLE_STEP 0.1      // seconds


int main(int argc, char** argv) { 
  
  if( argc < 2 ) { 
    printf("usage : main_puresine.exe <phase>\n");
    printf("\twhere phase is a multiplier of PI/2\n");
    return -1;
  }
  double phase = (M_PI/2)*strtod(argv[1],NULL);

  double *in;
  fftw_complex *out;
  fftw_plan p;
  
  int N = (int)(SAMPLE_DURATION/SAMPLE_STEP);
  
  in = (double*) fftw_malloc(sizeof(double) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
  
  
  int i	;
  for(i=0; i<SAMPLE_DURATION/SAMPLE_STEP; i++ ) { 
    in[i] = sin((2.*M_PI/SIGNAL_PERIOD)*(i*SAMPLE_STEP) + phase);
  } 
  
  
  fftw_execute(p); 
  
  for(i=0; i<SAMPLE_DURATION/SAMPLE_STEP; i++ ) { 
    printf( "i: %d\tt: %f\tin: %f\tor: %f\toi: %f\n", i,
	    (i*SAMPLE_STEP),
	    in[i],out[i][0], out[i][1]);
  } 
  
  fftw_destroy_plan(p);
  fftw_free(in); fftw_free(out);
}
