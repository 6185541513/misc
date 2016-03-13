#include "Deck.h"

//initialze deck
void Deck::initializeDeck(){
	for (int i = 0; i < 52; i++){
		deckOfCards[i] = i + 1;
	}
	usedCards[6] = { 0 };
	nextSpace = 0;
}

//Fisher-Yates shuffle algorithm to randomly shuffle cards in deck
void Deck::shuffleDeck(){
	int index = 52;
	int i_toSwap;
	while (index > 0){
		i_toSwap = rand() % index;
		swap(i_toSwap, index);
		--index;
	}
}

//swap used in Fisher-Yates
void Deck::swap(int i_toSwap, int index){
	int temp = deckOfCards[i_toSwap];
	deckOfCards[i_toSwap] = deckOfCards[index];
	deckOfCards[index] = temp;
}

//present card in string
string Deck::prestentCard(int cardNumber){
	string nameOfCards[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Knight", "Queen", "King"};
	if (cardNumber < 14){
		return (nameOfCards[cardNumber - 1] + " of Spades");
	}
	else if (cardNumber < 27){
		return (nameOfCards[cardNumber - 14] + " of Hearts");
	}
	else if (cardNumber < 40){
		return (nameOfCards[cardNumber - 27] + " of Diamonds");
	}
	else{
		return (nameOfCards[cardNumber - 40] + " of Clubs");
	}
}

//get int value of card
int Deck::getCardValue(int cardNumber){
	if (cardNumber < 14){
		return cardNumber;
	}
	else if (cardNumber < 27){
		return cardNumber - 13;
	}
	else if (cardNumber < 40){
		return cardNumber - 26;
	}
	else{
		return cardNumber - 39;
	}
}

//erase drawn card from deck + add drawn card to array for already drawn cards
void Deck::eraseCard(int index, int drawnCard){
	deckOfCards[index] = 0;
	usedCards[nextSpace] = drawnCard;
	nextSpace++;
}

//draw card
int Deck::drawCard(){
	int index = rand() % 52;
	int card = deckOfCards[index];
	while (card == 0){
		index = rand() % 52;
		card = deckOfCards[index];
	}

	eraseCard(index, card);
	return card;
}



