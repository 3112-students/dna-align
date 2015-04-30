#include "Input.h"

void Input::usage() {
    printf("Usage\n");
    printf("./align <file.fasta>    	Select the file\n");
    printf("<string> <string> <string> 	Available DNAs for alignment\n\n");
    /*
    printf("Functions\n");
    printf("--match                 	Show mathes in aligned DNAs\n");
    printf("--identity <number>     	Number of decimal places for identity value\n");
    printf("--gap      <symbol>     	Customizable symbol for gap output\n"); 
    */
}

void Input::viewSequence() {

        ifstream file (argv[1]);
        string temp;
        while (!file.eof()) {   
	        getline(file, temp);
	        temp.erase(0, 1);
	        cout<<temp<<endl;
	        getline(file, temp);
        }
        file.close();
}

void Input::readSequence(Sequence &seq1, Sequence &seq2) { // THIS IS VERY FUCKING STUPID
	string temp1, temp2;
	cin>>temp1>>temp2;
	Sequence tempSeq1(temp1, argv[1]);
	Sequence tempSeq2(temp2, argv[1]);
	seq1.name = temp1;
	seq2.name = temp2;
	seq1.seq = tempSeq1.seq;
	seq2.seq = tempSeq2.seq;
}

Input::Input(int ARGC, char const *ARGV[]) {
	argc = ARGC;
	for (int i = 0; i < argc; ++i) {
		argv[i] = ARGV[i];
	}
}
