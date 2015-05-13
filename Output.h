#pragma once
#include "Sequence.h"

class Output {
private:
        Sequence seq1;
        Sequence seq2;
        Sequence al_seq1;
        Sequence al_seq2;
public:
        Output(Sequence a, Sequence b, Sequence c, Sequence d);
        void printMatch();
        void printIdentity(int accuracy);
        void printAlignedSequences();
        float getIdentity();
        int getSequenceLength(Sequence al_seq1);
        void printFile(int accuracy, string fileName);
};