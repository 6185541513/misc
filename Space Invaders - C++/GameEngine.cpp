#include "GameEngine.h"

	/*Game loop which calls appropriate functions. First initializeing the game, then gathering input from player, updates objects in game,
	drawing graphics after update, playing sounds and delays loop according to frame rate. Finally it cleans up the game to free memory.
	*/
namespace engine{
	/*The game loop that sets current level as the first one in level list, it runs until game is ended and then calls a tidy up function*/
	void GameEngine::gameLoop(){
		currentLevel = *(LEVELS.begin());

		playIntro();
		while (gameRunning){
			gatherInput();
			updateLevel();
			drawGraphics();
			playSounds();
			SDL_Delay(FRAME_RATE);
		}
		playEnd();
		tidyUp();
	}

	/*Intro scene, just adding some delays to make it look nicer when starting*/
	void GameEngine::playIntro(){

		currentLevel->playerState = Level::state::INTRO;

		int countdown = 1000;
		while (countdown > 0){
			SDL_Texture* bg = currentLevel->getBackground(currentLevel->playerState);
			window->drawBackground(bg);
			countdown--;
		}
		countdown = 1000;

		currentLevel->playerState = Level::state::PLAYING;

		while (countdown > 0){
			window->drawBackground(currentLevel->getBackground(currentLevel->playerState));
			if (countdown < 700){
				for (Sprite* s : currentLevel->SURROUNDINGS){
					window->drawSprite(s);
				}
			}
			if (countdown < 450){
				for (Sprite* s : currentLevel->ENEMIES){
					window->drawSprite(s);
				}
			}
			if (countdown < 150){
				window->drawSprite(currentLevel->PLAYER);
			}
			countdown--;
		}
	}

	/*End scene, showing different end screens depending on win or fail*/
	void GameEngine::playEnd(){
		int countdown = 1500;
		while (countdown > 0){
			if (currentLevel->playerState == Level::state::LVL_FAIL){
				window->drawBackground(currentLevel->getBackground(currentLevel->playerState));
			}
			else if (currentLevel->playerState == Level::state::VICTORY){
				window->drawBackground(currentLevel->getBackground(currentLevel->playerState));
			}
			countdown--;
		}
	}

	/*Initializing game with nessesities*/
	void GameEngine::initializeGame(){
		window = new Window();

		collision = new Collision();
		collision->setWindow(window);

		gameRunning = true;
	}

	/*Gathering the player input and searching the keymap to see if the input matches a function, and if so runs it*/
	void GameEngine::gatherInput(){
		while (SDL_PollEvent(&e) != 0){
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_0)){
				gameRunning = false;
			}
			else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){
				if (keyMap.find(e.key.keysym.sym) != keyMap.end()){
					std::function<void(Uint32)> func = keyMap[e.key.keysym.sym];
					func(e.type);
				}
			}
		}
	}

	/*Updates the current level*/
	void GameEngine::updateLevel(){
		if (currentLevel->playerState == Level::state::PLAYING){
			std::list<Sprite*> removedSprites = currentLevel->update();
			if (removedSprites.size() > 0){
				for (Sprite* s : removedSprites){
					SPRITES.remove(s);
					delete s;
				}
			}
		}
		else if (currentLevel->playerState == Level::state::LVL_SUCCESS) {
			changeLevel();
		}
		else if (currentLevel->playerState == Level::state::LVL_FAIL || currentLevel->playerState == Level::state::VICTORY){
			gameRunning = false;
		}
	}

	/*Changes level when player completes it. If current level is the last, player has won, otherwise it changes to next level*/
	void GameEngine::changeLevel(){
		if (LEVELS.size() == 1){
			currentLevel->playerState = Level::state::VICTORY;
			gameRunning = false;
		}
		else{
			LEVELS.remove(currentLevel);
			noOfLevels = LEVELS.size();
			std::list<Level*>::iterator iter = std::next(LEVELS.begin(), noOfLevels - 1);
			currentLevel = *iter;
			currentLevel->playerState = Level::state::PLAYING;
		}
	}

	/*Draws the graphics for the sprites in game through the level*/
	void GameEngine::drawGraphics(){
		if (currentLevel->playerState == Level::state::PLAYING){
			window->drawSprite(currentLevel->PLAYER);
			for (Sprite* s : currentLevel->ENEMIES){
				window->drawSprite(s);
			}

			for (Sprite* s : currentLevel->BULLETS_PLAYER){
				window->drawSprite(s);
			}

			for (Sprite* s : currentLevel->BULLETS_ENEMIES){
				window->drawSprite(s);
			}
			for (Sprite* s : currentLevel->SURROUNDINGS){
				window->drawSprite(s);
			}
			window->flip(currentLevel->getBackground(Level::state::PLAYING));
		}
	}

	/*Member function to implement sound, if one wishes*/
	void GameEngine::playSounds(){

	}

	/*Frees memory where is needed*/
	void GameEngine::tidyUp(){
		/*Delete sprites*/
		std::vector<Sprite*> removeSprites;
		if (SPRITES.size() > 0){
			for (Sprite* s : SPRITES){
				removeSprites.push_back(s);
			}

			for (Sprite* s : removeSprites){
				SPRITES.remove(s);
				delete s;
			}
		}
	}

	/*Mapping a function with a key symbol for the gatherInput() to collect*/
	void GameEngine::addKeyEvent(SDL_Keycode key, std::function<void(Uint32)> funcCall){
		keyMap[key] = funcCall;
	}

	/*Gets texture for bullets from level, since bullet texture needs to be stored in a reachable way since they are created from other sprites*/
	SDL_Texture* GameEngine::getBulletTexture(){
		return currentLevel->bulletTexture;
	}

	/*Adding sprites to game to simplify handeling of in game sprites*/
	void GameEngine::addSprite(Sprite* sprite){
		sprite->setCollisionPointer(collision);
		SPRITES.push_back(sprite);
	}

	/*Adding level to game engine and setting the levels colision pointer*/
	void GameEngine::addLevel(Level* level){
		level->setCollision(collision);
		LEVELS.push_back(level);
		++noOfLevels;
	}

	/*Sets window title of game*/
	void GameEngine::setGameTitle(std::string title){
		window->setTitle(title);
	}

	/*Sets frame rate if game constructor wishes to change the default 30*/
	void GameEngine::setFrameRate(int newRate){
		FRAME_RATE = newRate;
	}

	/*Generates a texture from window*/
	SDL_Texture* GameEngine::generateTexture(std::string path){
		return window->createTexture(path);
	}

	/*Sets a specified level as the current*/
	void GameEngine::setLevel(Level* level){
		currentLevel = level;
	}

	/*Frees memory of what is claimed*/
	GameEngine::~GameEngine(){
		delete window;
		delete currentLevel;
		delete collision;
		while (!SPRITES.empty()){
			delete SPRITES.front(), SPRITES.pop_front();
		}
	}
}