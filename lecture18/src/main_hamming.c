#include <stdlib.h>
#include <unistd.h>

#include "IsingLattice2D.h"
#include "pattern.h"
#include "Jmatrix.h"
#include "neural.h"


#define SWEEP_MAX 50
#define STRIP 1



int main(int argc, char** argv) { 

  int M = argc - 1;
  int N=10;
  float T=0;


  pattern * pattern1;
  pattern * pattern2;
  

  //Input pattern load in
  FILE * fpat1  = fopen(argv[1], "r");
  pattern1 = readPatterns(&fpat1, 1, N);
  fclose(fpat1);
  printf("pattern 1: \n");
  writePattern(pattern1,stdout,STRIP);

  FILE * fpat2  = fopen(argv[2], "r");
  pattern2 = readPatterns(&fpat2, 1, N);
  fclose(fpat2);
  printf("pattern 2: \n");
  writePattern(pattern2,stdout,STRIP);

  
  double tmpHD = hammingDistance(pattern1, pattern2);
  printf("\nhammingDistance: %f\n", tmpHD);

}
