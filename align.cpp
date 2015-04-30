#include "NeedlemanWunsch.h"
#include "Output.h"
#include "Input.h"

int main(int argc, char const *argv[])
{
        Sequence seq1, seq2, al_seq1, al_seq2;
        
        Input Inp(argc, argv);
        Inp.viewSequence(); 
        Inp.readSequence(seq1, seq2);

        NeedlemanWunsch Alg(seq1, seq2);
        Alg.align(al_seq1, al_seq2);

        Output Out(seq1, seq2, al_seq1, al_seq2);
        Out.printFile("aligned.txt");
        /*
        Out.printAlignedSequences(); // Print into terminal

        if (strcmp(argv[i], "--match") == 0)
        {
                Out.printMatch(argv[i+1]);
        }
        if (strcmp(argv[i], "--identity") == 0)
        {
                Out.printIdentity(atoi(argv[i+1])); 
        } 
        */

        return 0;
}