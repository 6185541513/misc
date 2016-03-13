#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL.h>

namespace engine{

	struct Rectangle : public SDL_Rect{
		Rectangle();
		Rectangle(int x_value, int y_value, int width, int height);
	};

}
#endif