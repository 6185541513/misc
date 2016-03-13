#include "Sprite.h"

namespace engine{
	/*Constructor, sends all values to rect but the texture pointer that it sets to its texture*/
	Sprite::Sprite(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height) : rect(x_value, y_value, width, height){
		texture = txtr_ptr;
	}

	/*Returns its texture*/
	SDL_Texture* Sprite::getTexture(){
		return texture;
	}

	/*Returns its rect*/
	SDL_Rect* Sprite::getRect(){
		return &rect;
	}

	/*Sets collision pointer*/
	void Sprite::setCollisionPointer(Collision* col_point){
		collision_pointer = col_point;
	}

	/*Destructor*/
	Sprite::~Sprite(){
		
	}
}