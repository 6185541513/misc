#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

struct Player{
	Player(string n);
	string name;
	int wins;
	int losses;
};

#endif