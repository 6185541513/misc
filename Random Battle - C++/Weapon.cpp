#include <random>
#include <string>
#include <sstream>
#include <iostream>
#include "Weapon.h"
using namespace std;

Weapon::Weapon(char *c, int i1, int i2) :
name(c), attack_min(i1), attack_max(i2) {}

Weapon* createWeapon(){
//name
	//names to randomize
	char *adjectives[5] = { "Bloody ", "Sweet ", "Awkward ", "Fugly ", "Mighty " };
	char *types[5] = { "Toothpick ", "Crow Beak ", "Scythe ", "Storm Caller ", "Sock " };
	char *subtitles[5] = { "of the Horse Market", "of the Lame Lands", "of Sorrow", "of Dreamfall", "of Godly Horrors" };

	//building string
	ostringstream oss;
	oss << adjectives[rand() % 5] << types[rand() % 5] << subtitles[rand() % 5];
	string str = oss.str();

	//turning string to char pointer
	char* name = new char[str.size() + 1];
	name[str.size()] = 0;
	memcpy(name, str.c_str(), str.size());

//attack
	int attack_min = (rand()% 3 + 10);
	int attack_max = (rand()% 3 + 14);

//creating and returning new Weapon
	return new Weapon(name, attack_min, attack_max);
}

void showWeaponInfo(Weapon *w){
	int i = (w->attack_max) - (w->attack_min);
	cout << "Weapon name: " << w->name << endl;
	cout << "Weapon ap: " << w->attack_min << "(+" << i << ")" << endl;
}

void destroyWeapon(Weapon *w){
	delete w->name;
	delete w;
}