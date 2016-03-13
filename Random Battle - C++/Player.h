#ifndef P_H
#define P_H
struct Weapon;
struct Armour;
struct Player{
	Player(char *c1, char *c2, int i);
	char *name;
	char *type;
	int health;
	Weapon *weapon;
	Armour *armour;
	char* getName();
};
Player* createPlayer(char *name, char *type, Weapon *w, Armour *a);
void destroyPlayer(Player *p);
void showPlayerInfo(Player *p);
void equipPlayerWeapon(Player *p, Weapon *w);
void equipPlayerArmour(Player *p, Armour *a);
#endif