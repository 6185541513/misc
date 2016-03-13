#include "Collision.h"

namespace engine{
	/*Checks for screen collision, returns true if collision occured*/
	bool Collision::outsideScreen(SDL_Rect* rect){
		if (rect->x <= 0 || rect->x + rect->w > window_ptr->getX()){
			return true;
		}
		return false;
	}

	/*Set pointer to window*/
	void Collision::setWindow(Window* win_ptr){
		window_ptr = win_ptr;
	}

	/*Checks for collision between two objects according to standard aabb collision check. Returns true if collision occured.*/
	bool Collision::collisionDetected(SDL_Rect* rect1_ptr, SDL_Rect* rect2_ptr){
		if ((rect1_ptr->x + rect1_ptr->w) >= (rect2_ptr->x) && rect1_ptr->x <= (rect2_ptr->x + rect2_ptr->w) && (rect1_ptr->y + rect1_ptr->h) >= rect2_ptr->y && rect1_ptr->y <= (rect2_ptr->y + rect2_ptr->h)){
			return true;
		}
		return false;
	}
}