#include "PlayingCard.h"

PlayingCard::PlayingCard(void)
{
	rank = 0;
	suit = ' ';
}

int PlayingCard::getRank(void)
{
	return rank;
}

char PlayingCard::getSuit(void)
{
	return suit;
}

void PlayingCard::setRank(int aRank)
{
	rank = aRank;
}
void PlayingCard::setSuit(char aSuit)
{
	suit = aSuit;
}

bool PlayingCard::operator==(const PlayingCard &playingCard)
{
	bool match;
	
	if (rank == playingCard.rank && suit == playingCard.suit)
	{
		match = true;
	}
	else
	{
		match = false;
	}
	
	return match;
}

ostream& operator<<(ostream &out, const PlayingCard& playingCard)
{
	switch (playingCard.rank)
	{
		case 10:
			cout << 'T';
			break;
		case 11:
			cout << 'J';
			break;
		case 12:
			cout << 'Q';
			break;
		case 13:
			cout << 'K';
			break;
		case 14:
			cout << 'A';
			break;
		default:
			cout << playingCard.rank;
	}
	
	cout << playingCard.suit;
}
