#include "Sequence.h"
        
Sequence::Sequence() {
        name = "";
        seq = "";
        penalty = 0;
}        

/* Fasta (very dumb & only for 2 sequences) */
Sequence::Sequence (char const *seqName, string fileName) {
        ifstream file (fileName.c_str());
        while (!file.eof())
        {
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

/* Standard manual input */
Sequence::Sequence(string NAME, string SEQ) {
        name = NAME;
        seq = SEQ;
        penalty = -1;
}

/* Manual input + penalty */
Sequence::Sequence(string NAME, string SEQ, double PENALTY) {
        name = NAME;
        seq = SEQ;
        penalty = PENALTY;
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