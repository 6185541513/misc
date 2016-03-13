#ifndef PLAYER_H
#define PLAYER_H
#include "MoveableSprite.h"
#include "Bullet.h"

class Player : public engine::MoveableSprite{
	friend struct EntityFactory;
public:
	/*Variables*/
	static const int FRAME_WIDTH = 72;
	static const int FRAME_HEIGHT = 72;
	static std::string IMG_PATH;

	/*Member functions*/
	~Player();
	void processInput(moves move);
	void update();
	SDL_Rect* getSourceRect();
	static Player* getInstance(SDL_Texture* txtr_ptr, int x, int y);
	void moveLeft(Uint32);
	void moveRight(Uint32);
	void attack(Uint32);
private:
	/*Variables*/
	moves nextMove;
	int hasAttacked = false;

	/*Member functions*/
	Player(SDL_Texture* tex, int x_value, int y_value, int width, int height);
	Player();
	Player(Player& other);
	void updatePos();
	void updateAttack();
};
#endif