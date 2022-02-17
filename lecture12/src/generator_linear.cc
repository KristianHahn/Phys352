#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

#include "TCanvas.h"
#include "TGraph.h"
#include "TRandom3.h"

#define NBINS 500

using namespace std;



int main(int argc, char ** argv) { 

  const float a = 3.3; 
  const float b = 1.2; 
  const float sigma = 50.0; 

  TRandom3 r(strtol(argv[1], NULL, 10 ));
  
  vector <float> x, y;
  for( int i=0; i<NBINS; i++ ) { 
    float tmpx = ((float)i/NBINS)*100;
    float tmpy = r.Gaus( a*tmpx + b, sigma);
    x.push_back(tmpx);
    y.push_back(tmpy);
//    cout <<  tmpx << "\t" << tmpy << "\t" << sqrt(tmpx)*sqrt(tmpy) << endl;
    cout <<  tmpx << "\t" << tmpy << endl;
  }
  

  TGraph * g = new TGraph( NBINS, &(x[0]), &(y[0])); 
  
  TCanvas * c = new TCanvas("c","c", 0, 0, 500, 300);
  g->Draw("APC");
  c->Print("linear.png");

}
