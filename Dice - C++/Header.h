#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
using namespace std;

struct Player{
	Player(string n);
	string name;
	int money;
};
void battle(Player &user, int bet);
#endif