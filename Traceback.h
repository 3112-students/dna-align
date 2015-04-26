#pragma once
#include "Score.h"

class Traceback : public Matrix {
private:
        int num_max(float a, float b, float c);

        char slash(int num);
public:
        vector<vector <char> > array;

        Traceback(Sequence seq1, Sequence seq2);

        void print();

        void into_file(string file_name);
};