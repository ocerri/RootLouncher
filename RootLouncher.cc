#include<TFile.h>
#include<TBrowser.h>
#include<TString.h>

#include<iostream>
#include<vector>

void RootLouncher(TString fpath){
  cout << "\n\nFile: " << fpath.Data() << endl;
  auto f = new TFile(fpath);

  TIter next(f->GetListOfKeys());
  TKey* key;
  int nk=0;
  int ncanvases = 0;
  int n_noncanvases = 0;
  vector<TKey*> key_vec;
  while ( (key = (TKey*)next()) ) {
    nk++;
    cout << Form("Key %d: %s \"%s\" ", nk, key->GetClassName(), key->GetTitle() ) << endl;
    if( key->GetClassName() == TString("TCanvas") ){
      ncanvases++;
      if (ncanvases < 4) {
        auto c = (TCanvas*) f->Get(key->GetName());
        c->Draw();
      }
    }
    else n_noncanvases++;
  }

  if(ncanvases >= 4 || n_noncanvases > 0) new TBrowser;
}

// int main (int argc, char *argv[]){
//   std::cout << "Running\n" << argv[1] << std::endl;
//   RootLouncher(argv[1]);
//  }
