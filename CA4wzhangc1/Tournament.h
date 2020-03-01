#include "Game.h"

using namespace std;

class Tournament
{
public:
	int largestNumberOfBattles;
	int numberOfGames;
	int totalNumberOfBattles;
	Player winner;
	Player* bracket;
	
public:
	Tournament(int aNumberOfPlayers);
	void playTournament(void);
	Player playMatch(int parentIndex);
};
