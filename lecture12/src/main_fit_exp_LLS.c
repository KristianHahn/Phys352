#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct { 
  double a, bprime;
} linearStruct;

void linearFit( double * x, double * y, int N, linearStruct * s ) { 
  int i=0;
  double avg_x=0, avg_y=0, avg_xy=0, avg_xx=0;
  for( ; i<N; i++ ) {
    avg_x += *(x+i);
    avg_y += *(y+i);
    avg_xy += *(y+i) * *(x+i);
    avg_xx += *(x+i) * *(x+i);
  }
  avg_x /= N;
  avg_y /= N;
  avg_xy /= N;
  avg_xx /= N;

  s->a = (avg_xy - avg_x*avg_y)/(avg_xx - avg_x*avg_x);
  s->bprime = (avg_xx*avg_y - avg_x*avg_xy)/(avg_xx - avg_x*avg_x);
}


int main(int argc, char** argv) { 


  char * fname = argv[1];
  int N = strtoul(argv[2],NULL,10);


  linearStruct s;
  double * x = malloc(N*sizeof(double));
  double * y = malloc(N*sizeof(double));
  double * w = malloc(N*sizeof(double));


  double tmpx, tmpy, tmpw;
  FILE * f = fopen(fname, "r");
  int i=0;
  while( fscanf(f, "x: %lf\ty: %lf\tw: %lf\n", &tmpx, &tmpy, &tmpw ) != EOF ){ 
    x[i] = tmpx;
    y[i] = log(tmpy);
    printf( "x: %lf\tlog(Y): %lf\ty: %lf\n", x[i], y[i], tmpy );
    i++;
  }

  linearFit(x,y,N,&s);

  printf("B_1: %f\n", s.a);
  printf("B_0': %f\n", s.bprime);
  printf("\tB_0: %f\n", exp(s.bprime));
  

}
