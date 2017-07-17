#include "TFile.h"
//#include <algorithm> // for std::max
#include <iomanip>
#include "THStack.h"
#include "TCut.h"
#include "TH1.h"

#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TTree.h"
#include <TROOT.h>
#include <TStyle.h>
#include "TLegend.h"
//#include <iostream>
//#include <fstream>
//#include <string>

#include <ctime>
#include <stdlib.h>
#include "StandardRecord/StandardRecord.h"


#include "TApplication.h"
#include "TSystem.h"
#include "TRint.h"
#include "Cintex/Cintex.h"


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;



//#include "StandardRecord.h"

//gSystem->Load("libCintex.so");
//Cintex.Enable()
//gSystem.Load("$SRT_PUBLIC_CONTEXT/lib/Linux2.6-GCC-debug/libStandardRecord_dict.so")
//gInterpreter.AddIncludePath("$SRT_PUBLIC_CONTEXT")

void test01macro(){

        TFile* file=new TFile("/nova/ana/users/mylab/prod/decaf/0522a_numu/0/0/8/neardet_r00010910_s08_t00_S15-05-22a_v1_data_numu_contain.decaf.root","read");
//file->ls();
        TTree* tree=(TTree*) file->Get("recTree");
//tree->Scan();
        TCanvas* c1=new TCanvas("c1","X-Vertex position",1024,768);
        //TCanvas* c2=new TCanvas("c2","Y-Vertex position",1024,768);


        TH1F* h0=new TH1F("h0","X-Vertex Position",50,-140,140);
        TH1F* h1=new TH1F("h1","Y-Vertex Position",50,-140,140);
        TH1F* h2=new TH1F("h2","Z-Vertex Position",100,50,1200);
        TH1F* h3=new TH1F("h3","slc.nhit",50,20,250);
        TH1F* h4=new TH1F("h4","slc.calE",50,0,3.5);
        TH1F* h5=new TH1F("h5","trk.kalman.len",100,-20,420);


        caf::StandardRecord* rec;
        tree->SetBranchAddress("rec", &rec);
        //tree->SetBranchStatus("slc.nhit", 1);


        for(int i = 0; i< tree->GetEntries(); ++i)
        {
                tree->GetEntry(i);

                if(rec->trk.nkalman>0&&
                   rec->energy.numusimp.E>0&&
                   rec->sel.remid.pid>0&&
                   rec->vtx.nelastic>0&&
                   rec->slc.nhit>20&&
                   rec->slc.ncontplanes>4&&
                   rec->trk.ncosmic>0&&
                   rec->sel.remid.pid>0.75&&
                   abs(rec->vtx.elastic[0].vtx.fX)<140&&
                   abs(rec->vtx.elastic[0].vtx.fY)<140&&
                   rec->vtx.elastic[0].vtx.fZ<1200&&
                   rec->vtx.elastic[0].vtx.fZ>50
                   ) {


                        //std::cout << rec->vtx.elastic[0].vtx.fX << std::endl;

                        h0->Fill(rec->vtx.elastic[0].vtx.fX);
                        h1->Fill(rec->vtx.elastic[0].vtx.fY);
                        h2->Fill(rec->vtx.elastic[0].vtx.fZ);
                        h3->Fill(rec->slc.nhit);
                        h4->Fill(rec->slc.calE);

                        //std::cout<<rec->trk.nkalman<<std::endl;
                        for(Int_t k=0; k<rec->trk.nkalman; ++k) {

                                h5->Fill(rec->trk.kalman[k+1].len);
                        }
//std::cout<<rec->trk.kalman[1].len<<std::endl;

                }


                //gStyle->SetOptStat(kTRUE);
                c1->cd();
                h5->Draw();
                //  TCanvas* c2=new TCanvas("c2","Y-Vertex position",1024,768);
                //c2->cd();
                //h1->Draw();

                //
                //         //
                // }



                //std::cout << rec->slc.nhit << std::endl;
        }
}
