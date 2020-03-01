#include "Voter.h"

Voter::Voter(void)
{
	lastName = "";
	firstName = "";
	userId = "";
	password = "";
	age = 0;
	streetNumber = 0;
	streetName = "";
	town = "";
	zipCode = "";
	amountDonated = 0;
}

void Voter::Update(void)
{
	bool valid;
	string temp;
	
	cout << endl << "Input voter information" << endl << "Last name: " 
		<< lastName << endl << "New last name: ";
	cin.ignore();
	getline(cin, temp);
	
	if (temp != "")
	{
		lastName = temp;
	}
	
	cout << "First name: " << firstName << endl << "New first name: ";
	getline(cin, temp);
	
	if (temp != "")
	{
		firstName = temp;
	}
	
	cout << "Age: " << age << endl << "New age: ";
	getline(cin, temp);
	
	if (temp != "")
	{
		age = stoi(temp);
	}
	
	cout << "Street number: " << streetNumber << endl << "New street number: ";
	getline(cin, temp);
	
	if (temp != "")
	{
		streetNumber = stoi(temp);
	}
	
	cout << "Street name: " << streetName << endl << 
		"New street name: ";
	getline(cin, temp);
	
	if (temp != "")
	{
		streetName = temp;
	}
	
	cout << "Town: " << town << endl << "New town: ";
	getline(cin, temp);
	
	if (temp != "")
	{
		town = temp;
	}
	
	do
	{
		cout << "ZIP code: " << zipCode << endl << "New ZIP code: ";
		getline(cin, temp);
		
		valid = true;
		
		if (temp != "")
		{
			if (temp.length() == 5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (!isdigit(temp.at(i)))
					{
						valid = false;
					}
				}
			}
			else
			{
				valid = false;
			}
			
			if (valid)
			{
				zipCode = temp;
			}
			else
			{
				cout << "ZIP code must contain exactly 5 digits" << endl;
			}
		}
	} while (valid == false);
}

void Voter::Passwd(void)
{
	bool digit;
	bool specialChar;
	bool valid;
	string aPassword;
	string aPassword2;
	
	cout << endl << "Current password: ";
	cin >> aPassword;
	
	if (aPassword == password)
	{
		cout << "New password: ";
		cin >> aPassword;
		
		if (aPassword.length() >= 6)
		{
			digit = false;
			specialChar = false;
			valid = false;
	
			for (int i = 0; i < aPassword.length(); i++)
			{
				if (isdigit(aPassword.at(i)))
				{
					digit = true;
				}
				
				if (!isalpha(aPassword.at(i)) && !isdigit(aPassword.at(i)))
				{
					specialChar = true;
				}
			}
			
			if (digit && specialChar)
			{
				valid = true;
			}
		}
		
		if (valid)
		{
			cout << "New password: ";
			cin >> aPassword2;
			
			if (aPassword2 == aPassword)
			{
				password = aPassword;
				
				cout << "Password successfully updated" << endl;
			}
			else
			{
				cout << "ERROR: Password does not match" << endl;
			}
		}
		else
		{
			cout << "ERROR: Password must contains at least 6 characters, including at least one digit and one character that is neither a letter nor a digit" << endl;
		}
	}
	else
	{
		cout << "ERROR: Password does not match" << endl;
	}
}

void Voter::View(void)
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

void Voter::Donate(float& totalAmountDonated)
{
	float money;
	
	cout << endl << "Money to donate: ";
	cin >> money;
	
	if(amountDonated + money >= 0 && amountDonated + money <= 2700)
	{
		amountDonated += money;
		
		totalAmountDonated += money;
	}
	else
	{
		cout << "ERROR: Total amount must be non-negative, and not grow beyond $2,700" << endl;
	}
}

void Voter::Report(void)
{
	cout << endl << lastName << " $" << amountDonated << endl;
}


