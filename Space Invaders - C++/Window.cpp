#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "Window.h"
#include "Rectangle.h"
#include "Sprite.h"
#include "MoveableSprite.h"

using namespace std;

namespace engine{
	/*Cosntructor, sees that its nessesities are initialized properly and sets values to window and creates a renderer*/
	Window::Window(){
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
			throwException("SDL_Init-fel: ", SDL_GetError);
		wind = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, NULL, NULL, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN);
		if (wind == nullptr)
			throwException("SDL_CreateWindow error: ", SDL_GetError);
		renderer = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr)
			throwException("SDL_CreateRenderer error: ", SDL_GetError);
		if (TTF_Init() == -1)
			throwException("TTF_Init error: ", TTF_GetError);

		if (SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255) < 0)
			throwException("SetRenderColor error:", SDL_GetError);
	}

	/*Returns the outmost x position*/
	int Window::getX(){
		int x = 0;
		SDL_GetWindowSize(wind, &x, NULL);
		return x;
	}

	/*Returns the outmost y position*/
	int Window::getY(){
		int y = 0;
		SDL_GetWindowSize(wind, NULL, &y);
		return y;
	}

	/*Sets title of window*/
	void Window::setTitle(string title){
		SDL_SetWindowTitle(wind, title.c_str());
	}

	/*Returns a texture by taking in a path to an image, creates a surface with it, sets white as transparent and the creates the texture*/
	SDL_Texture* Window::createTexture(std::string path){
		SDL_Surface* surface = IMG_Load(path.c_str());
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		return texture;
	}

	/*Returns a texture from text, incluing color and font*/
	SDL_Texture* Window::createTextureWithFonts(std::string fontPath, SDL_Color color, std::string text){
		TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 18);
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		return texture;
	}

	/*Shows a texture with information from a sprite, it gets the sprites texture, then the sourcerect (which if NULL presents the whole image), the rect information where it should be drawn on the window*/
	void Window::drawSprite(Sprite* sprite){
		SDL_Texture* spritetexture = sprite->getTexture();
		SDL_RenderCopy(renderer, spritetexture, sprite->getSourceRect(), sprite->getRect());
	}

	/*Draws the background from the texture sent in, and in this case always shows the whole image on the whole screen*/
	void Window::drawBackground(SDL_Texture* texture){
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
	}

	/*Draws the texture sent in, and shows it on the whole screen*/
	void Window::flip(SDL_Texture* texture){
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
	}

	/*Exception function*/
	void throwException(string msg, const char* (*errorFunc)()){
		msg += errorFunc();
		throw runtime_error(msg.c_str());
	}

	Window::~Window(){
		
	}
}