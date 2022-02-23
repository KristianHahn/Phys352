#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char ** argv) { 
  
  int i=0;
  unsigned long tmpNtot, tmpNin, numer=0, denom=0;
  unsigned long Ntrials;

  FILE * f = fopen(argv[1], "r");
  double avgX=0, avgX2=0;

  int Nsamples=0;
  while( fscanf( f, "Ntot: %lu Nin: %lu", &tmpNtot, &tmpNin ) != EOF ) { 

    numer += tmpNin;
    denom += tmpNtot;
    Ntrials = tmpNtot; // will be the same for all ...

    double tmppi = 4*((double)tmpNin/tmpNtot);
    avgX += tmppi;
    avgX2 += tmppi*tmppi;
    Nsamples++;
  } 

  avgX /= Nsamples;
  avgX2 /= Nsamples;
  float s2 = ((double)Nsamples/(Nsamples-1))*(avgX2-avgX*avgX);


  double pi = avgX;
  double err = sqrt(s2)/sqrt(Nsamples);

  printf( "Ntrials: %lu\n", Ntrials);
  printf( "Nsamples: %lu\n", Nsamples);
  printf( "numer: %lu\n", numer);
  printf( "denom: %lu\n", denom);
  printf( "s2: %.10lf\n", s2);
  printf( "s: %.10lf\n", sqrt(s2));
  printf( "s/sqrt(Nsamples): %.10lf\n", sqrt(s2)/sqrt(Nsamples));
  printf( "----------------------\n");
  printf( "pi = %.10lf +/- %.10lf\n", pi, err ); 
  printf( "estimated err [ =1.65/sqrt(denom) ]: %.10lf\n", 1.65/sqrt(denom));
  printf( "----------------------\n");


}
