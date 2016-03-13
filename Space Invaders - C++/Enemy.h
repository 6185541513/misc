#ifndef ENEMY_H
#define ENEMY_H

#include <stdlib.h>
#include <time.h>
#include "MoveableSprite.h"
#include "Bullet.h"

class Enemy : public engine::MoveableSprite{
	friend struct EntityFactory;
public:
	/*Variables*/
	static const int FRAME_WIDTH = 40;
	static const int FRAME_HEIGHT = 30;
	/*Member functions*/
	~Enemy();
	void update();
	SDL_Rect* getSourceRect();
	moves getDirection();
	static Enemy* getInstance(SDL_Texture* txtr_ptr, int x_value, int y_value);
	void setSpeed(int newSpeed);
private:
	/*Variables*/
	static engine::MoveableSprite::moves currentDirection;
	int tick = 0;
	int frame = 0;
	int attackCountdown = 0;
	int attackFrequency;
	bool timeToAttack = false;

	/*Member functions*/
	Enemy(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height);
	Enemy();
	Enemy(Enemy& other);
	void updatePos();
	moves changeDirection();
	void updateAttack();
	void changeFrame();
};
#endif