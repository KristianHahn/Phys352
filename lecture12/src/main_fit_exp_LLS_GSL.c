#include <stdio.h>
#include <string.h>
#include <gsl/gsl_fit.h>


int
main (int argc, char** argv)
{

  char * fname = argv[1];
  int N = strtoul(argv[2],NULL,10);


  double * x = malloc(N*sizeof(double));
  double * y = malloc(N*sizeof(double));
  double * w = malloc(N*sizeof(double));



  //
  // read in the data
  //
  int i=0;
  double tmpy, tmpw;
  FILE * f = fopen(fname, "r");
  while( fscanf(f, "x: %lf\ty: %lf\tw: %lf\n", x+i, &tmpy, &tmpw  ) != EOF ){ 
    y[i] = log(tmpy);
    printf( "x: %lf\tlog(Y): %lf\n", x[i], y[i] );
    w[i] = .5; //dummy value tmpw
    i++;
  }


  double c0, c1, cov00, cov01, cov11, chisq;

  if( argc > 3 && !strcmp(argv[3],"weight")) { 

    gsl_fit_wlinear (x, 1, w, 1, y, 1, N,
		     &c0, &c1, &cov00, &cov01, &cov11,
		     &chisq);
  } else { 
    gsl_fit_linear (x, 1, y, 1, N,
		    &c0, &c1, &cov00, &cov01, &cov11,
		    &chisq);
  }

  printf ("# best fit: Y = %g + %g X\n", c0, c1);
  printf ("# exp(c0) = %g\n", exp(c0));
  printf ("# covariance matrix:\n");
  printf ("# [ %g, %g\n#   %g, %g]\n", cov00, cov01, cov01, cov11);
  printf ("# chisq = %g\n", chisq);


  /*
  for (i = 0; i < n; i++)
    printf ("data: %g %g %g\n",
	    x[i], y[i], 1/sqrt(w[i]));

  printf ("\n");
  */

  for (i = 0; i < 100; i++)
    {
      double xf = x[0] + (i/100.0) * (x[N-1] - x[0]);
      double yf, yf_err;

      gsl_fit_linear_est (xf,
                          c0, c1,
                          cov00, cov01, cov11,
                          &yf, &yf_err);

      printf ("++fit++ x: %g yfit: %g fitup: %g fitdown: %g exp: %g up: %g down %g\n", xf, 
	      yf, yf + yf_err, yf - yf_err,
	      exp(yf), exp(yf + yf_err), exp(yf - yf_err)
	      );
    }

  return 0;
}
