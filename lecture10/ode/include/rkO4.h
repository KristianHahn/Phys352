#include "TwoComponent.h"
#include "FourComponent.h"

/* for a single dependent variable */
double rkO4_step(double x, double t, double f, double dt);

void rkO4_solver(double* x, double* t, double dt, int steps);

void rkO4_solver_fp(double* x, double* t, double (*dxdt)(double,double,double*), 
		     double* dxdt_parameters, double dt, int steps);

/* for two dependent variables */
double rkO4_step_2component(TwoComponent* x, double t, double f1, double f2, double dt);

void rkO4_solver_2component_fp(TwoComponent* x, double* t, 
				double (*dxAdt)(TwoComponent*,double,double*), 
				double (*dxBdt)(TwoComponent*,double,double*), 
				double* dxdt_parameters, 
				double dt, int steps);


void rkO4_solver_2component_anglewrap_fp(TwoComponent* x, double* t, 
					 double (*dxAdt)(TwoComponent*,double,double*), 
					 double (*dxBdt)(TwoComponent*,double,double*), 
					 double* dxdt_parameters, 
					 double dt, int steps);



/* four dependent variables */
void rkO4_step_4component(FourComponent* x, double* t, 
			   double fA, double fB, double fC, double fD,  
			   double dt); 

void rkO4_solver_4component_fp(FourComponent* x, double* t, 
				double (*dxAdt)(FourComponent*,double,double*),
				double (*dxBdt)(FourComponent*,double,double*),
				double (*dxCdt)(FourComponent*,double,double*),
				double (*dxDdt)(FourComponent*,double,double*),
				double* dxdt_parameters, double dt, int steps) ;
