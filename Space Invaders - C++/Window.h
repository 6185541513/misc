#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

namespace engine{
	class Sprite;
	class Window{
		SDL_Window* wind = NULL;
		SDL_Renderer* renderer;
	public:
		Window();
		~Window();
		int getX();
		int getY();
		void setTitle(std::string title);
		SDL_Texture* createTexture(std::string path);
		SDL_Texture* createTextureWithFonts(std::string fontPath, SDL_Color color, std::string text);
		void drawBackground(SDL_Texture* texture);
		void drawSprite(Sprite* sprite);
		void flip(SDL_Texture* texture);
	};
	
	/*Helper function for throwing exceptions*/
	void throwException(std::string msg, const char* (*errorFunction)());
}
#endif