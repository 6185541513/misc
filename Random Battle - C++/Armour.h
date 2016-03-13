#ifndef A_H
#define A_H
struct Armour{
	Armour(char *c, int i);
	char* name;
	int armourclass;
};
Armour* createArmour();
void showArmourInfo(Armour *a);
void destroyArmour(Armour *a);
#endif