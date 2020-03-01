#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void New(string& lastName, string& firstName, int& age, int&
	streetNumber, string& streetName, string& town, string& zipCode,
	float& amountDonated);
	
void Update(string& lastName, string& firstName, int& age, int&
	streetNumber, string& streetName, string& town, string& zipCode);
	
void View(string lastName, string firstName, int age, int streetNumber, 
	string streetName, string town, string zipCode,	float 
	amountDonated);
	
void Donate(float& amountDonated);

void Report(string lastName, float amountDonated);
