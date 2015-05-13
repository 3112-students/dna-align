#include "NeedlemanWunsch.h"
#include "Output.h"
#include "Input.h"
#include <fstream>

int main(int argc, char const *argv[]) {
    Input Inp(argc, argv);
    if (argc == 1) 
    	Inp.usage();
    else {
		std::string fn = argv[1]; 
		ifstream ifile(argv[1]);
		if (!ifile) {
			cout<<"File not found"<<endl;
			Inp.usage();
		}
		else if ((fn.substr(fn.find_last_of(".") + 1)) != "fasta") {
			cout<<"Wrong file extension"<<endl;
			Inp.usage();
		}
		else {	
	    	Sequence seq1, seq2, al_seq1, al_seq2;
	        Inp.viewMode(seq1, seq2);
	        Inp.viewSequence(); 
	        Inp.readSequence(seq1, seq2);
	        NeedlemanWunsch Alg(seq1, seq2);
	        Alg.align(al_seq1, al_seq2);
	        Output Out(seq1, seq2, al_seq1, al_seq2);
	        if (Inp.outputMode()) {
		        Out.printFile(Inp.acc, Inp.alignFilename);
		        Alg.traceback_intofile(Inp.tracebackFilename);
		        Alg.score_intofile(Inp.scoreFilename);	        	
	        }
	        else {
	        	Out.printIdentity(Inp.acc);
	        	Out.printAlignedSequences();
	        	Out.printMatch();
	        }
	    }
    }
	return 0;
}