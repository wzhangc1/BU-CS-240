#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Voter.h"

using namespace std;

class VoterDB
{
public:
	float totalAmountDonated;
	int numberOfVoters;
	Voter * voter;
	
public:
	VoterDB(int maxVoters);
	int Login(void);
	void New(Voter& voter);		
	void ReportVoters(void);
	void Save(void);
	void Load(ifstream& fin);
};


