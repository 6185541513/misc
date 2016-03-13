#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Player.h"
#include "Weapon.h"
#include "Armour.h"
#include "Game.h"
using namespace std;

int main(){

//rnd
	srand((unsigned int)time(0));

//weapons
	Weapon* weapons[2] = { 0 };
	for (int i = 0; i < 2; i++){
		weapons[i] = createWeapon();
	}

//armours
	Armour* armours[2] = { 0 };
	for (int i = 0; i < 2; i++){
		armours[i] = createArmour();
	}

//players
	Player* p1 = createPlayer("name", "type", weapons[0], armours[0]);
	Player* p2 = createPlayer("n4m3", "7yp3", weapons[1], armours[1]);

//intro scene
	cout << "*****PLAYER ONE*****" << endl;
	showPlayerInfo(p1);
	showWeaponInfo(p1->weapon);
	showArmourInfo(p1->armour);

	cout << "\n*****PLAYER TWO*****" << endl;
	showPlayerInfo(p2);
	showWeaponInfo(p2->weapon);
	showArmourInfo(p2->armour);

//let the games begin...
	cin.ignore();
	doBattle(p1, p2);

//destroy what's been created
	destroyPlayer(p1);
	destroyWeapon(weapons[0]);
	destroyArmour(armours[0]);

	destroyPlayer(p2);
	destroyWeapon(weapons[1]);
	destroyArmour(armours[1]);

//done and done
	return 0;
}

