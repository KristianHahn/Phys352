#include <stdio.h>
#include <fftw3.h>
#include <math.h>

#define FFT_FORWARD 1
#define FFT_ESTIMATE 1

#define SAMPLE_STEP 0.01


int main(int argc, char** argv) { 

  	 double *in;
	 fftw_complex *out;
         fftw_plan p;

	 // read first just to determine number of points
	 FILE * f = fopen(argv[1], "r");
	 int N=0;
	 double t, theta, omega, x, y;
	 while( fscanf(f, "t: %lf\ttheta: %lf\tomega: %lf\tx: %lf\ty: %lf\n",  &t, &theta, &omega, &x, &y)
		!= EOF ) { 
	   N++;
	 }

	 rewind(f);
         in = (double*) fftw_malloc(sizeof(double) * N);
         out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
         p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

	 N=0;
	 while( fscanf(f, "t: %lf\ttheta: %lf\tomega: %lf\tx: %lf\ty: %lf\n",  &t, &theta, &omega, &x, &y)
		!= EOF ) { 
	   in[N] = theta;
	   N++;
	 }
		  
				  
         fftw_execute(p); 

	 int i;
	 for(i=0; i<N; i++ ) { 
	   printf( "f: %lf\tamp: %lf\n", 
		   (double)i/(N*SAMPLE_STEP),
		   sqrt(out[i][0]*out[i][0] + out[i][1]*out[i][1]));
	 } 

         fftw_destroy_plan(p);
         fftw_free(in); fftw_free(out);

}
