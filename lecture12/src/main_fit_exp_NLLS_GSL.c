#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>

#include "exp_for_GSL.h"
#include "utils.h"

#define N      100    /* number of data points to fit */
#define TMAX   (3.0)  /* time variable in [0,TMAX] */



int
main (int argc, char** argv)
{

  const gsl_multifit_nlinear_type *T = gsl_multifit_nlinear_trust;
  gsl_multifit_nlinear_workspace *w;
  gsl_multifit_nlinear_fdf fdf;
  gsl_multifit_nlinear_parameters fdf_params =
    gsl_multifit_nlinear_default_parameters();
  const size_t n = N;
  const size_t p = 3;

  gsl_vector *f;
  gsl_matrix *J;
  gsl_matrix *covar = gsl_matrix_alloc (p, p);
  double t[N], y[N], weights[N];
  struct data d = { n, t, y };
  double x_init[3] = { 1.0, 1.0, 0.0 }; /* starting values */
  gsl_vector_view x = gsl_vector_view_array (x_init, p);
  gsl_vector_view wts = gsl_vector_view_array(weights, n);
  gsl_rng * r;
  double chisq, chisq0;
  int status, info;
  size_t i;

  const double xtol = 1e-8;
  const double gtol = 1e-8;
  const double ftol = 0.0;

  gsl_rng_env_setup();
  r = gsl_rng_alloc(gsl_rng_default);

  /* define the function to be minimized */
  fdf.f = expb_f;
  fdf.df = expb_df;   /* set to NULL for finite-difference Jacobian */
  fdf.fvv = NULL;     /* not using geodesic acceleration */
  fdf.n = n;
  fdf.p = p;
  fdf.params = &d;




  /* this is the data to be fitted */
  for (i = 0; i < n; i++)
    {
      double ti = i * TMAX / (n - 1.0);
      double yi = 1.0 + 5 * exp (-1.5 * ti);
      double si = 0.1 * yi;
      double dy = gsl_ran_gaussian(r, si);

      t[i] = ti;
      y[i] = yi + dy;
      weights[i] = 1.0 / (si * si);
      printf ("data: %g %g %g\n", ti, y[i], si);
    };


  /* allocate workspace with default parameters */
  w = gsl_multifit_nlinear_alloc (T, &fdf_params, n, p);

  /* initialize solver with starting point and weights */
  if( argc > 1 && !strcmp(argv[1],"weight")) { 
    gsl_multifit_nlinear_winit (&x.vector, &wts.vector, &fdf, w);
  } else { 
    gsl_multifit_nlinear_init (&x.vector, &fdf, w);
  }

  /* compute initial cost function */
  f = gsl_multifit_nlinear_residual(w);
  gsl_blas_ddot(f, f, &chisq0);

  /* solve the system with a maximum of 100 iterations */
  status = gsl_multifit_nlinear_driver(100, xtol, gtol, ftol,
                                       callback, NULL, &info, w);

  /* compute covariance of best fit parameters */
  J = gsl_multifit_nlinear_jac(w);
  gsl_multifit_nlinear_covar (J, 0.0, covar);

  /* compute final cost */
  gsl_blas_ddot(f, f, &chisq);

#define FIT(i) gsl_vector_get(w->x, i)
#define ERR(i) sqrt(gsl_matrix_get(covar,i,i))

  fprintf(stderr, "summary from method '%s/%s'\n",
          gsl_multifit_nlinear_name(w),
          gsl_multifit_nlinear_trs_name(w));
  fprintf(stderr, "number of iterations: %zu\n",
          gsl_multifit_nlinear_niter(w));
  fprintf(stderr, "function evaluations: %zu\n", fdf.nevalf);
  fprintf(stderr, "Jacobian evaluations: %zu\n", fdf.nevaldf);
  fprintf(stderr, "reason for stopping: %s\n",
          (info == 1) ? "small step size" : "small gradient");
  fprintf(stderr, "initial |f(x)| = %f\n", sqrt(chisq0));
  fprintf(stderr, "final   |f(x)| = %f\n", sqrt(chisq));

  {
    double dof = n - p;
    double c = GSL_MAX_DBL(1, sqrt(chisq / dof));

    fprintf(stderr, "chisq/dof = %g\n", chisq / dof);

    fprintf (stderr, "A      = %.5f +/- %.5f\n", FIT(0), c*ERR(0));
    fprintf (stderr, "lambda = %.5f +/- %.5f\n", FIT(1), c*ERR(1));
    fprintf (stderr, "b      = %.5f +/- %.5f\n", FIT(2), c*ERR(2));
  }

  fprintf (stderr, "status = %s\n", gsl_strerror (status));

  gsl_multifit_nlinear_free (w);
  gsl_matrix_free (covar);
  gsl_rng_free (r);

  return 0;
}
