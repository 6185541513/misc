#include "EntityFactory.h"

namespace engine{
	/*Initializes static game enginge pointer*/
	GameEngine* EntityFactory::engine_ptr = NULL;

	/*Sets game engine pointer*/
	void EntityFactory::setGameEngine(engine::GameEngine* engn_ptr){
		EntityFactory::engine_ptr = engn_ptr;
	}

	/*Creates and returns shield, also adding it to game engine*/
	Shield* EntityFactory::createShield(SDL_Texture* txtr_ptr, int x, int y){
		Shield* shield = Shield::getInstance(txtr_ptr, x, y);
		engine_ptr->addSprite(shield);
		return shield;
	}

	/*Creates and returns a player, also adding it to game engine*/
	Player* EntityFactory::createPlayer(SDL_Texture* txtr_ptr, int x, int y){
		Player* player = Player::getInstance(txtr_ptr, x, y);
		engine_ptr->addSprite(player);
		return player;
	}

	/*Creates and returns an enemy, also adding it to game engine*/
	Enemy* EntityFactory::createEnemy(SDL_Texture* txtr_ptr, int x, int y){
		Enemy* enemy = Enemy::getInstance(txtr_ptr, x, y);
		engine_ptr->addSprite(enemy);
		return enemy;
	}

	/*Creates a bullet and setting a direction depending on parameter value 'direction'. Finally it adds the bullet to the game engine through the pointer to it*/
	void EntityFactory::createBullet(MoveableSprite::moves direction, int x, int y){
		Bullet* bullet = Bullet::getInstance(engine_ptr->getBulletTexture(), x, y);
		bullet->setDirection(direction);
		engine_ptr->addSprite(bullet);
		if (direction == MoveableSprite::moves::UP){
			engine_ptr->currentLevel->BULLETS_PLAYER.push_back(bullet);
		}
		else{
			engine_ptr->currentLevel->BULLETS_ENEMIES.push_back(bullet);
		}
	}

	/*Creates and returns a sprite, also adding it to game engine*/
	Sprite* EntityFactory::createSprite(SDL_Texture* txtr_ptr, int x, int y, int width, int height){
		Sprite* sprite = new Sprite(txtr_ptr, x, y, width, height);
		engine_ptr->addSprite(sprite);
		return sprite;
	}

	/*Creates and returns a textfield, also adding it to game engine*/
	TextField* EntityFactory::createTextField(std::string text, std::string fontPath, SDL_Color color, int x, int y, int width, int height){
		TextField* textField = TextField::getInstance(text, engine_ptr->window->createTextureWithFonts(fontPath, color, text), x, y, width, height);
		engine_ptr->addSprite(textField);
		return textField;
	}
}