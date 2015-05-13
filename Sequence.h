#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Sequence {
public:
        double penalty;
        string name;
        string seq;
        
        Sequence();

        Sequence(string seqName, string fileName);

        Sequence(Sequence const &Seq);

        void change(string NAME, string SEQ, double PENALTY);            

        void print();
};