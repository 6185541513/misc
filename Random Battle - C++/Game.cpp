#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Game.h"
using namespace std;

void doBattle(Player *p1, Player *p2){
//decide who goes first
	Player* players[2] = { p1, p2 };
	int firstPlayer = rand() % 2;
	int secondPlayer;
	if (firstPlayer == 0){
		secondPlayer = 1;
	}
	else{
		secondPlayer = 0;
	}

//start battle rounds
	int round = 1;
	while (players[firstPlayer]->health > 0 && players[secondPlayer]->health > 0){
		system("cls");
		cout << "*****ROUND " << round << "*****" << endl;
		attack(players[firstPlayer], players[secondPlayer]);
		if (players[firstPlayer]->health > 0 && players[secondPlayer]->health > 0){
			attack(players[secondPlayer], players[firstPlayer]);
		}
		++round;
	}
}

void attack(Player *attacker, Player *victim){
//do damage
	int interval = (attacker->weapon->attack_max) - (attacker->weapon->attack_min);
	int damage = rand() % interval + (attacker->weapon->attack_min) - (victim->armour->armourclass);
	if (damage < 0){
		damage = 0;
	}
	victim->health = (victim->health - damage);

//narrate battle
	cout << attacker->name << attacker->type << " wields the " << attacker->weapon->name
		<< " against " << victim->name << victim->type << "'s " << victim->armour->name
		<< ", and does " << damage << " of damage. " << victim->name
		<< " has " << victim->health << " hp left." << endl;
	cin.ignore();

//if battle is over
	if (victim->health < 1){
		system("cls");
		cout << "*****Battle is over*****\n" << attacker->name << attacker->type << " sent "
			<< victim->name << victim->type << " to the Fires of Hell." << endl;
		cin.ignore();
	}
}
