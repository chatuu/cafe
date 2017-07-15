#include <TH2.h>
#include "TFile.h"
#include "TTree.h"
#include "TVector3.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "TLorentzVector.h"
#include <vector>
#include <iomanip>
#include "TMath.h"
#include "TError.h"
#include <math.h>
#include "TApplication.h"
#include "TSystem.h"
#include "TRint.h"
#include "Cintex/Cintex.h"

//gSystem->Load("libCintex.so");
//Cintex::Enable();
//gSystem->Load("$SRT_PUBLIC_CONTEXT/lib/Linux2.6-GCC-debug/libStandardRecord_dict.so");


int main(int argc, char **argv)
{
   gSystem->Load("libCintex.so");
   Cintex::Enable();
   gSystem->Load("$SRT_PUBLIC_CONTEXT/lib/Linux2.6-GCC-debug/libStandardRecord_dict.so");

  TApplication theApp("tapp", &argc, argv);
  TFile* file = new TFile("/nova/ana/caf/genie_vs_nuwro_nue.root", "READ");
  TTree* tree = (TTree*)file->Get("genie");
  //tree->Draw("Ev");
  TCanvas *c1=new TCanvas("c1");
   tree->Draw("Ev:x","","colz");
   c1->Update();
   theApp.Run();
   return 0;


}
