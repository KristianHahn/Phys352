#include <stdio.h>
#include <stdlib.h>
#include "IsingLattice2D.h"

int main(int argc, char** argv) {

  unsigned seed=strtoul(argv[1],NULL,10); 
  srand(seed);
  double T = strtod(argv[2],NULL);
  double H = strtod(argv[3],NULL);

  IsingLattice2D* lattice = create2DIsingLattice( 10, 10, T, H );
  initialize2DSpinsRandom( lattice, seed);  
  dumpLattice(lattice);

}
