#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>


#define N      500    /* number of data points to generate */
#define TMAX   (100.0)  /* time variable in [0,TMAX] */


int
main (void)
{

  gsl_rng_env_setup();
  gsl_rng * r = gsl_rng_alloc(gsl_rng_default);

  /* this is the data to be fitted */
  for (int i = 0; i < N; i++)
    {
      double ti = i * TMAX / (N - 1.0);
      // no DC term ...
      //      double yi = 1.0 + 5 * exp (-0.05 * ti);
      double yi = 5 * exp (-0.05 * ti);
      double si = 0.1 * yi;
      double dy = gsl_ran_gaussian(r, si);


      printf ("x: %lf\ty: %lf\tw: %lf\n", ti, yi+dy , 1.0 / (si * si));
    };


  return 0;
}
