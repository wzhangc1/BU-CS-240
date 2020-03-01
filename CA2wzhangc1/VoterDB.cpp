#include "VoterDB.h"

VoterDB::VoterDB(int maxVoters)
{
	totalAmountDonated = 0;
	
	numberOfVoters = 0;
	
	voter = new Voter[maxVoters];
}

int VoterDB::Login(void)
{
	int i;
	string password;
	string userId;
	
	cout << endl << "User ID: ";
	cin >> userId;
	
	cout << "Password: ";
	cin >> password;
	
	i = 0;
	
	while (!(userId == voter[i].userId && password == voter[i].password) && i < numberOfVoters)
	{
		i++;
	}
	
	if (i >= numberOfVoters)
	{
		i = -1;
		
		cout << endl << "ERROR: User ID or Password are incorrect" << endl;
	}
	
	return i;
}
	
void VoterDB::New(Voter& voter)
{
	bool digit;
	bool specialChar;
	bool valid;
	
	cout << endl << "Input voter information" << endl << "Last name: ";
	cin >> voter.lastName;
	
	cout << "First name: ";
	cin >> voter.firstName;
	
	do
	{
		cout << "User ID: ";
		cin >> voter.userId;
		
		valid = true;
		
		if (voter.userId.length() >= 5 && voter.userId.length() <= 10)
		{
			for (int i = 0; valid && i < voter.userId.length(); i++)
			{
				if (!isalpha(voter.userId.at(i)) && !isdigit(voter.userId.at(i)))
				{
					valid = false;
				}
			}
		}
		else
		{
			valid = false;
		}
		
		if (!valid)
		{
			cout << "ERROR: User ID must contain at least 5 characters but no more than 10, containing only letters and digits" << endl;
		}
		
	} while (!valid);
	
	do
	{
		cout << "Password: ";
		cin >> voter.password;
		
		digit = false;
		specialChar = false;
		valid = false;
		
		if (voter.password.length() >= 6)
		{
			for (int i = 0; i < voter.password.length(); i++)
			{
				if (isdigit(voter.password.at(i)))
				{
					digit = true;
				}
				
				if (!isalpha(voter.password.at(i)) && !isdigit(voter.password.at(i)))
				{
					specialChar = true;
				}
			}
			
			if (digit && specialChar)
			{
				valid = true;
			}
		}
		
		if (!valid)
		{
			cout << "ERROR: Password must contains at least 6 characters, including at least one digit and one character that is neither a letter nor a digit" << endl;
		}
		
	} while (!valid);
	
	cout << "Age: ";
	cin >> voter.age;
	
	cout << "Street number: ";
	cin >> voter.streetNumber;
	
	cout << "Street name: ";
	cin.ignore();
	getline(cin, voter.streetName);
	
	cout << "Town: ";
	getline(cin, voter.town);
	
	do
	{
		cout << "ZIP code: ";
		cin >> voter.zipCode;
		
		valid = true;
		
		if (voter.zipCode.length() == 5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (!isdigit(voter.zipCode.at(i)))
				{
					valid = false;
				}
			}
		}
		else
		{
			valid = false;
		}
		
		if (!valid)
		{
			cout << "ERROR: ZIP code must contain exactly 5 digits" << endl;
		}
		
	} while (!valid);
	
	voter.amountDonated = 0.0;
	
	numberOfVoters++;
}

void VoterDB::ReportVoters(void)
{
	cout << endl << "Number of voters: " << numberOfVoters << endl
		<< "Monet donated to the campaing: $" << totalAmountDonated << 
		endl;
}

void VoterDB::Save(void)
{
	int i;
	ofstream fout;
	string fileName;
	string proceed;
	
	cout << endl << "Name of the file: ";
	cin >> fileName;
	
	if (fstream{fileName})
	{
		cout << endl << "WARNING: File already exists, proceed? Yes or No: ";
		cin >> proceed;
		
		if (proceed == "Yes")
		{
			fout.open(fileName);
			
			fout.clear();
			
			for(i = 0; i < numberOfVoters; i++)
			{
				fout << voter[i].lastName << ',' << voter[i].firstName 
					<< ',' << voter[i].userId << ',' << 
					voter[i].password << ',' << voter[i].age << ',' << 
					voter[i].streetNumber << ',' << voter[i].streetName 
					<< ',' << voter[i].town << ',' << voter[i].zipCode 
					<< ',' << voter[i].amountDonated << endl;
			}
				
			fout.close();
		}
		else
		{
			cout << endl << "Save cancelled" << endl;
		}
	}
	else
	{
		fout.open(fileName);
		
		for(i = 0; i < numberOfVoters; i++)
		{
			fout << voter[i].lastName << ',' << voter[i].firstName << 
			',' << voter[i].userId << ',' << voter[i].password << ',' << 
			voter[i].age << ',' << voter[i].streetNumber << ',' << 
			voter[i].streetName << ',' << voter[i].town << ',' << 
			voter[i].zipCode << ',' << voter[i].amountDonated << endl;
		}
		
		fout.close();
	}
}

void VoterDB::Load(ifstream& fin)
{
	string temp;
	
	getline(fin, temp, ',');
	
	while (fin)
	{
		voter[numberOfVoters].lastName = temp;
		
		getline(fin, voter[numberOfVoters].firstName, ',');
		
		getline(fin, voter[numberOfVoters].userId, ',');
		
		getline(fin, voter[numberOfVoters].password, ',');
		
		getline(fin, temp, ',');
		voter[numberOfVoters].age = stoi(temp);
		
		getline(fin, temp, ',');
		voter[numberOfVoters].streetNumber = stoi(temp);
		
		getline(fin, voter[numberOfVoters].streetName, ',');
		
		getline(fin, voter[numberOfVoters].town, ',');
		
		getline(fin, voter[numberOfVoters].zipCode, ',');
		
		fin >> voter[numberOfVoters].amountDonated;
		
		fin.ignore();
		
		totalAmountDonated += voter[numberOfVoters].amountDonated;
					
		numberOfVoters++;
		
		getline(fin, temp, ',');
	}
}
