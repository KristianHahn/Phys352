#include <math.h>
#include "TwoComponent.h"
#include "FourComponent.h"

/*

  Dragless

*/

double fx(TwoComponent* x, double dt, double* parameters  ) {
  double fval = x->B;
  return fval;
}

double fvx(TwoComponent* x, double dt, double* parameters  ) {
  return 0.;
}

double fy(TwoComponent* x, double dt, double* parameters  ) {
  double fval = x->B;
  return fval;
}

double fvy(TwoComponent* x, double dt, double* parameters  ) {
  double fval = -parameters[0]; /* ie: -g */
  return fval;
}


/*

  With drag

*/

double fx_drag(FourComponent* x, double dt, double* parameters  ) {
  double fval = x->B;
  return fval;
}

double fvx_drag(FourComponent* x, double dt, double* parameters  ) {
  /* - B2*v/m */
  double fval = -parameters[1]*sqrt(x->B*x->B + x->D*x->D)*x->B;
  return fval;
}

double fy_drag(FourComponent* x, double dt, double* parameters  ) {
  double fval = x->D;
  return fval;
}

double fvy_drag(FourComponent* x, double dt, double* parameters  ) {
  /* -g - B2*v/m */
  double fval = -(parameters[0] + parameters[1]*sqrt(x->B*x->B + x->D*x->D)*x->D); 
  return fval;
}


/*

  With altitude-dependent drag

*/

double fvx_drag_adiabatic(FourComponent* x, double dt, double* parameters  ) {
  /* - (B2*v/m)*(1- ay/T0)^alpha */
  double fval = -parameters[1]*sqrt(x->B*x->B + x->D*x->D)*x->B*pow((1.-(parameters[2]*x->C/parameters[3])),
								    parameters[4]);
  return fval;
}

double fvy_drag_adiabatic(FourComponent* x, double dt, double* parameters  ) {
  /* -g - (B2*v/m)*(1- ay/T0)^alpha */
  double fval = -(parameters[0] + 
		  parameters[1]*sqrt(x->B*x->B + x->D*x->D)*x->D*pow((1.-(parameters[2]*x->C/parameters[3])),
								     parameters[4])); 
  return fval;
}


