#include <random>
#include <iomanip>
#include "Header.h"

//in charge of battle rounds
void battle(Player &user, int bet){
	//initialize, and declare some, variables for later use
	system("cls");
	int round = 1;
	int firstThrow, secondThrow, throwsUser, throwsAI;
	int winUser = 0;
	int winAI = 0;

	bool keepPlaying = true;
	
	//start battle rounds
	while (keepPlaying){
		//rolls set for player
		firstThrow = rand() % 6;
		secondThrow = rand() % 6;
		throwsUser = firstThrow + secondThrow;
		
		//first round info
		cout << "*****ROUND " << round << "*****" << endl;
		cout << left << setw(10) << "[Player]";
		cout << right << setw(10) << "[Throw]" << endl;

		//player info
		cout << left << setw(10) << user.name;
		cout << right << setw(5) << throwsUser << "(" << firstThrow << " + " << secondThrow << ")" << endl;

		//rolls set for ai + info
		firstThrow = rand() % 6 + 1;
		secondThrow = rand() % 6 + 1;
		throwsAI = firstThrow + secondThrow;
		cout << left << setw(10) << "A.I.";
		cout << right << setw(5) << throwsAI << "(" << firstThrow<< " + " << secondThrow << ")" << endl;

		//winner announced
		if (throwsUser > throwsAI){
			++winUser;
			cout << "*" << user.name << " won this round*";
		}
		else if (throwsAI > throwsUser){
			++winAI;
			cout << "*A.I. won this round*";
		}
		else{
			cout << "**TIE**";
		}
		cout << "\n\n" << user.name <<" win: " << winUser << ", AI win: " << winAI << endl;
		cin.ignore();
		system("cls");
		++round;
		if (round > 3 || winUser == 2 || winAI == 2){
			keepPlaying = false;
		}
	}

	//if battle over, show info
	if (winUser > winAI){
		user.money += bet;
		cout << "*****The game is finished. " << user.name << " won*****\n" 
			<< user.name << " won " << bet  << " and has in total " 
			<< user.money << " credits." << endl;
		cin.ignore();
	}
	else if (winAI > winUser){
		user.money = (user.money - bet);
		if (user.money > 0){
			cout << "*****The game is finished. A.I. won*****\n"
				<< "But don't fret, sweetheart, you still have " << user.money
				<< " credits left to play with." << endl;
		}
		else{
			cout << "*****The game is finished. A.I. won*****\n"
				<< "But don't fret, sweetheart, you can put in more credits and keep playing." << endl;
		}
		cin.ignore();
	}
	else{
		cout << "wtf.. tie" << endl;
		cin.ignore();
	}

	system("cls");
}
