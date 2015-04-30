#include "NeedlemanWunsch.h"
#include "Output.h"
#include "Input.h"

int main(int argc, char const *argv[])
{
        Sequence seq1, seq2, al_seq1, al_seq2;

        /* Defaults */
		int accuracy = 0;
		seq1.penalty = -1;
		seq2.penalty = -1;
		string alignFilename = "align.txt";
		string tracebackFilename = "Traceback.txt";
		string scoreFilename = "Score.txt";
        
        Input Inp(argc, argv);
        
        std::string fn = argv[1];

        if ((argc == 1) || (fn.substr(fn.find_last_of(".") + 1) != "fasta"))
        {
        	Inp.usage();
        }
        else
        {
	        Inp.viewMode(accuracy, seq1, seq2, alignFilename, tracebackFilename, scoreFilename);
	        Inp.viewSequence(); 
	        Inp.readSequence(seq1, seq2);


	        NeedlemanWunsch Alg(seq1, seq2);
	        Alg.align(al_seq1, al_seq2);

	        Output Out(seq1, seq2, al_seq1, al_seq2);

	        if (Inp.outputMode() == 1)
	        {
		        Out.printFile(accuracy, alignFilename);
		        Alg.traceback_intofile(tracebackFilename);
		        Alg.score_intofile(scoreFilename);	        	
	        }
	        else
	        {
	        	Out.printIdentity(accuracy);
	        	Out.printAlignedSequences();
	        	Out.printMatch();
	        }


        }
        return 0;
}