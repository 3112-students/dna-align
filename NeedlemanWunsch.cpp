#include "NeedlemanWunsch.h"

string NeedlemanWunsch::shortened(string DNA) {
        for (int i=0; i<DNA.length(); i++) {
                if (DNA[i] == '0') {
                        DNA.erase(i, 1);
                        i--;
                }
        }
        return DNA;
}

NeedlemanWunsch::NeedlemanWunsch(Sequence SEQ1, Sequence SEQ2) {
        seq1 = SEQ1;       
        seq2 = SEQ2;
}

void NeedlemanWunsch::align(Sequence &al_seq1, Sequence &al_seq2) {
        Traceback traceback(seq1, seq2);
                int i = seq1.seq.length();
                int j = seq2.seq.length();
                int length = i+j, k = length-1;

                for (int i=0; i<length; i++) 
                {
                        al_seq1.seq += '0';
                        al_seq2.seq += '0';
                }
                while (traceback.array[i][j] != '0') 
                {    
                        if (traceback.array[i][j] == 'X') 
                        {
                                al_seq1.seq[k] = seq1.seq[i-1];
                                al_seq2.seq[k] = seq2.seq[j-1];
                                i--; j--;
                        }       
                        else if (traceback.array[i][j] == '~') 
                        {
                                        al_seq1.seq[k] = '_';
                                        al_seq2.seq[k] = seq2.seq[j-1];
                                        j--;
                        }
                        else if (traceback.array[i][j] == '|') 
                        {
                                                al_seq1.seq[k] = seq1.seq[i-1];
                                                al_seq2.seq[k] = '_';
                                                i--;
                        }
                        k--;
                }
                al_seq1.seq = shortened(al_seq1.seq);
                al_seq2.seq = shortened(al_seq2.seq);
                al_seq1.name = seq1.name;
                al_seq2.name = seq2.name;
}

void NeedlemanWunsch::printSeq() {
        seq1.print();
        seq2.print();
}

void NeedlemanWunsch::printTraceback() {
        Traceback traceback(seq1, seq2);
        traceback.print();
}

void NeedlemanWunsch::printScore() {
        Score score(seq1, seq2);
        score.print();
}

void NeedlemanWunsch::score_intofile(string filename) {
        Score score(seq1, seq2);        
        score.into_file(filename);
}

void NeedlemanWunsch::traceback_intofile(string filename) {
        Score traceback(seq1, seq2);        
        traceback.into_file(filename);
}