class output
{
private:
        sequence seq1;
        sequence seq2;
public:
        output(sequence L, sequence R)
        {
                seq1 = L;
                seq2 = R;
        }

        void printSequenceName(sequence seq1)
        {
                printf("%s ", seq1.name.c_str());
        }

        void printSequence(sequence seq1)
        {
                printf("%s ", seq1.seq.c_str());
        }

        void printSequenceLength(sequence seq1)
        {
                printf("[%lu]\n", seq1.seq.length());
        }

        void printAlignedSequences(sequence seq1, sequence seq2, sequence sequenceOneOG, sequence sequenceTwoOG)
        {
                if (seq1.name.length() > seq2.name.length())
                {
                        printSequenceName(seq1);
                        printSequence(seq1);
                        printSequenceLength(sequenceOneOG);
                        printSequenceName(seq2);
                        for (int i = 0; i < seq1.name.length()-seq2.name.length(); ++i)
                        {
                                printf(" ");
                        }
                        printSequence(seq2);
                        printSequenceLength(sequenceTwoOG);
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
                        printSequence(seq1);
                        printSequenceLength(sequenceOneOG);
                        printSequenceName(seq2);
                        printSequence(seq2);
                        printSequenceLength(sequenceTwoOG);
                        for (int i = 0; i < seq2.name.length()+1; ++i)
                        {
                                printf(" ");
                        }
                }
        }

        void printIdentity()
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
                printf("Identitiy = %.f%%. \n", 100 * identityCount / identityLength);
        }

        void printMatch()
        {
                for (int i = 0; i < seq1.seq.length(); ++i)
                {
                        if (seq1.seq[i] == seq2.seq[i])
                        {
                                printf("*");
                        }
                        else
                        {
                                printf(" ");
                        }
                }
                printf("\n");
        }
};