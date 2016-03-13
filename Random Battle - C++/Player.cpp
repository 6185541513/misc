#include <random>
#include <string>
#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(char *c1, char *c2, int i) : name(c1), type(c2), health(i) {}

Player* createPlayer(char *name, char *type, Weapon *w, Armour *a){
//name
	char *names[5] = {"Arwen ", "Karl ", "Bertha ", "Baboo ", "Lollys "};
	string sn = names[rand() % 5];

	char *n = new char[sn.size() + 1];
	n[sn.size()] = 0;
	memcpy(n, sn.c_str(), sn.size());
	name = n;

//type
	char *types[5] = { "the Awkward", "the Horribly Humid", "the Sickly", "the Lovley With all the Good Fat", "the Passive-Agressive" };
	string st = types[rand() % 5];
 
	char *t = new char[st.size() + 1];
	t[st.size()] = 0;
	memcpy(t, st.c_str(), st.size());
	type = t;

//health
	int health = (rand() % 10 + 15);

//create Player, equip it, return
	Player *p = new Player(name, type, health);
	equipPlayerWeapon(p, w);
	equipPlayerArmour(p, a);
	return p;
}

void destroyPlayer(Player *p){
	delete[] p->name;
	delete[] p->type;
	delete p;
}

void showPlayerInfo(Player *p){
	cout << p->name << p->type << " has " << p->health << " hp left." << endl;
}

void equipPlayerWeapon(Player *p, Weapon *w){
	p->weapon = w;
}

void equipPlayerArmour(Player *p, Armour *a){
	p->armour = a;
}
