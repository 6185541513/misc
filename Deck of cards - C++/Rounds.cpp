#include "Header.h"

//game loop
void game(Deck &deck, Player players[2]){
	int count = 1;
	int win_player = 0;
	int win_computer = 0;

	while (count < 4){
		cin.ignore();
		system("cls");
		cout << "***** " << "Round " << count << " *****" << endl;
		round(deck, players, win_player, win_computer);
		count++;
	}

	presentWinner(win_player, win_computer, players);
	presentUsedCards(deck);
}

//single round
void round(Deck &deck, Player players[2], int &win_player, int &win_computer){
	int valueCards[2];
	string presentableCards[2];

	headlineOutput();
	assignValues(deck, valueCards, presentableCards);
	playersOutput(players, presentableCards);
	winnerOutput(valueCards, win_player, win_computer, players, deck);

	cout << "\n\n" << players[0].name << " win: " << win_player << ", Computer win: " << win_computer << endl;
}

//output headline for single round
void headlineOutput(){
	cout << left << setw(10) << "[Player]";
	cout << right << setw(10) << "[Card]" << endl;
}

//assigns values to cards for single round
void assignValues(Deck &deck, int valueCards[2], string presentableCards[2]){
	//value of cards
	for (int i = 0; i < 2; i++){
		valueCards[i] = deck.drawCard();
	}

	//make cards presentable
	for (int i = 0; i < 2; i++){
		presentableCards[i] = deck.prestentCard(valueCards[i]);
	}
}

//output info about players for single round
void playersOutput(Player players[2], string cards[2]){
	for (int i = 0; i < 2; i++){
		cout << left << setw(10) << players[i].name;
		cout << right << setw(5) << cards[i] << endl;
	}
}

//output winner info for single round
void winnerOutput(int cards[2], int &win_player, int &win_computer, Player players[2], Deck deck){
	if (deck.getCardValue(cards[0]) > deck.getCardValue(cards[1])){
		win_player++;
		cout << "\n*" << players[0].name << " won this round*";
	}
	else if (deck.getCardValue(cards[1]) > deck.getCardValue(cards[0])){
		win_computer++;
		cout << "\n*" << players[1].name << " won this round*";
	}
	else{
		cout << "\n**TIE**";
	}
}

//output winner of all rounds
void presentWinner(int win_player, int win_computer, Player players[2]){
	cin.ignore();
	system("cls");
	if (win_player > win_computer){
		cout << "Congrats, you won" << endl;
		players[0].wins++;
	}
	else if (win_computer > win_player)
	{
		cout << "Sorry sweetie, you lost this time" << endl;
		players[0].losses++;
	}
	else{
		cout << "Well look at that, a frikkin tie" << endl;
	}
}

//presents which cards were used after all rounds have played out
void presentUsedCards(Deck deck){
	cout << "\n\nCards that where used during this game where: \n" << endl;
	int count = 0;
	while (deck.usedCards[count] != 0 && count < 6){
		cout << "* " << deck.prestentCard(deck.usedCards[count]) << endl;
		count++;
	}
}

