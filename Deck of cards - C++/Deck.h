#ifndef DECK_H
#define DECK_H
#include <random>
#include <string>
#include <iostream>
using namespace std;

struct Deck{
	int deckOfCards[52];
	int usedCards[6];
	int nextSpace;
	void initializeDeck();
	void shuffleDeck();
	void swap(int s, int i);
	string prestentCard(int cardNumber);
	int getCardValue(int cardNumber);
	void eraseCard(int index, int drawnCard);
	int drawCard();
	int size();
	void printDeck();
};
#endif