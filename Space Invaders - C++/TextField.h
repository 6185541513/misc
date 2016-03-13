#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include "Sprite.h"


class TextField : public engine::Sprite{
	friend struct EntityFactory;
public:
	~TextField();
	static TextField* getInstance(std::string textIn, SDL_Texture* txtr_ptr, int x, int y, int width, int height);
protected:
	TextField(std::string textIn, SDL_Texture* txtr_ptr, int x, int y, int width, int height);
	TextField(TextField& other);
	TextField();
	std::string text;
};

#endif