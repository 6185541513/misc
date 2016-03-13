#include "Header.h"

string answer;
int main(){
	//seed for random
	srand((unsigned int)time(0));

	//intro scene + create deck and players
	string name = intro();
	Deck deck;
	Player players[2] = { name, "Computer" };

	//let the games begin...
	do{
		deck.initializeDeck();
		deck.shuffleDeck();
		game(deck, players);
		keepPlaying();
	} while (answer != "no");

	cin.ignore();
	exit(players);
	return 0;
}

//intro
string intro(){
	string name;
	cout << "Hey, sweet thing, what is your name?" << endl;
	cin >> name;
	cout << "Ok, " << name << ", time to play some cards. \n\nOh, and remember to always press Enter to move further into the game. Try it now." << endl;
	cin.ignore();
	return name;
}

//question if continue game
void keepPlaying(){
	cout << "\n\n\nDo you wish to continue game(yes/no)?" << endl;
	cin >> answer;

	while(answer != "no" && answer != "yes"){
		cout << "Didn't really catch that, a simple yes or no would be perfect:" << endl;
		cin >> answer;
	}
}

//exit game
void exit(Player players[2]){
	system("cls");
	cout << "Your total wins are " << players[0].wins << ", and losses are " << players[0].losses << "\nFarewell now." << endl;
	cin.ignore();
}


