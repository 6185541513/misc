#include <iostream>
using namespace std;

void magic(int &noOf, int &change, int current);
void registerCalc(){
	cout << "\nregisterCalc():" << endl;
	int sum;
	int paid;
	int change;
	int noOf;

	cout << "what is sum?" << endl;
	cin >> sum;

	cout << "what did hen pay?" << endl;
	cin >> paid;

	change = (paid - sum);
	
	cout << "\n------\nMoney back: " << endl;
	magic(noOf, change, 100);
	cout << "\hundreds: " << noOf << endl;

	magic(noOf, change, 50);
	cout << "\nfiftys: " << noOf << endl;

	magic(noOf, change, 20);
	cout << "\ntwenties: " << noOf << endl;

	magic(noOf, change, 10);
	cout << "\ntens: " << noOf << endl;

	magic(noOf, change, 5);
	cout << "\fives: " << noOf << endl;

	magic(noOf, change, 1);
	cout << "\nones:" << noOf << endl;
}

void magic(int &noOf, int &change, int current){
	noOf = change / current;
	change = change % current;
}