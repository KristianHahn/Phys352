#define N      60    /* number of data points to fit */
#define TMAX   (159.5)  /* time variable in [0,TMAX] */

#define BIN_OFFSET 100

#define NPARAMS 6


struct data {
  size_t n;
  double * t;
  double * y;

};

int gaus_exp3_f (const gsl_vector * x, void *data, gsl_vector * f);
int gaus_exp3_df (const gsl_vector * x, void *data, gsl_matrix * J);
