#ifndef MOVEABLE_SPRITE_H
#define MOVEABLE_SPRITE_H
#include "Sprite.h"
namespace engine{
	class MoveableSprite : public Sprite{
		friend struct EntityFactory;
		MoveableSprite();
		MoveableSprite(MoveableSprite& other);
	protected:
		MoveableSprite(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height);
		int speed;
		virtual void updatePos(){};
		void moveX(int newX);
		void moveY(int newY);
	public:
		virtual ~MoveableSprite();
		enum moves{ UP, DOWN, LEFT, RIGHT, STILL, ATTACK };
		void setSpeed(int newSpeed);
	};
}

#endif