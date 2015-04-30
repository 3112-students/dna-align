#pragma once
#include <vector>
#include "Sequence.h"
#include "Matrix.h"

class Score : public Matrix {
private:
        float max(float a, float b, float c);
public:
        vector<vector <float> > array;

        Score(Sequence seq1, Sequence seq2);

        void print();

        void into_file(string FN); 
};