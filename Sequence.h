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

        Sequence(char const *seqName, string fileName);

        Sequence(string NAME, string SEQ);

        Sequence(string NAME, string SEQ, double PENALTY);

        Sequence(Sequence const &Seq);

        void change(string NAME, string SEQ, double PENALTY);            

        void print();

};