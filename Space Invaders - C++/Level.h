#ifndef LEVEL_H
#define LEVEL_H
#include <list>
#include <SDL.h>
#include "GameEngine.h"
#include "Collision.h"
#include "Sprite.h"
#include "MoveableSprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Player;
class Enemy;
class Bullet;

namespace engine{
	class Sprite;
	class MoveableSprite;

	class Level{
		Level(Level& other);
	protected:
		std::list<Sprite*> updateObjects();
		Collision* collision = NULL;
		int enemyCounter = 0;
	public:
		Level();
		enum state{INTRO, PLAYING, LVL_SUCCESS, LVL_FAIL, VICTORY};
		state playerState = INTRO;
		std::list<SDL_Texture*> BACKGROUNDS;
		std::list<Sprite*> SURROUNDINGS;
		Player* PLAYER;
		std::list<Enemy*> ENEMIES;
		std::list<Bullet*> BULLETS_PLAYER;
		std::list<Bullet*> BULLETS_ENEMIES;
		SDL_Texture* getBackground(state state);
		SDL_Texture* bulletTexture;
		std::list<Sprite*> update();
		void spawnRow(int rowNumber, int no_of_enemies, int width_distanceBetweenEnemies, int height_distanceBetweenEnemies, SDL_Texture* texture);
		void setCollision(Collision* collision);
		~Level();
	};
}
#endif