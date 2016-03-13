#include <SDL.h>
#include <stdio.h>
#include <string>
#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Shield.h"
#include "TextField.h"

/*Creates game engine and sets the engine as same in the Entity Factory that creates objects*/
//engine::GameEngine* gameEngine;

engine::Level* createLevel1(Player* p, engine::GameEngine* ge);
engine::Level* createLevel2(Player* p, engine::GameEngine* ge);

int main(int argc, char* args[]){
	/*Creates game engine and sets the engine as same in the Entity Factory that creates objects*/
	engine::GameEngine* gameEngine = new engine::GameEngine();
	engine::EntityFactory::setGameEngine(gameEngine);

	/*Initializes nessecery functions in game engine like a window and collision*/
	gameEngine->initializeGame();
	gameEngine->setGameTitle("Space Invaders");

	/*Creates player by letting the entity factory create the player. Finally it adds the player to the engine*/
	Player* player = engine::EntityFactory::createPlayer(gameEngine->generateTexture(Player::IMG_PATH), gameEngine->window->getX() / 2 - Player::FRAME_WIDTH / 2, gameEngine->window->getY() - Player::FRAME_HEIGHT);
	
	/*Creates levels and adding them to game engine*/
	engine::Level* lvl1 = createLevel1(player, gameEngine);
	engine::Level* lvl2 = createLevel2(player, gameEngine);
	gameEngine->addLevel(lvl1);
	gameEngine->addLevel(lvl2);

	/*Bind functions to keys*/
	std::function<void(Uint32)> moveLeft = std::bind(&Player::moveLeft, player, std::placeholders::_1);
	std::function<void(Uint32)> moveRight = std::bind(&Player::moveRight, player, std::placeholders::_1);
	std::function<void(Uint32)> attack = std::bind(&Player::attack, player, std::placeholders::_1);
	gameEngine->addKeyEvent(SDLK_LEFT, moveLeft);
	gameEngine->addKeyEvent(SDLK_RIGHT, moveRight);
	gameEngine->addKeyEvent(SDLK_SPACE, attack);

	/*Frame rate is default 30 but game constructor can change that*/
	gameEngine->setFrameRate(35);

	/*runs game loop*/
	gameEngine->gameLoop();
	return 0;
}

/*Function for creating the first level*/
engine::Level* createLevel1(Player* player, engine::GameEngine* ge){
	engine::GameEngine* gameEngine = ge;
	engine::Level* level = new engine::Level();

	/*Set player*/
	level->PLAYER = player;

	/*Prepare different backgorunds*/
	std::string pathsLevelBackgrounds[5]{"logo.png", "background.bmp", "logo.png", "loose.png", "win.png"};
	for (int i = 0; i < 5; i++){
		level->BACKGROUNDS.push_back(gameEngine->generateTexture(pathsLevelBackgrounds[i]));
	}

	/*Creates enemies by deciding how many different types will be spawned, then giving values deciding layout of enemies. After that
	calling a function from the engine that spawns rows accordingly.*/
	std::string path_enemiesImages[3]{"enemysprite_purple.png", "enemysprite_pink.png", "enemysprite_purple.png"};

	int no_of_enemies_per_row = 10;
	int width_distance_between_enemies = 40;
	int height_distance_between_enemies = 20;

	for (int row_number = 0; row_number < 3; ++row_number)
	{
		level->spawnRow(row_number, no_of_enemies_per_row, width_distance_between_enemies, height_distance_between_enemies, (gameEngine->generateTexture(path_enemiesImages[row_number])));
	}

	/*Preparing future bullet creation by setting a texture with a given image path*/
	level->bulletTexture = gameEngine->generateTexture("player_bullet.png");

	/*Creates immobile sprites which will serve as shileds in the game*/
	int numberOfSheilds = 3;
	int x_start = gameEngine->window->getX() / numberOfSheilds / 2 - (Shield::FRAME_WIDTH / 2);
	for (int i = 0; i < numberOfSheilds; i++){
		Shield* shield = engine::EntityFactory::createShield(gameEngine->generateTexture(Shield::IMG_PATH), x_start + i * gameEngine->window->getX() / 3, gameEngine->window->getY() / 2);
		level->SURROUNDINGS.push_back(shield);
	}

	/*Set text field*/
	std::string text = "BEWARE THE INVASION";
	std::string fontPath = "Candara.ttf";
	SDL_Color color = { 255, 255, 255 };
	int width = 200;
	int height = 50;
	int x_tf = gameEngine->window->getX() - width * 2;
	int y_tf = gameEngine->window->getY() - height;

	level->SURROUNDINGS.push_back(engine::EntityFactory::createTextField(text, fontPath, color, x_tf, y_tf, width, height));

	return level;
}

/*Function for creating second level*/
engine::Level* createLevel2(Player* player, engine::GameEngine* ge){
	engine::GameEngine* gameEngine = ge;
	engine::Level* level = new engine::Level();

	/*Set player*/
	level->PLAYER = player;

	/*Prepare different backgorunds*/
	std::string pathsLevelBackgrounds[5]{"logo.png", "background.bmp", "logo.png", "loose.png", "win.png"};
	for (int i = 0; i < 5; i++){
		level->BACKGROUNDS.push_back(gameEngine->generateTexture(pathsLevelBackgrounds[i]));
	}

	/*Creates enemies by deciding how many different types will be spawned, then giving values deciding layout of enemies. After that
	calling a function from the engine that spawns rows accordingly.*/
	std::string path_enemiesImages[3]{"enemysprite_cyan.png", "enemysprite_pink.png", "enemysprite_cyan.png"};

	int no_of_enemies_per_row = 10;
	int width_distance_between_enemies = 40;
	int height_distance_between_enemies = 20;

	for (int row_number = 0; row_number < 3; ++row_number)
	{
		level->spawnRow(row_number, no_of_enemies_per_row, width_distance_between_enemies, height_distance_between_enemies, (gameEngine->generateTexture(path_enemiesImages[row_number])));
	}

	/*Sets new faster speed for enemies*/
	for (Enemy* e : level->ENEMIES){
		e->setSpeed(12);
	}

	/*Preparing future bullet creation by setting a texture with a given image path*/
	level->bulletTexture = gameEngine->generateTexture("player_bullet.png");

	/*Creates immobile sprites which will serve as shileds in the game*/
	int numberOfSheilds = 3;
	int x_start = gameEngine->window->getX() / numberOfSheilds / 2 - (Shield::FRAME_WIDTH / 2);
	for (int i = 0; i < numberOfSheilds; i++){
		Shield* shield = engine::EntityFactory::createShield(gameEngine->generateTexture(Shield::IMG_PATH), x_start + i * gameEngine->window->getX() / 3, gameEngine->window->getY() / 2);
		level->SURROUNDINGS.push_back(shield);
	}

	/*Set text field*/
	std::string text = "BEWARE THE INVASION";
	std::string fontPath = "Candara.ttf";
	SDL_Color color = { 255, 255, 255 };
	int width = 200;
	int height = 50;
	int x_tf = gameEngine->window->getX() - width * 2;
	int y_tf = gameEngine->window->getY() - height;

	level->SURROUNDINGS.push_back(engine::EntityFactory::createTextField(text, fontPath, color, x_tf, y_tf, width, height));

	return level;
}
