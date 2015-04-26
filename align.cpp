#include "NeedlemanWunsch.h"

//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//#include "Sequence.h"
//using namespace std;

/*class Sequence{
public:
        float penalty;
        string name;
        string seq;
        
        Sequence() {
                name = "";
                seq = "";
                penalty = 0;
        }

        Sequence(string filename) {
                string str_penalty;
                ifstream file(filename.c_str());
                getline(file, name);
                getline(file, seq);
                getline(file, str_penalty);
                file.close();
                penalty = atof(str_penalty.c_str());
        }

        Sequence(string NAME, string SEQ, float PENALTY) {
                name = NAME;
                seq = SEQ;
                penalty = PENALTY;
        }

        Sequence(Sequence const &Seq) {
                name = Seq.name;
                seq = Seq.seq;
                penalty = Seq.penalty;
        }

        void change(string NAME, string SEQ, float PENALTY) {
                name = NAME;
                seq = SEQ;
                penalty = PENALTY;
        }               

        void print() {
                cout<<name<<":     "<<seq<<endl;
        }

        void print_penalty() {
                cout<<"gap penalty for "<<name<<":     "<<penalty<<endl;
        }
};
*/
/*
class Matrix {
protected:
        int weight(int i, int j, string DNA1, string DNA2) {
                if (DNA1[i-1] == DNA2[j-1]) {
                        return 1;
                } else {
                        return 0;
                }
        }
public:
        virtual void print() = 0;
        virtual void into_file(string file_name) = 0;
};
*/
/*
class Score : public Matrix {
private:
        float max(float a, float b, float c) {
                if ((a>=b) && (a>=c)) { return a; };
                if ((b>=a) && (b>=c)) { return b; };
                if ((c>=a) && (c>=b)) { return c; };
        }
public:
        vector<vector <float> > array;

        Score(Sequence seq1, Sequence seq2) {
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

        void print() {
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

        void into_file(string file_name) {
                int string_num = array.size();
                int column_num = array[0].size();
                ofstream out(file_name.c_str());
                for (int i=0; i<string_num; i++) {
                        for (int j=0; j<column_num; j++) {
                                if (array[i][j] < 0) {
                                        out<<array[i][j]<<" ";
                                } else {
                                        out<<" "<<array[i][j]<<" ";        
                                }
                        }
                        out<<"\n";
                }
                out.close();
        }
};
*/
/*
class Traceback : public Matrix {
private:
        int num_max(float a, float b, float c) {
                if ((a>=b) && (a>=c)) { return 1; };
                if ((b>=a) && (b>=c)) { return 2; };
                if ((c>=a) && (c>=b)) { return 3; };
        }

        char slash(int num) {
        if (num == 1) { return 'X';};
        if (num == 2) { return '|';};
        if (num == 3) { return '~';};
        }
public:
        vector<vector <char> > array;

        Traceback(Sequence seq1, Sequence seq2) {
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

                Score Score(seq1, seq2);
                for (int i=1; i<length1+1; i++) {
                        for (int j=1; j<length2+1; j++) {
                                array[i][j] = slash(num_max(
                                                Score.array[i-1][j-1] + weight(i, j, seq1.seq, seq2.seq),
                                                Score.array[i-1][j] + seq2.penalty,
                                                Score.array[i][j-1] + seq1.penalty
                                                                                                        ));
                        }
                }
        }

        void print() {
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

        void into_file(string file_name) {
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
};
*/
/*

class Needleman_Wunsch{
private:
        Sequence seq1;
        Sequence seq2;

        string shortened(string DNA) {
        for (int i=0; i<DNA.length(); i++) {
                if (DNA[i] == '0') {
                        DNA.erase(i, 1);
                        i--;
                }
        }
        return DNA;
}
public:
        Needleman_Wunsch(Sequence SEQ1, Sequence SEQ2) {
                seq1 = SEQ1;       
                seq2 = SEQ2;
        }

        void align(Sequence &al_seq1, Sequence &al_seq2) {
                Traceback traceback(seq1, seq2);
                int i = seq1.seq.length();
                int j = seq2.seq.length();
                int length = i+j, k = length-1;

                for (int i=0; i<length; i++) {
                        al_seq1.seq += '0';
                        al_seq2.seq += '0';
                }
                while (traceback.array[i][j]!='0') {    
                        if (traceback.array[i][j] == 'X') {
                                al_seq1.seq[k] = seq1.seq[i-1];
                                al_seq2.seq[k] = seq2.seq[j-1];
                                i--; j--;
                        }       
                        else {
                                if (traceback.array[i][j] == '~') {
                                        al_seq1.seq[k] = '_';
                                        al_seq2.seq[k] = seq2.seq[j-1];
                                        j--;
                                }
                                else {                              
                                        if (traceback.array[i][j] == '|') {
                                                al_seq1.seq[k] = seq1.seq[i-1];
                                                al_seq2.seq[k] = '_';
                                                i--;
                                        }
                                }
                        }
                        k--;
                }
                al_seq1.seq = shortened(al_seq1.seq);
                al_seq2.seq = shortened(al_seq2.seq);
                al_seq1.name = "ALIGNED " + seq1.name;
                al_seq2.name = "ALIGNED " + seq2.name;
        }

        void print_seq() {
                seq1.print();
                seq2.print();
        }

        void print_traceback() {
                Traceback traceback(seq1, seq2);
                traceback.print();
        }

        void print_score() {
                Score score(seq1, seq2);
                score.print();
        }

        void score_intofile(string filename) {
                Score score(seq1, seq2);        
                score.into_file(filename);
        }

        void traceback_intofile(string filename) {
                Score traceback(seq1, seq2);        
                traceback.into_file(filename);
        }
};
*/

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