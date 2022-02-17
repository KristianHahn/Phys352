#include <stdio.h>
#define ARRAY_SIZE 512

typedef struct { 
  float a, b;
} linearStruct;

void linearFit( float * x, float * y, int N, linearStruct * s ) { 
  int i=0;
  float avg_x=0, avg_y=0, avg_xy=0, avg_xx=0;
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
  s->b = (avg_xx*avg_y - avg_x*avg_xy)/(avg_xx - avg_x*avg_x);
}


int main() { 
  int N=0;
  linearStruct s;
  float x[ARRAY_SIZE], y[ARRAY_SIZE];

  FILE * f = fopen("idata/linear.dat", "r");
  while( fscanf(f, "%f\t%f", x+N, y+N ) != EOF ){ 
    N++;
    if( N >= ARRAY_SIZE ) { 
      printf("too much data, truncating ...\n");
      break;
    } 
  }

  linearFit(x,y,N,&s);

  printf("a: %f\n", s.a);
  printf("b: %f\n", s.b);
  

}
