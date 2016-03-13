#ifndef BULLET_H
#define BULLET_H

#include "MoveableSprite.h"

class Bullet : public engine::MoveableSprite{
	friend struct EntityFactory;
public:
	/*Variables*/
	static const int FRAME_WIDTH = 6;
	static const int FRAME_HEIGHT = 17;

	/*Member function*/
	~Bullet();
	void update();
	SDL_Rect* getSourceRect();
	void setDirection(engine::MoveableSprite::moves direction);
	engine::MoveableSprite::moves Bullet::getDirection();
	static Bullet* getInstance(SDL_Texture* txtr_ptr, int x_value, int y_value);
private:
	/*Variables*/
	SDL_Texture* texture_ptr;
	engine::MoveableSprite::moves direction;

	/*Member functions*/
	Bullet(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height);
	Bullet();
	Bullet(Bullet& other);
	void updatePos();
};
#endif