#include "Bullet.h"

/*Constructor, passing values on to Sprite constructor. Initializes speed.*/
Bullet::Bullet(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height) : engine::MoveableSprite(txtr_ptr, x_value, y_value, width, height) {
	speed = 20;
}

/*Update bullet by calling relevant update functions*/
void Bullet::update(){
	updatePos();
}

Bullet* Bullet::getInstance(SDL_Texture* txtr_ptr, int x_value, int y_value){
	return new Bullet(txtr_ptr, x_value, y_value, Bullet::FRAME_WIDTH, Bullet::FRAME_HEIGHT); 
}

/*Update position of bullet by changing its y-axis depending on wheter it's moving up or down*/
void Bullet::updatePos(){
	SDL_Rect tmpRect = rect;
	switch (direction){
	case UP:
		tmpRect.y -= speed;
		break;
	case DOWN:
		tmpRect.y += speed;
		break;
	}
	moveY(tmpRect.y);
}

/*Returns rect of bullet that is going to be seen, NULL in this instance to see all*/
SDL_Rect* Bullet::getSourceRect(){
	return NULL;
}

/*Sets direction of bullet*/
void Bullet::setDirection(engine::MoveableSprite::moves direct){
	direction = direct;
}

/*Returns direction of bullet*/
engine::MoveableSprite::moves Bullet::getDirection(){
	return direction;
}

Bullet::~Bullet(){

}