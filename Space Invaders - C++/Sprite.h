#ifndef SPRITE_H
#define SPRITE_H
#include "Rectangle.h"
#include "Collision.h"

namespace engine{
	class Sprite{
		Sprite(Sprite& other);
	protected:
		/*Variables*/
		int speed;//bort
		SDL_Texture* texture;
		Rectangle rect;
		Collision* collision_pointer;

		/*Member functions*/
		Sprite(SDL_Texture* tex, int x_value, int y_value, int width, int height);
		Sprite();
	public:
		/*Member functions*/
		virtual ~Sprite();
		virtual void update(){};
		void setCollisionPointer(Collision* col_point);//b
		SDL_Texture* getTexture();
		SDL_Rect* getRect();
		virtual	SDL_Rect* getSourceRect(){ return NULL; };
		friend struct EntityFactory;
	};
}
#endif