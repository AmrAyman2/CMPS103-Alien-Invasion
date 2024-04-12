#include <iostream>
#include "Generator.h"
#include "Input.h"
using namespace std;

Generator::Generator(int n, int es, int et, int eg, int as, int am, int ad,int prob) {
	n = getN();
	es = getES(); et = getET(); eg = getEG();
	as = getAS(); am = getAM(); ad = getAD();
	prob = getProb();
};

void Generator :: mainFunction() {}
