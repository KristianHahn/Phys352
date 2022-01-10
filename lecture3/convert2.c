#include <stdio.h>

main() { 

  float highF, avgF, lowF;
  float highC, avgC, lowC;
  int month, day, year;

  FILE * input  = fopen("chicago_temps_2012.csv", "r");
  FILE * output = fopen("chicago_tempsC_2012.csv", "w+"); 

  /* throw away the first line of text, 
     star means 'don't assign to a variable'  */
  fscanf( input, "%*s" );

  while( fscanf( input, 
		 "%d-%d-%d,%f,%f,%f", 
		 &year, &month, &day,  &highF, &avgF, &lowF) 
	 != EOF ) { 
    
    highC = (highF  - 32.)*(5./9.); 
    avgC = (avgF  - 32.)*(5./9.); 
    lowC  = (lowF - 32.)*(5./9.); 
    
    fprintf( output, 
	     "%d.%d.%d,%.0f,%.0f,%.0f\n", 
	     month, day, year, highC, avgC, lowC);
  }

  fclose(output);
  fclose(input);

}
