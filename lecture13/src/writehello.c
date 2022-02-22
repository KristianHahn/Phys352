#include <stdio.h>
int main(int argc, char ** argv ) {
  int i;
  printf("I was called as follows: ");
  for( i=0; i<argc; i++ ) {
    printf("%s ", argv[i] );
  }
  printf("\n");
  if( argc<3 ) {
    printf("too few arguments, quitting\n");
    return -1;
  }
  char fname[512];
  sprintf( fname, "%s/%s.dat", argv[2], argv[1] );
  FILE * f = fopen(fname, "w");
  fprintf(f, "hello from job %s\n", argv[1]);
  fclose(f);
  return 0;
}
