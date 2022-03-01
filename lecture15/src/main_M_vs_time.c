#include <stdio.h>
#include <stdlib.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

#define NSWEEPS 100000

int main(int argc, char** argv) {

  unsigned seed=strtoul(argv[1],NULL,10); 
  srand(seed);
  double T = strtod(argv[2],NULL);
  double H = strtod(argv[3],NULL);

  IsingLattice2D* lattice = create2DIsingLattice( 10, 10, T, H );
  
  double M=0;
  for( int i=0; i<NSWEEPS; i++ ) { 
    sweep( lattice, boltzmannFlip );
    printf("i: %d\tM: %f\n", i, getMagnetization(lattice));
  }


}
