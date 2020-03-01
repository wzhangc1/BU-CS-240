#include "VoterDB.h"

int main(int argc, char *argv[])
{
	string lastName;
	string firstName;
	int age;
	int streetNumber;
	string streetName;
	string town;
	string zipCode;
	float amountDonated;
	
	string command;
	float money;
	
	cout << fixed << setprecision(2);
	
	do
	{
		cout << endl << "Enter the one following commands: New, Update, View, Donate, Report, or Quit" << endl;

		cin >> command;
		
		if (command == "New")
		{
			New(lastName, firstName, age, streetNumber, streetName, 
				town, zipCode, amountDonated);
		}
		else if (command == "Update")
		{
			Update(lastName, firstName, age, streetNumber, streetName, 
				town, zipCode);
		}
		else if (command == "View")
		{
			View(lastName, firstName, age, streetNumber, streetName, 
				town, zipCode, amountDonated);
		}
		else if (command == "Donate")
		{
			Donate(amountDonated);
		}
		else if (command == "Report")
		{
			Report(lastName, amountDonated);
		}
		
	} while(command != "Quit");
	
	return 0;
}
