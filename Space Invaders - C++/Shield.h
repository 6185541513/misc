#ifndef SHIELD_H
#define SHIELD_H
#include "Sprite.h"


class Shield : public engine::Sprite{
	friend struct EntityFactory;
public:
	static const int FRAME_WIDTH = 155;
	static const int FRAME_HEIGHT = 79;
	static std::string IMG_PATH;

	~Shield();
	static Shield* getInstance(SDL_Texture* txtr_ptr, int x_value, int y_value);
private:
	Shield(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height);
	Shield();
	Shield(Shield& other);
};
#endif