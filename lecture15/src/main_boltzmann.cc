#include <stdio.h>
#include <limits>
#include <vector>
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"

#define kB 1.

int boltzmann(double E, double T) { 
  double fB = exp(-E/(kB*T));
  double rval = (double)rand()/RAND_MAX;
  if( rval <= fB ) 
    return 1; 
  return 0;
}

int main(int argc, char ** argv) { 
  
  std::vector<double> Tvec( {5.0, 10.0, 25.0, 50.0});
  std::vector<EColor> cvec( {kBlack, kRed, kBlue, kViolet});
  std::vector<TH1F*> hvec;

  unsigned seed = strtoul(argv[1],NULL,10);

  srand(seed);

  printf("looping over %d entries\n", Tvec.size());
  for(int k=0; k<Tvec.size(); k++ ) { 
    char str[256];
    sprintf(str,"h_%d", k);
    hvec.push_back(new TH1F( str, str, 50,0,50));
    double E=0.1;
    for( int j=0; j<1000; j++ ) { 
      for( int i=0; i<100000; i++ ) { 
	if( boltzmann(E,Tvec[k]) )
	  hvec[k]->Fill(E);
      }
      E += 0.2;
    }
    hvec[k]->SetLineColor(cvec[k]);
    hvec[k]->Scale(1./hvec[k]->GetEntries());
  }


  TCanvas * c = new TCanvas("c","c",0,0,600,500);
  TH1F * frame = (TH1F*)c->DrawFrame( 0,0,50,1.2*hvec[0]->GetMaximum());
  frame->GetXaxis()->SetTitle("Energy");
  frame->GetYaxis()->SetTitle("Probability");

  for( int k=0; k<hvec.size(); k++ ) { 
    hvec[k]->SetLineColor(cvec[k]);
    hvec[k]->Draw("hsame");
  }

  TLegend * l = new TLegend(0.65,0.65,0.89,0.89);
  l->SetFillColor(0);
  l->SetBorderSize(0);
  l->AddEntry( hvec[0], "T =  5.0", "l");
  l->AddEntry( hvec[1], "T = 10.0", "l");
  l->AddEntry( hvec[2], "T = 25.0", "l");
  l->AddEntry( hvec[3], "T = 50.0", "l");
  l->Draw("same");

  c->Print("img/boltzmann.png");

}




