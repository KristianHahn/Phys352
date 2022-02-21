#define N      60    /* number of data points to fit */
#define TMAX   (159.5)  /* time variable in [0,TMAX] */
#define BIN_OFFSET 100

/* best-fit values from BG-only exp fit */
/*
Ab     = 1526.67690 +/- 32711827088299292.00000
tau    = -20.34237 +/- 0.34487
x0     = 102.10658 +/- 435872312452599.87500
*/
#define BG_AB  1526.67690 
#define BG_TAU -20.34237 
#define BG_X0  102.10658
// nparams for signal 
#define NPARAMS 3     


struct data {
  size_t n;
  double * t;
  double * y;
};

int gaus_fixedExp_f (const gsl_vector * x, void *data, gsl_vector * f);
int gaus_fixedExp_df (const gsl_vector * x, void *data, gsl_matrix * J);
