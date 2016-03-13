#ifndef W_H
#define W_H
struct Weapon{
	Weapon(char *c, int i1, int i2);
	char *name;
	int attack_min;
	int attack_max;
};
Weapon* createWeapon();
void showWeaponInfo(Weapon *w);
void destroyWeapon(Weapon *w);
#endif