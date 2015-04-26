#include "Sequence.h"
        
Sequence::Sequence() {
        name = "";
        seq = "";
        penalty = 0;
}        

Sequence::Sequence(string filename) {
        string str_penalty;
        ifstream file(filename.c_str());
        getline(file, name);
        getline(file, seq);
        getline(file, str_penalty);
        file.close();
        penalty = atof(str_penalty.c_str());
}

Sequence::Sequence(string NAME, string SEQ, float PENALTY) {
        name = NAME;
        seq = SEQ;
        penalty = PENALTY;
}

Sequence::Sequence(Sequence const &Seq) {
        name = Seq.name;
        seq = Seq.seq;
        penalty = Seq.penalty;
}
        
void Sequence::change(string NAME, string SEQ, float PENALTY) {
        name = NAME;
        seq = SEQ;
        penalty = PENALTY;
}               

void Sequence::print() {
        cout<<name<<":     "<<seq<<endl;
}

//void Sequence::print_penalty() {
//        cout<<"gap penalty for "<<name<<":     "<<penalty<<endl;
//}        