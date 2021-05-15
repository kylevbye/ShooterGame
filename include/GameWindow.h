#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.h"
#include "Renderer.h"


class Entity;
class Renderer;

class GameWindow : public Renderer {

private:

	int width, height;
	bool isFullScreen;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *windowIcon;

public:

	///	Getters
	SDL_Window *getWindow() { return window; }
	SDL_Renderer *getRenderer() { return renderer; }

	SDL_Texture *loadTexture(const char *filePath);
	void clear();
	void render(SDL_Texture *texture);
	void render(Entity &entity);
	void display();

	void toggleFullScreen();

	GameWindow(const char *title, int width, int height);

	~GameWindow();

};