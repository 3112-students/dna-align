#include "Output.h"
        
Output::Output(Sequence a, Sequence b, Sequence c, Sequence d) {
        seq1 = a;
        seq2 = b;
        al_seq1 = c;
        al_seq2 = d;
}

void Output::printMatch() {
    for (int i = 0; i < seq1.seq.length(); ++i) {
        if (al_seq1.seq[i] == al_seq2.seq[i]) 
            cout<<"*";
        else 
            cout<<" ";
    }
    cout<<endl;
}

void Output::printIdentity(int accuracy) {
        float identityCount = 0;
        float identityLength = al_seq1.seq.length();
        for (int i = 0; i < identityLength; ++i) {
            if (al_seq1.seq[i] == al_seq2.seq[i])
                ++identityCount;
        }
        std::cout<<std::fixed<<"Terminal output, sequence identity = "<<std::setprecision(accuracy)<< 100*identityCount/identityLength<< "%"<<std::endl<<std::endl<<std::endl;
}

void Output::printAlignedSequences() {
    if (seq1.name.length() > seq2.name.length()) {
        cout<<seq1.name<<"        "<<al_seq1.seq<<" "<<seq1.seq.length()<<endl;
        cout<<seq2.name<<"        ";
        for (int i = 0; i < seq1.name.length()-seq2.name.length(); ++i)
            cout<<" ";
        cout<<al_seq2.seq<<" "<<seq2.seq.length()<<endl;
        for (int i = 0; i < seq1.name.length(); ++i)
            cout<<" ";
        cout<<"        ";
    }  
    else {
        cout<<seq1.name<<"        ";
        for (int i = 0; i < seq2.name.length()-seq1.name.length(); ++i)
            cout<<" ";
        cout<<al_seq1.seq<<" "<<seq1.seq.length()<<endl;
        cout<<al_seq2.name<<"        "<<al_seq2.seq<<" "<<al_seq2.seq.length()<<endl;
        for (int i = 0; i < seq2.name.length(); ++i) 
            cout<<" ";
        cout<<"        ";
    }
}

float Output::getIdentity() {
    float identityCount = 0;
    float identityLength = al_seq1.seq.length();
    for (int i = 0; i < identityLength; ++i) {
        if (al_seq1.seq[i] == al_seq2.seq[i]) 
            ++identityCount;
    }
    float result = 100*identityCount/identityLength;
    return (result);
}

int Output::getSequenceLength(Sequence al_seq1) {
    return(al_seq1.seq.length());
}

void Output::printFile(int accuracy, string fileName) {
        ofstream out(fileName.c_str());
        out<<"FASTA format, sequence identity = "<<setprecision(accuracy+2)<<getIdentity()<<"%"<<endl<<endl<<endl;
        if (al_seq1.name.length() > al_seq2.name.length()) {
            out<<al_seq1.name<<"        "<<al_seq1.seq<<" ["<<seq1.seq.length()<<"]"<<endl<<al_seq2.name<<"        ";
            for (int i = 0; i < al_seq1.name.length() - al_seq2.name.length(); ++i)
                out<<" ";
            out<<al_seq2.seq<<" ["<<seq2.seq.length()<<"]"<<endl;

            for (int i = 0; i < al_seq1.name.length()+8; ++i) 
                out<<" ";
            for (int i = 0; i < al_seq1.seq.length(); ++i) {
                if (al_seq1.seq[i] == al_seq2.seq[i]) 
                    out<<"*";
                else 
                    out<<" ";
            }  
        }  
        else {
            out<<al_seq1.name<<"        ";
            for (int i = 0; i < al_seq2.name.length()-al_seq1.name.length(); ++i) {
                out<<" ";
            }
            out<<al_seq1.seq<<" ["<< seq1.seq.length()<<"]"<<endl;
            out<<al_seq2.name<<"        "<<al_seq2.seq<<" ["<<seq2.seq.length()<<"]"<<endl;
            for (int i = 0; i < seq2.name.length()+8; ++i) {
                out<<" ";
            }            
            for (int i = 0; i < al_seq1.seq.length(); ++i) {
                if (al_seq1.seq[i] == al_seq2.seq[i]) 
                    out<<"*";
                else 
                    out<<" ";
            }                
        }
        out<<endl; 
        out.close();
        cout<<"Aligned sequences printed into "<<fileName<<endl;
}