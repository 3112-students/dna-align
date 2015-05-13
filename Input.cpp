#include "Input.h"

Input::Input(int ARGC, char const *ARGV[]) {
	argc = ARGC;
	for (int i = 0; i < argc; ++i) {
		argv[i] = ARGV[i];
	}
	acc = 0;
	alignFilename = "Align.txt";
	tracebackFilename = "Traceback.txt";
	scoreFilename = "Score.txt";
}

void Input::usage() {
	cout<<"Usage:"<<endl<<"./align <file.fasta>"<<endl<<"Functions:"<<endl;
	cout<<"--identity <number>              Number of decimal places for identity value"<<endl;
	cout<<"--penalty <number> <number>      Set penalties for sequences"<<endl;
	cout<<"--file                           Print aligned sequences into TXT file"<<endl; 
	cout<<"--output.path <file>             Sequence output TXT file"<<endl;
	cout<<"--traceback.path <file>          Traceback output TXT file"<<endl;
	cout<<"--score.path <file>              Score output TXT file"<<endl;	
}

void Input::viewMode(Sequence &seq1, Sequence &seq2) {
	for (int i = 0; i < argc; ++i) {
		if (argv[i] == "--identity") {
			acc = stoi(argv[i+1]);
		} else if (argv[i] == "--penalty") {
			seq1.penalty = stoi(argv[i+1]);
			seq2.penalty = stoi(argv[i+2]);
		} else if (argv[i] == "--output.path") {
			alignFilename = argv[i+1];
		} else if (argv[i] == "--traceback.path") {
			tracebackFilename = argv[i+1];
		} else if (argv[i] == "--score.path") {
			scoreFilename = argv[i+1];
		}
	}
}

void Input::viewSequence() {
    cout<<"Sequences found:"<<endl;
    ifstream file (argv[1]);
    string temp;
    while (!file.eof()) {   
        getline(file, temp);
        temp.erase(0, 1);
        cout<<temp<<" ";
        getline(file, temp);
    }
    file.close();
    cout<<endl<<"Usage: <sequence.name> <sequnce.name>"<<endl;
}

void Input::readSequence(Sequence &seq1, Sequence &seq2) {
	string temp1, temp2;
	cin>>temp1>>temp2;
	Sequence tempSeq1(temp1, argv[1]);
	Sequence tempSeq2(temp2, argv[1]);
	seq1.name = tempSeq1.name;
	seq2.name = tempSeq2.name;
	seq1.seq = tempSeq1.seq;
	seq2.seq = tempSeq2.seq;
}

bool Input::outputMode() {
	int temp = 0;
	for (int i = 0; i < argc; ++i) {
		if (argv[i] == "--file") {
			temp = 1; 
			break;
		}
		else 
			temp = 0;
	}
	return(temp);
}