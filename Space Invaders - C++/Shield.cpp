#include "Shield.h"

/*Calling a getinstance to allow constructor to be private*/
Shield* Shield::getInstance(SDL_Texture* txtr_ptr, int x_value, int y_value){
	return new Shield(txtr_ptr, x_value, y_value, Shield::FRAME_WIDTH, Shield::FRAME_HEIGHT);
}

/*Setting the image path to the shield*/
std::string Shield::IMG_PATH = "shield.png";

/*Constructor of Shield that passes on its values to Sprite in engine namespace*/
Shield::Shield(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height) : engine::Sprite(txtr_ptr, x_value, y_value, width, height){}

/*Destructor*/
Shield::~Shield(){

}
