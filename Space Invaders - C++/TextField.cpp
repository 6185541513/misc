#include "TextField.h"

/*Constructor, sends arguments to Sprite, except the string that it sets its text variable to*/
TextField::TextField(std::string textIn, SDL_Texture* txtr_ptr, int x, int y, int width, int heigth) : engine::Sprite(txtr_ptr, x, y, width, heigth){
	text = textIn;
}

/*Returns a Textfield object, this is needed to allow constructor to be private*/
TextField* TextField::getInstance(std::string textIn, SDL_Texture* txtr_ptr, int x, int y, int width, int heigth){
	return new TextField(textIn, txtr_ptr, x, y, width, heigth);
}

/*Destructor*/
TextField::~TextField(){

}