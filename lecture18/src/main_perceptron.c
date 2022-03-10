#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "IsingLattice2D.h"
#include "pattern.h"
#include "Jmatrix.h"
#include "neural.h"


#define SWEEP_MAX 50
#define STRIP 1


int main(int argc, char** argv) { 

  unsigned seed = strtoul(argv[1],NULL,10);
  float randomization = strtof(argv[2],NULL);
  float damage = strtof(argv[3],NULL);

  int M = 10; // input patterns
  int N = 10; // patterns are 10x10
  int P = 2; // output patterns
  float T=0;

  char *fnames[] = { "./characters/0.dat",
		     "./characters/1.dat",
		     "./characters/2.dat",
		     "./characters/3.dat",
		     "./characters/4.dat",
		     "./characters/5.dat",
		     "./characters/6.dat",
		     "./characters/7.dat",
		     "./characters/8.dat",
		     "./characters/9.dat" };

  
  FILE ** fsin = (FILE **)calloc(M, sizeof(FILE *));
  FILE ** fsout = (FILE **)calloc(P, sizeof(FILE *));
  FILE ** ftest = (FILE **)malloc(1*sizeof(FILE *));
  pattern *inputs, *outputs;
  pattern *layer1, *layer2;


  double prevenergy = 0;
  double currenergy = -5;
  double r;
  double hamming;
  int i,j;
  

  srand(seed);

  //
  // Load input patterns
  //
  for (i = 0; i < M; i++) {
    fsin[i] = fopen(fnames[i], "r");
  }
  inputs = readPatterns(fsin, M, N);
  for (i = 0; i < M; i++) {
    fclose(fsin[i]);
  }

  //
  // Load output patterns
  //
  fsout[0] = fopen(fnames[0], "r"); // 0.dat
  fsout[1] = fopen(fnames[1], "r"); // 1.dat
  fprintf(stderr,"reading in memory pattern ...\n");
  outputs = readPatterns(fsout, P, N);
  fclose(fsout[0]);
  fclose(fsout[1]);
  
 

  
  //
  // Open test pattern
  //
  ftest[0] = fopen(argv[4], "r");
  int input_index = 0;
  for( int z=0; z<10; z++ ) { 
    if(!(strcmp(argv[4],fnames[z]) ) )
       input_index = z;
  }

  layer1 = readPatterns(ftest, 1, N);
  fclose(ftest[0]); //test pattern is loaded in by the ftest and test initialization
  clear();
  printf("input pattern : \n\n");
  writePattern(layer1, stdout, STRIP);
  sleep(1);
  clear();


  //
  // create lattices and interaction matrix, initialize
  // layer 1 to the input pattern

  Jmatrix * Jmat, *Jmatdummy;
  Jmat = createJperceptron(inputs, outputs, M, N, P);
   
  IsingLattice2D * lattice1 = create2DIsingLattice( N, N, T, 0); 
  IsingLattice2D * lattice2 = create2DIsingLattice( N, N, T, 0); 
  int sweeps = 0;

  IsingFromPattern(lattice1, layer1, Jmat);
  clear();
  
  
  
  //
  // sweep until we reach energy minumum ...
  //
  while(prevenergy != currenergy && sweeps < SWEEP_MAX) {
    printf("sweep: %d\n\n", sweeps);
    layer2 = PatternFromIsing(lattice2);
    writePattern(layer2, stdout, STRIP);
    prevenergy = getTotalEnergyPerceptron(lattice1, lattice2);
    sweepNeuralPerceptron(lattice1, lattice2, &neuralFlipPerceptron);
    currenergy = getTotalEnergyPerceptron(lattice1, lattice2);
    if (currenergy != prevenergy) {
      sweeps++;
    }
    sleep(1);
    clear();
  }  
  
  printf("%d mod 2 =  \n\n", input_index);
  layer2 = PatternFromIsing(lattice2);
  writePattern(layer2, stdout, STRIP);
  printf("\n");
  
  
}
