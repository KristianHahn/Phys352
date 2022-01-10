#include <stdio.h>
#include "conversion.h"

main() { 

  float highF, avgF, lowF;
  float highC, avgC, lowC;
  int month, day, year;

  FILE * input  = fopen("./data/chicago_temps_2012.csv", "r");
  FILE * output = fopen("./data/chicago_tempsC_2012.csv", "w+"); 

  /* throw away the first line of text, 
     star means 'don't assign to a variable'  */
  fscanf( input, "%*s" );

  while( fscanf( input, 
		 "%d-%d-%d,%f,%f,%f", 
		 &year, &month, &day,  &highF, &avgF, &lowF) 
	 != EOF ) { 
    
    highC = convertToC(highF);
    avgC  = convertToC(avgF);
    lowC  = convertToC(lowF);
    
    fprintf( output, 
	     "%d.%d.%d,%.0f,%.0f,%.0f\n", 
	     month, day, year, highC, avgC, lowC);
  }

  fclose(output);
  fclose(input);

}

#include "conversionImpl.h"
