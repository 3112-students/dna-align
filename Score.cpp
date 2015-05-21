#include "Score.h"

float Score::max(float a, float b, float c) {
        if ((a>=b) && (a>=c)) {
                return a;
        }
        else {
                if ((b>=a) && (b>=c)) {
                        return b;
                } 
                else {
                        return c;
                }
        }
}

Score::Score(Sequence seq1, Sequence seq2) {
        int length1 = seq1.seq.length();
        int length2 = seq2.seq.length();
        array.resize(length1+1);
        for (int i=0; i<(length1+1); i++) {
                array[i].resize(length2+1);
                for (int j=0; j<(length2+1); j++) {
                        array[i][j] = 0;
                }
        }
        for (int i=0; i<length1+1; i++) {
                array[i][0] = (-i);
        }
        for (int j=0; j<length2+1; j++) {
                array[0][j] = (-j);
        }

        for (int i=1; i<length1+1; i++) {
                for (int j=1; j<length2+1; j++) {
                        array[i][j] = max(
                                        array[i-1][j-1] + weight(i, j, seq1.seq, seq2.seq),
                                        array[i-1][j] + seq2.penalty,
                                        array[i][j-1] + seq1.penalty
                                                                                );
                }
        }
}       

void Score::print() {
        cout<<"\n";
        int string_num = array.size();
        int column_num = array[0].size();
        for (int i=0; i<string_num; i++) {
                for (int j=0; j<column_num; j++) {
                        if (array[i][j] < 0) {
                                cout<<array[i][j]<<" ";
                        } else {
                                cout<<" "<<array[i][j]<<" ";        
                        }
                }
                cout<<"\n";
        }
        cout<<"\n";
}

void Score::into_file(string FN) {
        int string_num = array.size();
        int column_num = array[0].size();
        ofstream out(FN.c_str());
        for (int i=0; i<string_num; i++) {
                for (int j=0; j<column_num; j++) 
                {
                        if (array[i][j] < -99)
                        {
                            out<<array[i][j]<<" ";
                        }
                        else if (array[i][j] < -9)
                        {
                            out<<" "<<array[i][j]<<" ";
                        }
                        else if (array[i][j] < 0)
                        {
                            out<<"  "<<array[i][j]<<" ";
                        }
                        else if (array[i][j] < 10)
                        {
                           out<<"   "<<array[i][j]<<" "; 
                        }
                        else if (array[i][j] < 100)
                        {
                            out<<"  "<<array[i][j]<<" "; 
                        }
                        else
                            out<<" "<<array[i][j]<<" ";
                }
                out<<endl;
        }
        out.close();
        cout<<"Score printed into "<<FN<<endl;
}