#pragma once
#include "Sequence.h"

class Input
{
private:
	int argc;
	string argv[10];
public:
	void usage();

	void viewSequence();

	void readSequence(Sequence &seq1, Sequence &seq2);

	Input (int argc, char const *argv[]);
};