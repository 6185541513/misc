#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "TextField.h"
#include "Shield.h"

class TextField;
class Shield;
class Player;
class Enemy;
namespace engine{
	/*Variables*/
	class GameEngine;
	class Sprite;
	class MoveableSprite;
	struct EntityFactory{
	static GameEngine* engine_ptr;

	/*Memeber functions*/
	static void setGameEngine(GameEngine* engn_ptr);
	static Player* createPlayer(SDL_Texture* txtr_ptr, int x, int y);
	static Enemy* createEnemy(SDL_Texture* txtr_ptr, int x, int y);
	static void createBullet(MoveableSprite::moves direction, int x, int y);
	static Sprite* createSprite(SDL_Texture* txtr_ptr, int x, int y, int width, int height);
	static TextField* createTextField(std::string text, std::string fontPath, SDL_Color color, int x, int y, int width, int height);
	static Shield* createShield(SDL_Texture* txtr_ptr, int x, int y);
	};
}
#endif