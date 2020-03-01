#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class PlayingCard
{
private:
	int rank;
	char suit;
	
public:
	PlayingCard(void);
	
	int getRank(void);
	char getSuit(void);
	
	void setRank(int aRank);
	void setSuit(char aSuit);
	
	bool operator==(const PlayingCard &playingCard);
	friend ostream& operator<<(ostream &out, const PlayingCard& playingCard);
};
