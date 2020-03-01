#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Voter
{
public:
	string lastName;
	string firstName;
	string userId;
	string password;
	int age;
	int streetNumber;
	string streetName;
	string town;
	string zipCode;
	float amountDonated;
	
public:
	Voter(void);
	void Update(void);
	void Passwd(void);
	void View(void);		
	void Donate(float& totalAmountDonated);
	void Report(void);
};
