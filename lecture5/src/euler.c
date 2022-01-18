#include <stdio.h>

double 
euler_step(double x, double t, double f, double dt) {
  return x + f*dt; 
}


void 
euler_solver(double* x, double* t, double dt, int steps) {
  const float tc = 1.;
  int i=0; 
  for( i=0; i<steps-1; i++ ) { 
    double f = -1 * *(x+i)/tc;  /* hard-coded for exponential */
    *(x+i+1) = euler_step(*(x+i), 0, f, dt ); /* 2nd arg not needed */
  }
}

void 
euler_solver_fp(double* x, double* t, double (*dxdt)(double,double,double*), 
		double* dxdt_parameters, double dt, int steps) {
  int i=0; 
  for( i=0; i<steps-1; i++ ) { 
    double f = (*dxdt)(*(x+i),dt,dxdt_parameters); /* now for generic func */
/*     printf("f: %f\n", f); */
    *(x+i+1) = euler_step(*(x+i), *(t+i), f, dt );
    *(t+i+1) = *(t+i) + dt;
  }
}

double 
f(double N, double dt, double* parameters  ) {
  double fval = -N/parameters[0];
/*   printf("returning %f\n", fval ); */
  return fval;
}
