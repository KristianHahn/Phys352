#include <stdio.h>
#include "TwoComponent.h"
#include "FourComponent.h"

/* single dependent variable */

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
    *(x+i+1) = euler_step(*(x+i), *(t+i), f, dt );
    *(t+i+1) = *(t+i) + dt;
  }
}


/* two dependent variables */
void
euler_step_2component(TwoComponent* x, double* t, double fA, double fB,  double dt) {
  (x+1)->A = x->A  + fA*dt;  
  (x+1)->B = x->B  + fB*dt;  
  *(t+1) = *t + dt;
}

void 
euler_solver_2component_fp(TwoComponent* x, double* t, 
			   double (*dxAdt)(TwoComponent*,double,double*),
			   double (*dxBdt)(TwoComponent*,double,double*),
			   double* dxdt_parameters, double dt, int steps) 
{
  int i=0; 
  for( i=0; i<steps-1; i++ ) { 
    double fA = (*dxAdt)((x+i),*(t+i),dxdt_parameters);
    double fB = (*dxBdt)((x+i),*(t+i),dxdt_parameters);
    euler_step_2component(x+i, t+i, fA, fB, dt );
  }
}



/* four dependent variables */
void
euler_step_4component(FourComponent* x, double* t, 
		      double fA, double fB, double fC, double fD,  
		      double dt) 
{
  (x+1)->A = x->A  + fA*dt;  
  (x+1)->B = x->B  + fB*dt;  
  (x+1)->C = x->C  + fC*dt;  
  (x+1)->D = x->D  + fD*dt;  
  *(t+1) = *t + dt;
}

void 
euler_solver_4component_fp(FourComponent* x, double* t, 
			   double (*dxAdt)(FourComponent*,double,double*),
			   double (*dxBdt)(FourComponent*,double,double*),
			   double (*dxCdt)(FourComponent*,double,double*),
			   double (*dxDdt)(FourComponent*,double,double*),
			   double* dxdt_parameters, double dt, int steps) 
{
  int i=0; 
  for( i=0; i<steps-1; i++ ) { 
    double fA = (*dxAdt)((x+i),*(t+i),dxdt_parameters);
    double fB = (*dxBdt)((x+i),*(t+i),dxdt_parameters);
    double fC = (*dxCdt)((x+i),*(t+i),dxdt_parameters);
    double fD = (*dxDdt)((x+i),*(t+i),dxdt_parameters);
    euler_step_4component(x+i, t+i, fA, fB, fC, fD, dt );
  }
}





