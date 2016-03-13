#include <ctime>
#include "Header.h"

int main(){
	//seed for random
	srand((unsigned int)time(0));

	//intro scene + create player
	string name;
	int bet;
	cout << "Welcome, friend. Please state your name: " << endl;
	cin >> name;
	cout << "Pleased to meet you, " << name << ". How much is your first bet? (100/300/500)" << endl;
	cin >> bet;
	while (bet != 100 && bet != 300 && bet != 500){
		cout << "It's not an utopia, darling, chose one of the available amounts (100/300/500):" << endl;
		cin >> bet;
	}

	Player user = Player(name);

	cout << bet << "? Well, high rollah, may the odds be ever in your favour." << endl << endl;
	cout << "(Throughout the game you should press Enter to keep going... try it now " << name << ", don't be afraid.)" << endl;
	cin.ignore();//clear cin
	cin.ignore();//wait for enter keypress
	
	//battle rounds begin
	string answer;
	do{
		battle(user, bet);
		cout << "Do you wish to continue the battle?(yes/no)" << endl;
		cin >> answer;
		while(answer != "yes" && answer != "no"){
			cout << "Sorry, I didn't catch that. A simple yes or no is more in my capacity to understand:" << endl;
			cin >> answer;
		}
		//if user wants to continue game we ask for new bet etc..
		if (answer == "yes"){
			if (user.money > 0){
				cout << "You have " << user.money << " credits left, how much are you sacrificing for the next round? " << endl;
				cin >> bet;
			}
			else{
				cout << "You have no credits left babe, how much will you put into your account (max 5000)?" << endl;
				cin >> user.money;
				while (user.money > 5000 || user.money <= 0){
					cout << "That's not an appropriate amount. Please try a different one (1-5000):" << endl;
					cin >> user.money;
				}
				cout << user.money << ", huh? And how many of these credits do you wish to spend?" << endl;
				cin >> bet;
			}
			while (bet > user.money){
				cout << "Can't spend more than you're making, honey. Place a new bet: " << endl;
				cin >> bet;
			}
			cin.ignore();
		}
	} while (answer != "no");
	cin.ignore();
	system("cls");
	cout << "Farewell, old chap" << endl;
	cin.ignore();
	return 0;
}
