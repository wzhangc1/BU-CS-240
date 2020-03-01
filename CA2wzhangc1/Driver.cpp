#include "VoterDB.h"

int main(int argc, char **argv)
{
	int index;
	int maxVoters;
	
	string command;
	
	maxVoters = stoi(argv[1]);
	
	if (maxVoters >= 1 && maxVoters <= 1000)
	{
		VoterDB database = VoterDB(maxVoters);
		
		if (argv[2] != NULL)
		{
			if (fstream{argv[2]})
			{			
				ifstream fin;
				
				fin.open(argv[2]);
				
				database.Load(fin);
				
				fin.close();
			}
			else
			{
				cout << endl << "ERROR: File does not exists" << endl;
			}
		}
	
		index = -1;
		
		cout << fixed << setprecision(2);
		
		do
		{
			if (index == -1)
			{
				cout << endl << "Enter the one following commands: Login, New, Report, Save, Load, or Quit" << endl;

				cin >> command;
				
				if (command == "Login")
				{
					index = database.Login();
				}
				else if (command == "New")
				{
					if (database.numberOfVoters < maxVoters)
					{
						database.New(database.voter[database.numberOfVoters]);
					}
					else
					{
						cout << endl << "ERROR: Maximum number of voters reached" << endl;
					}
				}
				else if (command == "Report")
				{
					database.ReportVoters();
				}
				else if (command == "Save")
				{
					database.Save();
				}
				else if (command == "Load")
				{
					VoterDB database = VoterDB(maxVoters);
					
					string fileName;
	
					cout << endl << "Name of the file: ";
					cin >> fileName;
					
					if (fstream{fileName})
					{
						ifstream fin;
						
						fin.open(fileName);
						
						database.Load(fin);
				
						fin.close();
					}
					else
					{
						cout << endl << "ERROR: File does not exist" << endl;
					}
				}
			}
			else
			{
				do
				{
					cout << endl << "Enter the one following commands: Update, Passwd, View, Donate, Report, or Logout" << endl;
		
					cin >> command;
					
					if (command == "Update")
					{
						database.voter[index].Update();
					}
					else if (command == "Passwd")
					{
						database.voter[index].Passwd();
					}
					else if (command == "View")
					{
						database.voter[index].View();
					}
					else if (command == "Donate")
					{
						database.voter[index].Donate(database.totalAmountDonated);
					}
					else if (command == "Report")
					{
						database.voter[index].Report();
					}
					
				} while(command != "Logout");
				
				index = -1;
			}
			
		} while(command != "Quit");
	}
	
	return 0;
}
