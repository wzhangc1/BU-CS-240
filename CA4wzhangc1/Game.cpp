#include "Game.h"

Game::Game(void)
{
	player1 = Player();
	player2 = Player();
}

Player Game::play(void)
{
	Node<PlayingCard>* ptr;
	Player winner;
	
	numberOfBattles = 0;
	numberOfWars = 0;
	
	cout << "===" << endl << player1.name << " VS. " << player2.name << 
		endl;
	
	while (player1.deck.first != NULL && player2.deck.first != NULL)
	{
		battle();
		
		if (numberOfBattles % 1000 == 0)
		{
			player1.deck.shuffle();
			player2.deck.shuffle();
		}
	}
	
	if (player2.deck.first == NULL)
	{
		player1.numberOfWins++;
		
		cout << player1.name << " (" << player1.numberOfWins << 
			") DEFEATED " <<  player2.name << " in " << numberOfBattles 
			<< " Battles and " << numberOfWars << " Wars" << endl;
		
		while (player1.deck.first != NULL)
		{
			ptr = player1.deck.first->next;
			delete player1.deck.first;
			player1.deck.first = ptr;
		}
		
		winner = player1;
	}
	else
	{
		player2.numberOfWins++;
		
		cout << player2.name << " (" << player2.numberOfWins << 
			") DEFEATED " <<  player1.name << " in " << numberOfBattles 
			<< " Battles and " << numberOfWars << " Wars" << endl;
		
		while (player2.deck.first != NULL)
		{
			ptr = player2.deck.first->next;
			delete player2.deck.first;
			player2.deck.first = ptr;
		}
		
		winner = player2;
	}
	
	return winner;
}
void Game::battle(void)
{
	PlayingCard playingCard1;
	PlayingCard playingCard2;
	Node<PlayingCard>* ptr;
	
	numberOfBattles++;
	
	playingCard1 = player1.deck.first->data;
	pile.insert(player1.deck.first->data);
	ptr = player1.deck.first->next;
	delete player1.deck.first;
	player1.deck.first = ptr;
	
	playingCard2 = player2.deck.first->data;
	pile.insert(player2.deck.first->data);
	ptr = player2.deck.first->next;
	delete player2.deck.first;
	player2.deck.first = ptr;
	
	if (playingCard1.getRank() > playingCard2.getRank())
	{
		player1.deck.join(pile);
		
		cout << "\tBattle " << numberOfBattles << ": " << player1.name 
			<< " (" << playingCard1 << ") defeated " << player2.name << 
			" (" << playingCard2 << "): " << player1.name << ' ' << 
			player1.deck.len() << ", " << player2.name << ' ' << 
			player2.deck.len() << endl;
	}
	else if (playingCard1.getRank() < playingCard2.getRank())
	{
		player2.deck.join(pile);
		
		cout << "\tBattle " << numberOfBattles << ": " << player2.name 
			<< " (" << playingCard2 << ") defeated " << player1.name << 
			" (" << playingCard1 << "): " << player1.name << ' ' << 
			player1.deck.len() << ", " << player2.name << ' ' << 
			player2.deck.len() << endl;
	}
	else
	{
		cout << "\tBattle " << numberOfBattles << ": " << player1.name 
			<< " (" << playingCard1 << ") tied " << player2.name << " (" 
			<< playingCard2 << ')' << endl;
		
		war();
	}
	
	while (pile.first != NULL)
	{
		ptr = pile.first->next;
		delete pile.first;
		pile.first = ptr;
	}
}
void Game::war(void)
{
	int i;
	PlayingCard playingCard1;
	PlayingCard playingCard2;
	Node<PlayingCard>* ptr;
	
	numberOfWars++;
	
	for (i = 0; i < 4 && i < player1.deck.len(); i++)
	{
		playingCard1 = player1.deck.first->data;
		pile.insert(player1.deck.first->data);
		ptr = player1.deck.first->next;
		delete player1.deck.first;
		player1.deck.first = ptr;
	}
	
	for (i = 0; i < 4 && i < player2.deck.len(); i++)
	{
		playingCard2 = player2.deck.first->data;
		pile.insert(player2.deck.first->data);
		ptr = player2.deck.first->next;
		delete player2.deck.first;
		player2.deck.first = ptr;
	}
	
	if (playingCard1.getRank() > playingCard2.getRank())
	{
		player1.deck.join(pile);
		
		cout << "\tWar " << numberOfWars << ": " << player1.name << " (" 
			<< playingCard1 << ") defeated " << player2.name << " (" << 
			playingCard2 << "): " << player1.name << ' ' << 
			player1.deck.len() << ", " << player2.name << ' ' << 
			player2.deck.len() << endl;
	}
	else if (playingCard1.getRank() < playingCard2.getRank())
	{
		player2.deck.join(pile);
		
		cout << "\tWar " << numberOfWars << ": " << player2.name << " (" 
			<< playingCard2 << ") defeated " << player1.name << " (" << 
			playingCard1 << "): " << player1.name << ' ' << 
			player1.deck.len() << ", " << player2.name << ' ' << 
			player2.deck.len() << endl;
	}
	else
	{
		cout << "\tWar " << numberOfWars << ": " << player1.name << " (" 
			<< playingCard1 << ") tied " << player2.name << " (" << 
			playingCard2 << ')' << endl;
		
		war();
	}
}

void Game::shuffleDeck(void)
{
	int i;
	Node<PlayingCard>* ptr;
	PlayingCard playingCard;
	
	while (pile.first != NULL)
	{
		ptr = pile.first->next;
		delete pile.first;
		pile.first = ptr;
	}
	
	while (player1.deck.first != NULL)
	{
		ptr = player1.deck.first->next;
		delete player1.deck.first;
		player1.deck.first = ptr;
	}
	
	while (player2.deck.first != NULL)
	{
		ptr = player2.deck.first->next;
		delete player2.deck.first;
		player2.deck.first = ptr;
	}
	
	for (i = 2; i <= 14; i++)
	{
		playingCard.setRank(i);
		
		playingCard.setSuit('C');
		pile.insert(playingCard);
		
		playingCard.setSuit('D');
		pile.insert(playingCard);
		
		playingCard.setSuit('H');
		pile.insert(playingCard);
		
		playingCard.setSuit('S');
		pile.insert(playingCard);
	}
	
	pile.shuffle();
}

void Game::dealCards(void)
{
	int i;
	Node<PlayingCard> *ptr;
	
	for (i = 0; i < 26; i++)
	{
		player1.deck.insert(pile.first->data);
		ptr = pile.first->next;
		delete pile.first;
		pile.first = ptr;
		
		player2.deck.insert(pile.first->data);
		ptr = pile.first->next;
		delete pile.first;
		pile.first = ptr;
	}
}
