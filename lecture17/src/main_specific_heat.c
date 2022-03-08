#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

#define NSWEEPS 20000

int main(int argc, char** argv) {

  unsigned seed=strtoul(argv[1],NULL,10); 
  double T = strtod(argv[2],NULL);
  double H = strtod(argv[3],NULL);
  int size = strtoul(argv[4],NULL,10);

  srand(seed);

  IsingLattice2D* lattice = create2DIsingLattice( size, size, T, H );

  // warm up
  int i;
  for( i=0; i<1000; i++ ) { 
    sweep( lattice, boltzmannFlip );
  }

  double E=0, E2=0;
  for( i=0; i<NSWEEPS; i++ ) { 
    sweep( lattice, boltzmannFlip );
    E  += getEnergyPerSpin(lattice)/NSWEEPS;
    E2 += getEnergySquaredPerSpin(lattice)/NSWEEPS;
  }

  printf("E2: %f\tE*E: %lf\n", E2, E*E);
  double s2 = E2 - (size*size*E*E); 
  double C  = s2/(T*T);

  printf( "T: %lf\tC: %lf\n", T, C );

}
