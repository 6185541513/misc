#ifndef ENEMY_COUNTER_H
#define ENEMY_COUNTER_H
#include "TextField.h"

class EnemyCounter : public TextField{
	friend struct EntityFactory;
public:
	~EnemyCounter();
	void increment();
	int getEnemiesKilled();
private:
	EnemyCounter(std::string textIn, SDL_Texture* txtr_ptr, int x, int y, int width, int height);
	EnemyCounter(EnemyCounter& other);
	EnemyCounter();
	int enemiesKilled = 0;
};

#endif