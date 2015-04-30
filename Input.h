#pragma once
#include "Sequence.h"

class Input
{
private:
	int argc;
	string argv[20];
public:
	void usage();

	void viewSequence();

	int outputMode();

	void viewMode(int &accuracy, Sequence &seq1, Sequence &seq2, string &alignFilename, string &tracebackFilename, string &scoreFilename);

	void readSequence(Sequence &seq1, Sequence &seq2);

	Input (int argc, char const *argv[]);
};