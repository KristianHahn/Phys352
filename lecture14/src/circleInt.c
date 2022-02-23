#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int main( int argc, char ** argv ) { 

  if( argc < 3 ) { 
    printf("usage: circleInt.exe <Npts> <seed>\n");
    return -1;
  }

  int is_it_in=0;
  unsigned long i;
  unsigned long Npts = strtoul(argv[1],  NULL, 10);
  unsigned long seed = strtoul(argv[2], NULL, 10);
  unsigned long Ninside = 0;

  /* set the random seed */
  srand(seed);
  
  for( i=0; i<Npts; i++ ) { 
    float x = (float)rand()/RAND_MAX;
    float y = (float)rand()/RAND_MAX;
    is_it_in=0;
    if( y < sqrt(1.-x*x) ) {
      Ninside++;
      is_it_in=1;
    }
#ifdef VERBOSE
    printf( "%f\t%f\t%d\n", x, y, is_it_in);
#endif
  }
  printf( "# Npts : %lu\n", Npts);
  printf( "# Ninside : %lu\n", Ninside);
  printf( "# Area : %lf\n", (double)Ninside/Npts);
  printf( "# 4Area : %lf\n", 4*(double)Ninside/Npts);

  return 0;

}
