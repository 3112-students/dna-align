#include "Sequence.h"
        
Sequence::Sequence() {
        name = "";
        seq = "";
        penalty = 0;
}        
        
Sequence::Sequence (string seqName, string fileName) {
        ifstream file (fileName.c_str());
        while (!file.eof())
        {
                string name;
                getline(file, name);
                name.erase(0,1);
                if (name == seqName)
                {
                        getline(file, seq);
                        break;
                }
                else 
                {
                        getline(file, name);
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