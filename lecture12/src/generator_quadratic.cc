#include <iostream>
#include <vector>
#include <stdlib.h>


#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TRandom3.h"
#include "TH1F.h"
#include "TF1.h"

using namespace std;

int main(int argc, char ** argv) { 

  const float mu = 0.5; 
  const float sigma = 1.5; 

  TH1F * h = new TH1F("h","h",200, -4, 4);

  TF1 * gaus = (TF1*) gROOT->GetFunction("gaus");
  gaus->SetParameter("Mean",  mu);
  gaus->SetParameter("Sigma", sigma);

  h->FillRandom( "gaus", 750000);

  vector <float> x, y;
  for( int i=1; i<=200; i++ ) { 
    float tmpx = h->GetBinCenter(i);
    float tmpy = h->GetBinContent(i);
    x.push_back(tmpx);
    y.push_back(tmpy);
    cout <<  tmpx << "\t" << tmpy << endl;
  }
  

 
  TCanvas * c = new TCanvas("c","c", 0, 0, 500, 300);
  h->Draw();
  c->Print("quadratic.png");

}
