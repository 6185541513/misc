#include "Player.h"
#include "EntityFactory.h"
/*Sets the path to player image*/
std::string Player::IMG_PATH = "player.png";

Player::Player(SDL_Texture* tex, int x_value, int y_value, int width, int height) : engine::MoveableSprite(tex, x_value, y_value, width, height) {
	speed = 15;
}

/*Takes in keystate and if it is pressed down hasAttacked is set to true*/
void Player::attack(Uint32 keyState){
	if (keyState == SDL_KEYDOWN){
		hasAttacked = true;
	}
}

/*When move right is called nextMove is right until the key state is SDL_KEYUP*/
void Player::moveRight(Uint32 keyState){
	if (keyState == SDL_KEYDOWN){
		nextMove = RIGHT;
	}
	else if (keyState == SDL_KEYUP){
		nextMove = STILL;
	}
}

/*When move left is called nextMove is left until the key state is SDL_KEYUP*/
void Player::moveLeft(Uint32 keyState){
	if (keyState == SDL_KEYDOWN){
		nextMove = LEFT;
	}
	else if (keyState == SDL_KEYUP){
		nextMove = STILL;
	}
}

/*Calls the functions to update position and then update attack, if hasAttacked is set to true*/
void Player::update(){
	updatePos();
	if (hasAttacked){
		updateAttack();
	}
}

/*Depending on state of nextMove the rects x is moved left or right*/
void Player::updatePos(){
	SDL_Rect tmpRect = rect;
	switch (nextMove){
	case LEFT:
	{
		tmpRect.x += -speed;
		break;
	}
		
	case RIGHT:
		tmpRect.x += speed;
		break;
	}
	if (!(collision_pointer->outsideScreen(&tmpRect))){
		moveX(tmpRect.x);
	}
}

/*Creates a bullet and sets hasAttacked to false since attack is now done*/
void Player::updateAttack(){
	engine::EntityFactory::createBullet(UP, rect.x + Player::FRAME_WIDTH / 2, rect.y - Bullet::FRAME_HEIGHT);
	hasAttacked = false;
}

/*Returns source rect, is used for the window to know if it should draw the whole image, since this is not a sprite sheet NULL i returned so whole image is shown*/
SDL_Rect* Player::getSourceRect(){
	return NULL;
}

/*So Player constructor can be private*/
Player* Player::getInstance(SDL_Texture* txtr_ptr, int x, int y){
	return new Player(txtr_ptr, x, y, Player::FRAME_WIDTH, Player::FRAME_HEIGHT);
}

/*Destructor*/
Player::~Player(){

}