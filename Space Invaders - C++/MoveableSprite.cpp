#include "MoveableSprite.h"
namespace engine{
	/*Constructor that send all values to Sprite constructor and initializes speed to 15*/
	MoveableSprite::MoveableSprite(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height) : Sprite(txtr_ptr, x_value, y_value, width, height){
		speed = 15;
	}

	/*Moves the rects x position according to argument value*/
	void MoveableSprite::moveX(int newX){
		rect.x = newX;
	}

	/*Moves the rects y position according to argument value*/
	void MoveableSprite::moveY(int newY){
		rect.y = newY;
	}

	/*Sets a speed*/
	void MoveableSprite::setSpeed(int newSpeed){
		speed = newSpeed;
	}

	/*Destructor*/
	MoveableSprite::~MoveableSprite(){

	}

}
