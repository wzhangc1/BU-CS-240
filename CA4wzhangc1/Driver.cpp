#include "Tournament.h"

using namespace std;

int main(int argc, char *argv[])
{
	bool valid;
	ifstream fin;
	int i;
	int numberOfPlayers;
	string tempStr;
	
	fin.open(argv[1]);
	
	numberOfPlayers = 0;
	
	while (fin >> tempStr)
	{		
		numberOfPlayers++;	
	}
	
	switch (numberOfPlayers)
	{
		case 2:
		case 4:
		case 8:
		case 16:
		case 32:
		case 64:
			valid = true;
			break;
		default:
			valid = false;
	}
	
	cout << numberOfPlayers << endl;
	
	if (valid)
	{
		Tournament tournament(numberOfPlayers);
		
		fin.clear();
		fin.seekg(0, ios::beg);
		
		for (i = numberOfPlayers-1; i < 2*numberOfPlayers-1; i++)
		{
			fin >> tournament.bracket[i].name;
		}
		
		tournament.playTournament();
		
		cout << fixed << setprecision(2);
		
		cout << endl << tournament.winner.name << " won the tournament!" 
			<< endl;
		
		cout << "The average number of battles is " << 
			(double)tournament.totalNumberOfBattles / 
			tournament.numberOfGames << endl;
			
		cout << "The largest number of battles is " << 
			tournament.largestNumberOfBattles << endl;
	}
	else
	{
		cout << "ERROR - Invalid number of players" << endl;
	}
	
	return 0;
}
