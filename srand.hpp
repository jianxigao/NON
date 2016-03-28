/* random number genertator using 'mzran' algorithm,
   srand() generates a random number in the range [0,1).
   initsrand(w) reads 4 integer seed from 'seed.dat',
   and writes new random seeds to the same file if w!=0. */
#ifndef SRAND_HPP
#define SRAND_HPP
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

static int iir,jjr,kkr,nnr,mzran;

double srand() {
  mzran=iir-kkr;
  if (mzran < 0)  mzran=mzran+2147483579;
  iir=jjr; jjr=kkr; kkr=mzran;
  nnr=69069*nnr+1013904243;
  mzran=mzran+nnr;
  return 0.5e0+mzran*0.23283064e-9;
}

void initsrand(int w) {
  ifstream seed_in("seed.dat");
  if( !seed_in ) {
    cerr << "'seed.dat' could not be found." << endl;
    exit( 1 );
  }
  seed_in >> iir >> jjr >> kkr >> nnr;
  seed_in.close();
  iir=abs(iir)+1; jjr=abs(jjr)+1; kkr=abs(kkr)+1;
  if (w!=0) {
    ofstream seed_out("seed.dat");
    seed_out << abs(static_cast<int>((srand()-0.5e0)/0.23283064e-9)) << endl
	     << abs(static_cast<int>((srand()-0.5e0)/0.23283064e-9)) << endl
	     << abs(static_cast<int>((srand()-0.5e0)/0.23283064e-9)) << endl
	     << abs(static_cast<int>((srand()-0.5e0)/0.23283064e-9)) << endl;
    seed_out.close();
  }
}

#endif
