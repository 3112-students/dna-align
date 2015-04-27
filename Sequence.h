#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Sequence {
public:
        float penalty;
        string name;
        string seq;
        
        Sequence();

        Sequence(string filename);

        Sequence(string NAME, string SEQ, float PENALTY);

        Sequence(Sequence const &Seq);

        void reed(string filename);

//        void reed(char filename[]);

        void change(string NAME, string SEQ, float PENALTY);            

        void print();

 //       void print_penalty();
};