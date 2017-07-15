#include "TFile.h"
#include <algorithm> // for std::max
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
#include <iostream>
#include <fstream>
#include <string>

#include <ctime>
#include <stdlib.h>
#include "StandardRecord/StandardRecord.h"
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

        caf::StandardRecord* rec;
        tree->SetBranchAddress("rec", &rec);
        tree->SetBranchStatus("slc.nhit", 1);


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
                   ) {std::cout << rec->vtx.elastic[0].vtx.fX << std::endl;}

                //
                //         //
                // }



                //std::cout << rec->slc.nhit << std::endl;
        }
}
