#include <stdio.h>

main() { 

  float tempF, tempC;

  printf("\n\nEnter temperature (F): "  );
  scanf("%f", &tempF );

  tempC = (tempF - 32.)*(5./9.);
  printf( "Temperature (C): %.1f\n", tempC);

}
