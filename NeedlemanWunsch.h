#pragma once
#include "Traceback.h"

class NeedlemanWunsch {

private:
        Sequence seq1;
        Sequence seq2;

        string shortened(string DNA);

public:        
        NeedlemanWunsch(Sequence SEQ1, Sequence SEQ2);

        void align(Sequence &al_seq1, Sequence &al_seq2);

        void printSeq();                        // нет в новой редакции!

        void printTraceback();                  // по идее тоже не нужны, так как уже есть в output

        void printScore();

        void score_intofile(string filename);   

        void traceback_intofile(string filename);
};