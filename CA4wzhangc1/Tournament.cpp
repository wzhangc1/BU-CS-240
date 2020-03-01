#include "Tournament.h"

Tournament::Tournament(int aNumberOfPlayers)
{
	largestNumberOfBattles = 0;
	numberOfGames = 0;
	totalNumberOfBattles = 0;
	winner = Player();
	bracket = new Player[2*aNumberOfPlayers-1];
}

void Tournament::playTournament(void)
{
	winner = playMatch(0);
}

Player Tournament::playMatch(int parentIndex)
{
	Game game;
	Player winner;
	
	if (bracket[2*parentIndex + 1].name == "")
	{
		bracket[2*parentIndex+1] = playMatch(2*parentIndex + 1);
	}
	
	if (bracket[2*parentIndex+2].name == "")
	{
		bracket[2*parentIndex+2] = playMatch(2*parentIndex + 2);
	}
	
	cout << "Matchday #" << ++numberOfGames << endl << 
		"Press Enter to Continue";
	
	cin.ignore();
	
	game.player1 = bracket[(2*parentIndex)+1];
	game.player2 = bracket[(2*parentIndex)+2];
	
	game.shuffleDeck();
	game.dealCards();
	
	winner = game.play();
	
	totalNumberOfBattles += game.numberOfBattles;
	
	if (game.numberOfBattles > largestNumberOfBattles)
	{
		largestNumberOfBattles = game.numberOfBattles;
	}
	
	return winner;
}
