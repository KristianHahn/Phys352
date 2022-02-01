#include <stdio.h>
#include <fftw3.h>
#include <math.h>
#include <stdlib.h>
#include "wave.h"

#define FFT_FORWARD 1
#define FFT_ESTIMATE 1


#define SAMPLE_STEP 0.0000333333333


int main(int argc, char** argv) { 

  if( argc != 2 ) { 
    printf("usage: main_fft_beat.exe <col#>\n");
    printf("\twhere col# is : \n");
    printf("\t\t1 : k1\n");
    printf("\t\t2 : k2\n");
    printf("\t\t3 : sum\n");
    return -1;
  }

  int colnum = strtoul(argv[1], NULL,10);

  double *in;
  fftw_complex *out;
  fftw_plan p;

  int N = 800;
	 
  in = (double*) fftw_malloc(sizeof(double) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

  
  /* read in the dat file  */
  FILE * f = fopen("data/timeseries_2wave_at_x_0.05.dat", "r");
  int i=0;
  double tmpt, tmpx, tmpy, tmpy2, tmpsum;
  while( fscanf( f, "t: %lf\tx: %lf\ty: %lf\ty2: %lf\tsum: %lf\n", &tmpt, &tmpx, &tmpy, &tmpy2, &tmpsum ) > 0  ) { 
    
    if( colnum == 1 ) 
      in[i] = tmpy; 
    if( colnum == 2 )
      in[i] = tmpy2;
    if( colnum == 3) 
      in[i] = tmpsum; 
    i++;
  }

       


  fftw_execute(p);

				  
  for(i=0; i<N; i++ ) { 
    printf( "i: %d\tt: %f\tin: %f\tor: %f\toi: %f\n",
	    i,(i*SAMPLE_STEP),
	    in[i],out[i][0], out[i][1]);
  } 

  fftw_destroy_plan(p);
  fftw_free(in); fftw_free(out);
  



}
