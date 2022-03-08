#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

#define NSWEEPS 100000

int main(int argc, char** argv) {

  unsigned seed=strtoul(argv[1],NULL,10); 
  srand(seed);
  double T = strtod(argv[2],NULL);
  double H = strtod(argv[3],NULL);
  double spin = strtod(argv[4],NULL);

  int verbose = 0;
  if( argc == 6 && !strcmp(argv[5],"verbose") ) verbose = 1;
  
  IsingLattice2D* lattice = create2DIsingLattice( 10, 10, T, H, spin );
  
  // warm up if not wanting timeseries data ...
  if( !verbose ) { 
    for( int i=0; i<5000; i++ ) { 
      sweep( lattice, boltzmannFlip );
    }
  }

  double M=0;
  for( int i=0; i<NSWEEPS; i++ ) { 
    sweep( lattice, boltzmannFlip );
    M += getMagnetization(lattice)/NSWEEPS;
    if( verbose )
      printf( "i: %d\tM: %f\n", i, getMagnetization(lattice));
  }

  if( !verbose )
    printf( "T: %lf\tH: %lf\tM: %lf\n", T, H, M );

}
