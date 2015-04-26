#include "NeedlemanWunsch.h"
#include "Output.h"

/*
int main() {
        cout<<endl;
        Sequence seq1("DNA1.txt");
        Sequence seq2("DNA2.txt");
        Sequence al_seq1;
        Sequence al_seq2;
        NeedlemanWunsch Alg(seq1, seq2);
        Alg.align(al_seq1, al_seq2);
        Alg.printSeq();
//      Alg.print_score();
//      Alg.print_traceback();
//      Alg.traceback_intofile("route.txt");
//      Alg.score_intofile("table.txt");
        al_seq1.print();
        al_seq2.print();
        cout<<endl;

        return 0;
}
*/

int main() {
        Sequence seq1("DNA1.txt"); Sequence seq2("DNA2.txt");

        Sequence al_seq1; Sequence al_seq2;

        NeedlemanWunsch Alg(seq1, seq2);

        Alg.align(al_seq1, al_seq2);

        Output Out(al_seq1, al_seq2);

        Out.printAlignedSequences(al_seq1, al_seq2, seq1, seq2);
        Out.printMatch();
        Out.printIdentity();
        
        return 0;
}