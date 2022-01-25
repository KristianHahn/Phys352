#include <math.h>

double mpi_to_pi(double x) { 
  while (x >= M_PI) x -= 2*M_PI;
  while (x < -M_PI) x += 2*M_PI;
  return x;
}
