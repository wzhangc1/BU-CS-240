#include "VoterDB.h"
	
void New(string& lastName, string& firstName, int& age, int&
	streetNumber, string& streetName, string& town, string& zipCode,
	float& amountDonated)
{
	cout << endl << "Input voter information" << endl << "Last name: ";
	cin.ignore();
	getline(cin, lastName);
	cout << "First name: " ;
	cin.ignore();
	getline(cin, firstName);
	cout << "Age: ";
	cin >> age;
	cout << "Street number: ";
	cin >> streetNumber;
	cout << "Street name: ";
	cin.ignore();
	getline(cin, streetName);
	cout << "Town: ";
	cin.ignore();
	getline(cin, town);
	cout << "ZIP code: ";
	cin >> zipCode;
	
	amountDonated = 0.0;
}

void Update(string& lastName, string& firstName, int& age, int&
	streetNumber, string& streetName, string& town, string& zipCode)
{
	cout << endl << "Input voter information" << endl << "Last name: ";
	cin.ignore(100, '\n');
	getline(cin, lastName);
	cout << "First name: " ;
	cin.ignore(100, '\n');
	getline(cin, firstName);
	cout << "Age: ";
	cin >> age;
	cout << "Street number: ";
	cin >> streetNumber;
	cout << "Street name: ";
	cin.ignore(100, '\n');
	getline(cin, streetName);
	cout << "Town: ";
	cin.ignore(100, '\n');
	getline(cin, town);
	cout << "ZIP code: ";
	cin >> zipCode;
}

void View(string lastName, string firstName, int age, int streetNumber, 
	string streetName, string town, string zipCode,	float 
	amountDonated)
{
	cout << endl << "Voter information" << endl
	<< "Last name: " << lastName << endl
	<< "First name: " << firstName << endl
	<< "Age: " << age << endl
	<< "Street number: " << streetNumber << endl
	<< "Street name: " << streetName << endl
	<< "Town: " << town << endl
	<< "ZIP code: " << zipCode << endl
	<< "Amount donated: " << amountDonated << endl;
}

void Donate(float& amountDonated)
{
	float money;
	
	cout << endl << "Money to donate: ";
		cin >> money;
			
	amountDonated += money;
}

void Report(string lastName, float amountDonated)
{
	cout << endl << lastName << " $" << amountDonated << endl;
}
