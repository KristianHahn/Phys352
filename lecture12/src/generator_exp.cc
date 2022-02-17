#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <limits>

#include "TCanvas.h"
#include "TGraph.h"
#include "TRandom3.h"

#define NBINS 500

using namespace std;



int main(int argc, char ** argv) { 

  const float Ab = 15000; 
  const float tau = -20; 
  const float sigma = 50.0; 

  TRandom3 r(strtol(argv[1], NULL, 10 ));
  
  vector <float> x, y;
  for( int i=0; i<NBINS; i++ ) { 
    float tmpx = ((float)i/NBINS)*100;
    float tmpy = r.Gaus( Ab*exp(tmpx/tau), sigma);
    x.push_back(tmpx);
    y.push_back(tmpy);
    cout << "x: " << tmpx << "\t" 
	 << "y: " << tmpy << "\t"
	 << "w: " << 1 << endl;
  }
  

  TGraph * g = new TGraph( NBINS, &(x[0]), &(y[0])); 
  
  TCanvas * c = new TCanvas("c","c", 0, 0, 500, 300);
  g->Draw("APC");
  c->Print("exp.png");


}
