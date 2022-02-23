#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) { 

  if( argc < 4 ) { 
    printf("usage: avg_and_std.exe <filename> <Nsamples> <Ntrials>\n");
    return -1;
  }

  FILE * f = fopen(argv[1],"r"); /* area_all.dat */
  unsigned long Nsample=strtoul(argv[2],NULL,10); /* 500 */
  unsigned long Ntrial=strtoul(argv[3],NULL,10); /* 10000000000 */

  double tmpA;
  double avgx=0., avgxx=0., s2=0.;


  /*
    calculate the avg & std of the sample means.
    The distribution of sample means should be distributed
    as a Gaussian centered on the population mean and with 
    variance = ns^{2}
   */
  int i=0;
  while( fscanf(f,"%lf", &tmpA) != EOF && i<Nsample) {
    avgx += tmpA;
    avgxx += tmpA*tmpA;
    i++;
    #ifdef VERBOSE
    printf( "A: %lf \tavgx: %lf \tavgx*avgx: %lf \tavgxx: %lf\n", tmpA, avgx/i, (avgx*avgx)/(i*i), avgxx/i);
    #endif
  }

  avgx /= i;
  avgxx /= i;


  s2 = ((double)Ntrial/(Ntrial-1)) * (avgxx - avgx*avgx);

  printf("avg(xbar): %.10lf\n", avgx); 
  printf("s^2(xbar): %.10lf\n", s2);
  printf("--------------------\n");
  double sigma = sqrt(Ntrial*s2);
  printf("sigma (estimate): %lf\n", sigma);
    
}
