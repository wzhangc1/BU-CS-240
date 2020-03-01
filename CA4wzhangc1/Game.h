#include "Player.h"

using namespace std;

class Game
{
public:
	Player player1;
	Player player2;
	LLC<PlayingCard> pile;
	int numberOfBattles;
	int numberOfWars;
	
public:
	Game(void);
	Player play(void);
	void battle(void);
	void war(void);
	void shuffleDeck(void);
	void dealCards(void);
};
