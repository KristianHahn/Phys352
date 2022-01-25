#include <stdio.h>
#include "TwoComponent.h"

double 
f(double N, double dt, double* parameters  ) {
  double fval = -N/parameters[0];
  return fval;
}

double 
fA(TwoComponent* n, double dt, double* parameters  ) {
  double fval = -(n->A/parameters[0]) + (n->B/parameters[1]);
  return fval;
}
double 
fB(TwoComponent* n, double dt, double* parameters  ) {
  double fval = -(n->B/parameters[1]) + (n->A/parameters[0]);
  return fval;
}
