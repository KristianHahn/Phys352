void hist(string fname, string pngname, float sigest, int ntrial) {

  TTree * t = new TTree("t","t");
  t->ReadFile(fname.c_str());
  t->Print();

  TCanvas * c = new TCanvas("c","c",0,0,600,500);

  TH1F * h = new TH1F( "h","h", 100, 3.02, 3.25);
  t->Draw("v>>h","","goff");
  h->Draw();
  h->Fit("gaus");

  char str[512];
  sprintf(str,"estimated std: %f",sigest/sqrt(ntrial));
  h->SetTitle(str);



  c->Print(pngname.c_str());
}
