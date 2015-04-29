#pragma once
#include "Sequence.h"

class Output
{
private:
        Sequence seq1;
        Sequence seq2;
        Sequence al_seq1;
        Sequence al_seq2;
public:
        Output(Sequence a, Sequence b, Sequence c, Sequence d);

        void printSequenceName(Sequence testSequence);

        void printSequence(Sequence testSequence);

        void printSequenceLength(Sequence testSequence);

        void printAlignedSequences();
        
        void printIdentity(int accuracy);

        void printMatch(char const *star);

        void printFile(string fileName);
};