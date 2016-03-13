#include "Level.h"
namespace engine{
	Level::Level() {}

	/*Calls an updateObject function that returns the updated sprites in a list*/
	std::list<Sprite*> Level::update(){
		return updateObjects();
	}

	/*In short updates the objects in the level by calling their respective update functions, and also checks for collsions and handles those*/
	std::list<Sprite*> Level::updateObjects(){
		std::list<Sprite*> removedSprites{};
		if (enemyCounter == 0){
			playerState = LVL_SUCCESS;
		}
		else{
			/*UPDATE SPRITES*/

			/*Update player*/
			PLAYER->update();

			/*Update enemies*/
			if (ENEMIES.size() > 0 && ENEMIES.front()->getDirection() == MoveableSprite::moves::RIGHT){
				std::list<Enemy*>::iterator iter = ENEMIES.end();
				for (; iter != ENEMIES.begin();){
					--iter;
					(*iter)->update();
				}
			}
			else{
				for (Enemy* e : ENEMIES){
					e->update();
				}
			}

			/*Update player bullets*/
			for (Bullet* b : BULLETS_PLAYER){
				b->update();
			}

			/*Update enemies bullets*/
			for (Bullet* b : BULLETS_ENEMIES){
				b->update();
			}

			/*CHECK COLLISION*/
			bool hasCollided = false;

			/*Check if enemy bullets hit player, and if so set player state to DEATH*/
			for (Bullet* b : BULLETS_ENEMIES){
				hasCollided = collision->collisionDetected(PLAYER->getRect(), b->getRect());
				if (hasCollided){
					playerState = LVL_FAIL;
				}
			}

			if (playerState != LVL_FAIL){
				/*Check if player bullets hits screen the remove, else check if it hits enemies and if so remove both objects in level and game engine lists*/
				std::vector<Bullet*> removedBullets{};
				std::vector<Enemy*> removedEnemies{};
				for (Bullet* b : BULLETS_PLAYER){
					if (collision->outsideScreen(b->getRect())){
						removedBullets.push_back(b);
					}
					else{
						for (Enemy* e : ENEMIES){
							hasCollided = collision->collisionDetected(e->getRect(), b->getRect());
							if (hasCollided){
								removedEnemies.push_back(e);
								removedBullets.push_back(b);
								removedSprites.push_back(e);
								removedSprites.push_back(b);
							}
						}
					}
					
				}
				if (removedEnemies.size() > 0){
					for (Enemy* e : removedEnemies){
						--enemyCounter;
						ENEMIES.remove(e);
					}
				}
				if (removedBullets.size() > 0){
					for (Bullet* b : removedBullets){
						BULLETS_PLAYER.remove(b);
					}
				}

				removedBullets.clear();
				/*Check if enemy bullets hits shield, and if so removing the bullet*/
				for (Bullet* b : BULLETS_ENEMIES){
					for (Sprite* s : SURROUNDINGS){
						hasCollided = collision->collisionDetected(s->getRect(), b->getRect());
						if (hasCollided){
							removedBullets.push_back(b);
							removedSprites.push_back(b);
						}
					}
				}
				if (removedBullets.size() > 0){
					for (Bullet* b : removedBullets){
						BULLETS_ENEMIES.remove(b);
					}
				}

			}
		}
		return removedSprites;
	}

	/*Sets the collision pointer*/
	void Level::setCollision(Collision* col_ptr){
		collision = col_ptr;
	}

	/*Returns the backgorund texture that matches the state of the game*/
	SDL_Texture* Level::getBackground(state state){
		std::list<SDL_Texture*>::iterator iter = std::next(BACKGROUNDS.begin(), state);
		return *(iter);
	}

	/*Creates a row of enemies and places them in the enemy list of the level*/
	void Level::spawnRow(int rowNumber, int no_of_enemies, int width_distanceBetweenEnemies, int height_distanceBetweenEnemies, SDL_Texture* texture)
	{
		int y_offset = (Enemy::FRAME_HEIGHT + height_distanceBetweenEnemies) * rowNumber;
		for (int i = 0; i < no_of_enemies; i++)
		{
			++enemyCounter;
			Enemy* enemy = EntityFactory::createEnemy(texture, i * width_distanceBetweenEnemies + i * Enemy::FRAME_WIDTH, y_offset);
			ENEMIES.push_back(enemy);
		}
	}

	/*Frees memory of what has been claimed*/
	Level::~Level(){
		while (!ENEMIES.empty()){
			delete ENEMIES.front(), ENEMIES.pop_front();
		}
		while (!BULLETS_ENEMIES.empty()){
			delete BULLETS_ENEMIES.front(), BULLETS_ENEMIES.pop_front();
		}
		while (!BULLETS_PLAYER.empty()){
			delete BULLETS_PLAYER.front(), BULLETS_PLAYER.pop_front();
		}
		delete collision;
	}
}