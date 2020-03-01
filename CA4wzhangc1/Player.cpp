#include "Player.h"

Player::Player(void)
{
	deck = LLC<PlayingCard>();
	name = "";
	numberOfWins = 0;
}

Player::Player(string aName, const LLC<PlayingCard> &aDeck)
{
	name = aName;
	deck = aDeck;
	numberOfWins = 0;
}
