#include "Sequence.h"
        
Sequence::Sequence() {
        name = "";
        seq = "";
        penalty = -1;
}        
        
Sequence::Sequence (string seqName, string fileName) {
        ifstream file (fileName.c_str());
        while (!file.eof()) {
                string temp;
                getline(file, temp);
                temp.erase(0,1);
                if (temp == seqName) {
                        getline(file, seq);
                        name = seqName;
                        break;
                }
                else {
                        getline(file, temp);
                }
        }
        file.close();
}

Sequence::Sequence(Sequence const &Seq) {
        name = Seq.name;
        seq = Seq.seq;
        penalty = Seq.penalty;
}

void Sequence::change(string NAME, string SEQ, double PENALTY) {
        name = NAME;
        seq = SEQ;
        penalty = PENALTY;
}               

void Sequence::print() {
        cout<<name<<":     "<<seq<<endl;
}  