#include "NeedlemanWunsch.h"
#include "Output.h"

int main(int argc, char const *argv[])
{
        Sequence seq1;
        Sequence seq2;

        if (argc == 1)
        {
                printf("Usage: \n");
                printf(" --manual <name1> <sequence1> <name2> <sequence2>      Manual input from command line \n");
                printf(" --fasta  <file1.fasta> <file2.fasta>                  Input from selected FASTA files \n");
        }
        else if (strcmp(argv[1], "--fasta") == 0)
        {
                Sequence seq1(argv[3], argv[2]);
                Sequence seq2(argv[4], argv[2]);

                Sequence al_seq1; 
                Sequence al_seq2;

                NeedlemanWunsch Alg(seq1, seq2);

                Alg.align(al_seq1, al_seq2);

                Output Out(seq1, seq2, al_seq1, al_seq2);

                Out.printFile("aligned.txt");

                // Out.printAlignedSequences(al_seq1, al_seq2, seq1, seq2);
                // Out.printMatch();
                // Out.printIdentity();
        }
        else if (strcmp(argv[1], "--manual") == 0)
        {
                Sequence seq1(argv[2], argv[3], atof(argv[4]));
                Sequence seq2(argv[5], argv[6], atof(argv[7]));

                Sequence al_seq1; Sequence al_seq2;

                NeedlemanWunsch Alg(seq1, seq2);

                Alg.align(al_seq1, al_seq2);

                Output Out(seq1, seq2, al_seq1, al_seq2);

                Out.printAlignedSequences();
                for (int i = 0; i < argc; ++i)
                {
                        if (strcmp(argv[i], "--gap") == 0)
                        {
                                Out.printMatch(argv[i+1]);
                                break;
                        }
                }                
                // Out.printMatch();
                for (int i = 0; i < argc; ++i)
                {
                        if (strcmp(argv[i], "--identity") == 0)
                        {
                                Out.printIdentity(atoi(argv[i+1])); 
                                break;
                        }
                }                 
                               
        }
        else
        {
                printf("Usage: \n");
                printf(" --manual <name1> <sequence1> <penalty1> <name2> <sequence2> <penalty2>         Manual input from command line \n");
                printf(" --fasta  <file1.fasta> <penalty1> <file2.fasta> <penalty2>                     Input from selected FASTA files \n");
                printf(" --identity <number>                                                            Number of decimal places for identity value \n");
                printf(" --gap <symbol>                                                                 Customizable symbol for gap output \n"); 
        }
        
        return 0;
}