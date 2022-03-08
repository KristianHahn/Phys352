#include <stdio.h>
#include <stdlib.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

int main(int argc, char** argv) {

  unsigned seed=strtoul(argv[1],NULL,10); 
  srand(seed);
  double T = strtod(argv[2],NULL);
  double H = strtod(argv[3],NULL);

  IsingLattice2D* lattice = create2DIsingLattice( 20, 20, T, H );
  
  int i;

  for( i=0; i<1000; i++ ) { 
    sweep( lattice, boltzmanFlip );
  }

  printf("here we go ...\n");

  double M=0;
  for( i=0; i<200; i++ ) { 

    sweep( lattice, boltzmanFlip );


    /* take a snapshot */
    char fname[256];
    sprintf(fname, "timeseries_T_%.2f/lattice_%d.dat", T, i);
    FILE * f = fopen(fname, "w");
    for( int j=0; j<200; j++ ){
      for( int k=0; k<200; k++ ){
	fprintf( f,"%d\t%d\t%f\n", j, k, lattice->spinarray[j][k].spin);
      }
    }
    fclose(f);



  }




}
