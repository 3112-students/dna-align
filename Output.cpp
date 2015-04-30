#include "Output.h"
        
Output::Output(Sequence a, Sequence b, Sequence c, Sequence d)
{
        seq1 = a;
        seq2 = b;
        al_seq1 = c;
        al_seq2 = d;
}

void Output::printSequenceName(Sequence testSequence)
{
        cout<<testSequence.name<<" ";
}

void Output::printSequence(Sequence testSequence)
{
        cout<<testSequence.seq;
}

void Output::printSequenceLength(Sequence testSequence)
{
        cout<<"["<<testSequence.seq.length()<<"]";
}

void Output::printAlignedSequences()
{
        if (seq1.name.length() > seq2.name.length())
        {
            cout<<seq1.name<<" "<<al_seq1.seq<<" "<<seq1.seq.length()<<endl;
            cout<<seq2.name<<" ";
            for (int i = 0; i < seq1.name.length()-seq2.name.length(); ++i) {
                cout<<" ";
            }
            cout<<al_seq2.seq<<" "<<seq2.seq.length();
            for (int i = 0; i < seq1.name.length()+1; ++i) {
                cout<<" ";
            }
        }  
        else 
        {
                printSequenceName(seq1);
                for (int i = 0; i < seq2.name.length()-seq1.name.length(); ++i)
                {
                        cout<<" ";
                }
                printSequence(al_seq1);
                printSequenceLength(seq1);
                printSequenceName(al_seq2);
                printSequence(seq2);
                printSequenceLength(seq2);
                for (int i = 0; i < seq2.name.length()+1; ++i)
                {
                        printf(" ");
                }
        }
}

void Output::printIdentity(int accuracy)
{
        float identityCount = 0;
        float identityLength = seq1.seq.length();
        for (int i = 0; i < identityLength; ++i)
        {
                if (seq1.seq[i] == seq2.seq[i])
                {
                        ++identityCount;
                }
        }
        std::cout << std::fixed << std::setprecision(accuracy) << 100 * identityCount / identityLength << "%"<<std::endl;
}

void Output::printMatch(char const *star)
{
        for (int i = 0; i < seq1.seq.length(); ++i)
        {
                if (seq1.seq[i] == seq2.seq[i])
                {
                        printf("%s", star);
                }
                else
                {
                        printf(" ");
                }
        }
        printf("\n");
}

void Output::printFile(string fileName) 
{
        ofstream out(fileName.c_str());

        float identityCount = 0;
        float identityLength = al_seq1.seq.length();
        for (int i = 0; i < identityLength; ++i) {
            if (al_seq1.seq[i] == al_seq2.seq[i]) {
                ++identityCount;
            }
        }

        out<<"FASTA format, sequence identity = "<< setprecision(3) <<100 * identityCount / identityLength<<"%"<<endl<<endl<<endl;
   

        if (al_seq1.name.length() > al_seq2.name.length()) {
            out<< al_seq1.name << "        " << al_seq1.seq << endl << al_seq2.name <<"        ";
            for (int i = 0; i < al_seq1.name.length() - al_seq2.name.length(); ++i)
            {
                    out<<" ";
            }
            out<< al_seq2.seq << endl<<"        ";

            for (int i = 0; i < al_seq1.name.length()+8; ++i)
            {
                out<<" ";
            }

            for (int i = 0; i < al_seq1.seq.length(); ++i)
            {
                    if (al_seq1.seq[i] == al_seq2.seq[i])
                    {
                            out<<"*";
                    }
                    else
                    {
                            out<<" ";
                    }
            }                

        }  
        else 
        {
            out<<al_seq1.name<<"        ";
            for (int i = 0; i < al_seq2.name.length()-al_seq1.name.length(); ++i)
            {
                out<<" ";
            }
            out<<al_seq1.seq<<endl<<al_seq2.name<<"        "<<al_seq2.seq<<endl;

            for (int i = 0; i < seq2.name.length(); ++i)
            {
                out<<" ";
            }
            out<<"        ";

            for (int i = 0; i < al_seq1.seq.length(); ++i)
            {
                    if (al_seq1.seq[i] == al_seq2.seq[i])
                    {
                            out<<"*";
                    }
                    else
                    {
                            out<<" ";
                    }
            }                 
        }

        out<<"\n"; 

        out.close();
        printf("successfully printed to %s\n", fileName.c_str());
}