#pragma once
#include "Sequence.h"

class Output
{
private:
        Sequence seq1;
        Sequence seq2;
public:
        Output(Sequence L, Sequence R);

        void printSequenceName(Sequence seq1);

        void printSequence(Sequence seq1);

        void printSequenceLength(Sequence seq1);

        void printAlignedSequences(Sequence seq1, Sequence seq2, Sequence sequenceOneOG, Sequence sequenceTwoOG);
        
        void printIdentity();

        void printMatch();
};