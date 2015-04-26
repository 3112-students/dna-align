int main() {
        sequence seq1("DNA1.txt"); sequence seq2("DNA2.txt");

        sequence al_seq1; sequence al_seq2;

        algorithm Alg(seq1, seq2);

        Alg.align(al_seq1, al_seq2);

        output Out(al_seq1, al_seq2);

        Out.printAlignedSequences(al_seq1, al_seq2, seq1, seq2);
        Out.printMatch();
        Out.printIdentity();
        
        return 0;
}