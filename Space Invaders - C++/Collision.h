#ifndef COLLISION_H
#define COLLISION_H

#include "Window.h"
namespace engine{
	class Collision{
	public:
		/*Member functions*/
		void setWindow(Window* win_ptr);
		bool outsideScreen(SDL_Rect* rect);
		bool collisionDetected(SDL_Rect* rect1_ptr, SDL_Rect* rect2_ptr);
	private:
		/*Variables*/
		Window* window_ptr = NULL;
	};
}
#endif