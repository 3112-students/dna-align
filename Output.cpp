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
        printf("%s ", testSequence.name.c_str());
}

void Output::printSequence(Sequence testSequence)
{
        printf("%s ", testSequence.seq.c_str());
}

void Output::printSequenceLength(Sequence testSequence)
{
        printf("[%lu]\n", testSequence.seq.length());
}

void Output::printAlignedSequences()
{
        if (seq1.name.length() > seq2.name.length())
        {
                printSequenceName(seq1);
                printSequence(al_seq1);
                printSequenceLength(seq1);
                printSequenceName(seq2);
                for (int i = 0; i < seq1.name.length()-seq2.name.length(); ++i)
                {
                        printf(" ");
                }
                printSequence(al_seq2);
                printSequenceLength(seq2);
                for (int i = 0; i < seq1.name.length()+1; ++i)
                {
                        printf(" ");
                }
        }  
        else 
        {
                printSequenceName(seq1);
                for (int i = 0; i < seq2.name.length()-seq1.name.length(); ++i)
                {
                        printf(" ");
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
        std::cout << std::fixed << std::setprecision(accuracy) << 100 * identityCount / identityLength << "%%"<<std::endl;
       // printf("Identitiy = %.3f%%. \n", 100 * identityCount / identityLength);
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

void Output::printFile(string fileName) {
        ofstream out(fileName.c_str());
        out<<"DNA 1: "<<al_seq1.seq<<" \n";
        out<<"DNA 2: "<<al_seq2.seq;
        out.close();
        printf("File was successfully printed to %s\n", fileName.c_str());
}