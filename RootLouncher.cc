#include<TFile.h>
#include<TBrowser.h>
#include<TString.h>

#include<iostream>

void RootLouncher(TString fpath){
  auto f = new TFile(fpath);
  f->ls();
  new TBrowser;
}

// int main (int argc, char *argv[]){
//   std::cout << "Running\n" << argv[1] << std::endl;
//   RootLouncher(argv[1]);
//  }
