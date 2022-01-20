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

