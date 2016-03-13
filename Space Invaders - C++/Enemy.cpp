#include "Enemy.h"
#include "EntityFactory.h"

/*Initializes first direction, static because all enemies share direction*/
engine::MoveableSprite::moves Enemy::currentDirection = RIGHT;

/*Constructor, passing values on to Sprite constructor. Sets a seed for random, initializes attack frequensy and speed.*/
Enemy::Enemy(SDL_Texture* txtr_ptr, int x_value, int y_value, int width, int height) : engine::MoveableSprite(txtr_ptr, x_value, y_value, width, height) {
	srand(time(NULL));
	attackFrequency = rand() % 20 + 1;
	speed = 8;
}

/*Update enemy by calling relevant functions, in this instance it first updates position, then an attack if one is due and last incrementing tick by one*/
void Enemy::update(){
	updatePos();
	if (timeToAttack){
		updateAttack();
		timeToAttack = false;
	}
	tick++;
}

/*Returns rect of enemy that is going to be seen, returns rect depending on which frame is currently supposed to be shown*/
SDL_Rect* Enemy::getSourceRect(){
	return new SDL_Rect{ 0, FRAME_HEIGHT * frame, FRAME_WIDTH, FRAME_HEIGHT };
}

/*Updates position of enemy depending on current direction, if any enemy collides with screen they all change direction.
It also checks if the ticks are above 15 in which case it changes the frame and sees if it is time to attack and if so
sets a bool who keeps track of this to true
*/
void Enemy::updatePos(){
	SDL_Rect tmpRect = rect;
	switch (currentDirection){
	case LEFT:
		tmpRect.x += -speed;
		break;
	case RIGHT:
		tmpRect.x += speed;
		break;
	}

	if (!(collision_pointer->outsideScreen(&tmpRect))){
		moveX(tmpRect.x);
	}
	else{
		if (currentDirection == RIGHT){
			moveX(rect.x - speed);
		}
		else{
			moveX(rect.x + speed);
		}
		currentDirection = changeDirection();
	}
	if (tick > 15){
		if (attackCountdown > attackFrequency){
			int r = std::rand() % 20;
			if (r == 7)
			{
				timeToAttack = true;
			}
		}
		changeFrame();
		attackCountdown++;
		tick = 0;
	}
}

/*Updates enemy attack by creating a bullet spawned from enemy position in the direction of the player below*/
void Enemy::updateAttack(){
	engine::EntityFactory::createBullet(DOWN, rect.x + Enemy::FRAME_WIDTH / 2, rect.y + Bullet::FRAME_HEIGHT);
}

Enemy* Enemy::getInstance(SDL_Texture* txtr_ptr, int x_value, int y_value){
	return new Enemy(txtr_ptr, x_value, y_value, Enemy::FRAME_WIDTH, Enemy::FRAME_HEIGHT);
}

/*Changes frame depening on which is currently shown*/
void Enemy::changeFrame(){
	if (frame == 0){
		frame = 1;
	}
	else{
		frame = 0;
	}
}

/*Changes direction of enemy movement depending on which is current*/
engine::MoveableSprite::moves Enemy::changeDirection(){
	if (currentDirection == RIGHT){
		return LEFT;
	}
	else{
		return RIGHT;
	}
}

/*return current direction*/
engine::MoveableSprite::moves Enemy::getDirection()
{
	return currentDirection;
}

Enemy::~Enemy(){

}

/*Sets new speed*/
void Enemy::setSpeed(int newSpeed){
	speed = newSpeed;
}