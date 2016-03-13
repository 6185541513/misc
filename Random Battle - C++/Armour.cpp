#include <iostream>
#include <string>
#include <sstream>
#include "Armour.h"
using namespace std;

Armour::Armour(char *c, int i) : name(c), armourclass(i) {}

Armour* createArmour(){
//name
	char *adjectives[5] = {"Studded ", "Wooden ", "Disgusting ", "Glorious ", "Broken "};
	char *types[5] = {"blanket ", "fedora ", "armour ", "cloth ", "plank "};
	char *subtitles[5] = {"of Killers' Teeth", "on Sale", "of Milk Threads", "of Rotten Flesh", "of Boredom"};
	
	//building string
	ostringstream oss;
	oss << adjectives[rand() % 5] << types[rand() % 5] << subtitles[rand() % 5];
	string str = oss.str();

	//turning string to char array pointer
	char* name = new char[str.size() + 1];
	name[str.size()] = 0;
	memcpy(name, str.c_str(), str.size());

//attack
	int armourclass = (rand() % 3 + 3);

//creating and returnning new Armour
	return new Armour(name, armourclass);
}

void showArmourInfo(Armour *a){
	cout << "Armour name: " << a->name << endl;
	cout << "Armour class: " << a->armourclass << endl;
}

void destroyArmour(Armour *a){
	delete a->name;
	delete a;
}
