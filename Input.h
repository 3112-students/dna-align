#pragma once
#include "Sequence.h"

class Input {
private:
	int argc;
	string argv[20];

public:
	int acc;
	string alignFilename;
	string tracebackFilename;
	string scoreFilename;

	Input (int argc, char const *argv[]);

	void usage();
	void viewMode(Sequence &seq1, Sequence &seq2);
	void viewSequence();
	void readSequence(Sequence &seq1, Sequence &seq2);
	bool outputMode();
};