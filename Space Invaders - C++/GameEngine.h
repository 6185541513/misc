#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <list>
#include <string>
#include <map>
#include <functional>
#include "Window.h"
#include "Collision.h"
#include "Level.h"
#include "EntityFactory.h"
#include "Sprite.h"

namespace engine{
	class Level;
	class Sprite;
	class GameEngine{
		/*Variables*/
		int FRAME_RATE = 30;
		bool gameRunning;
		SDL_Event e;
		Collision* collision = NULL;
		std::list<Sprite*> SPRITES;
		std::list<Level*> LEVELS;
		bool victory = false;
		int levelCounter = 0;
		std::map<SDL_Keycode, std::function<void(Uint32)>> keyMap;

		/*Member functions*/
		void playIntro();
		void gatherInput();
		void updateLevel();
		void drawGraphics();
		void playSounds();
		void playEnd();
		void tidyUp();
		int noOfLevels = 0;

	public:
		/*Variables*/
		~GameEngine();
		Window* window;
		GameEngine() {}
		Level* currentLevel = NULL;
		/*Member functions*/
		void initializeGame();
		void setBackground(std::string path);
		SDL_Texture* generateTexture(std::string path);
		void setBulletTexture(std::string path);
		void spawnRow(int rowNumber, int no_of_enemies, int width_distanceBetweenEnemies, int height_distanceBetweenEnemies, SDL_Texture* texture);
		void gameLoop();
		SDL_Texture* getBulletTexture();
		void setFrameRate(int newRate);
		void setGameTitle(std::string title);
		void setLevel(Level* level);
		void changeLevel();
		void addLevel(Level* level);
		void addSprite(Sprite* sprite);
		void addKeyEvent(SDL_Keycode key, std::function<void(Uint32)> funcCall);
	};
}
#endif