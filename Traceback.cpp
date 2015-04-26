#include "Traceback.h"

int Traceback::num_max(float a, float b, float c) {
        if ((a>=b) && (a>=c)) {
                return 1;
        } 
        else { 
                if ((b>=a) && (b>=c)) {
                        return 2;
                }
                else {
                        return 3;
                }
        }
}

char Traceback::slash(int num) {
        {
                if (num == 1) { 
                        return 'X';
                }
                else 
                        if (num == 2) { 
                                return '|';
                        }
                        else 
                                return '~';
        }
}

Traceback::Traceback(Sequence seq1, Sequence seq2) {
        int length1 = seq1.seq.length();
        int length2 = seq2.seq.length();
        array.resize(length1+1);

        for (int i=0; i<(length1+1); i++) {
                array[i].resize(length2+1);
                for (int j=0; j<(length2+1); j++) {
                        array[i][j] = '0';
                }
        }
        for (int i=1; i<length1+1; i++) {
                array[i][0] = '|';
        }
        for (int j=1; j<length2+1; j++) {
                array[0][j] = '~';
        }                

        Score score(seq1, seq2);
        for (int i=1; i<length1+1; i++) {
                for (int j=1; j<length2+1; j++) {
                        array[i][j] = slash(num_max(
                                                score.array[i-1][j-1] + weight(i, j, seq1.seq, seq2.seq),
                                                score.array[i-1][j] + seq2.penalty,
                                                score.array[i][j-1] + seq1.penalty
                                                                                                        ));
                }
        }
}

void Traceback::print() {
        cout<<"\n";
        int string_num = array.size();
        int column_num = array[0].size();
        for (int i=0; i<string_num; i++) {
                for (int j=0; j<column_num; j++) {
                        cout<<array[i][j]<<" ";
                }
                cout<<"\n";
        }
        cout<<"\n";
}

void Traceback::into_file(string file_name) {
        int string_num = array.size();
        int column_num = array[0].size();
        ofstream out(file_name.c_str());
        for (int i=0; i<string_num; i++) {
                for (int j=0; j<column_num; j++) {
                        out<<array[i][j]<<" ";
                }
                out<<"\n";
        }
        out.close();
}