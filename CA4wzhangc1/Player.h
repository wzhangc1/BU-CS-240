#include "LLC.cpp"
#include "PlayingCard.h"

using namespace std;

class Player
{
public:
	LLC<PlayingCard> deck;
	string name;
	int numberOfWins;
	
public:
	Player(void);
	Player(string aName, const LLC<PlayingCard> &aDeck);
};
