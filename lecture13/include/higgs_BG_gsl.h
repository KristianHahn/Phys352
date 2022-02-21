#define N      60    /* number of data points to fit */
#define TMAX   (159.5)  /* time variable in [0,TMAX] */
#define NPARAM 3
#define BIN_OFFSET 100.

struct data {
  size_t n;
  double * t;
  double * y;
};

int bg_exp_f (const gsl_vector * x, void *data, gsl_vector * f);
int bg_exp_df (const gsl_vector * x, void *data, gsl_matrix * J);
