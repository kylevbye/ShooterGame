#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Game/Level.h"
#include "Game/GameState.h"
#include "GameWindow.h"
#include "AssetLoader.h"
#include "AssetHandler.h"
#include "Label.h"
#include <iostream>

float screenWidth, screenHeight;
SDL_Renderer *asset_renderer;
Game::GameState gameState;
GameWindow *gameWindow;
LevelHandler levels;
bool isRunning = true;
bool isDebugging = false;
Uint32 totalTicks = 0;
Uint32 totalFrames = 0;
float currentFPS = 0.f;
float averageFPS = 0.f;

int initialize();
void handleInput();
void terminate();

/**
 *	
 */
int main(int argc, char *args[]) {

	std::cout << "Starting Shooter Game" << std::endl;

	if (initialize() == 1) return 1;

	//	VFR
	Uint32 lastUpdate = SDL_GetTicks();

	//	Game Loop
	while (isRunning) {

		//	Time Update
		++totalFrames;
		Uint32 startTicks = SDL_GetTicks();

		//	Process Logic
		handleInput();

		//	Update
		Uint32 current = SDL_GetTicks();
		float dt = (current-lastUpdate)/1000.f;
		gameState.update(dt);
		if (gameState.getCurrentLevel().isDone()) {
			gameState.loadCurrentLevel(
				loadLevel(gameState.getCurrentLevel().getNextLevelCode())
				);
		}
		lastUpdate = current;

		//	Render
		gameWindow->clear();
		gameState.render();
		gameWindow->display();

		//	Random FPS Test
		//SDL_Delay(rand() % 35);

		//	End Frame Time
		float frameTime = (SDL_GetTicks()-startTicks)/1000.f;
		currentFPS = 1.f/frameTime;
		if (isDebugging) {
			std::cout << "FPS = " << currentFPS << std::endl;

		}

	}

	//	Termination Sequence
	delete gameWindow;
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	terminate();

	return 0;

}

int initialize() {
	//	Init SDL; Quit if failed.
	if (SDL_Init(SDL_INIT_VIDEO||SDL_INIT_AUDIO != 0)) {
		
		SDL_Log("Unable to init SDL: %s", SDL_GetError());
		terminate();

		return 1;

	}

	//	Init IMG; Quit if failed.
	if (!IMG_Init(IMG_INIT_PNG)) {

		SDL_Log("Unable to init SDL_image: %s", SDL_GetError());
		terminate();
		
		return 1;

	}

	//	Init TTF; Quit if failed.
	if (TTF_Init() == -1) {

		SDL_Log("Unable to init SDL_ttf: %s", TTF_GetError());
		terminate();

		return 1;

	}

	//	Init Mixer; Quit if failed.
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {

		SDL_Log("Unable to init SDL_mixer: %s", Mix_GetError());
		terminate();

		return 1;

	}

	screenWidth = 1280; screenHeight = 720;
	gameWindow = new GameWindow("Shooter", 1280, 720);

	//	Prepare AssetLoader
	asset_renderer = gameWindow->getRenderer();

	//	FPS Label
	Label fpsDebugLabel = *loadLabel(0, 0, "000", "res/fnt/DTM-Mono.ttf", 25, {255,255,255}); 

	//	GameState
	gameState = (gameWindow->getRenderer());
	gameState.loadCurrentLevel(loadLevel("titleLevel"));

}

void handleInput() {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {

			case SDL_KEYDOWN:
				gameState.getKeyHandler().handleDownInput(event.key.keysym.sym);
				if (event.key.keysym.sym == 	
SDLK_F4) { gameWindow->toggleFullScreen(); }
				break;

			case SDL_KEYUP:
				gameState.getKeyHandler().handleUpInput(event.key.keysym.sym);
				break;

			case SDL_QUIT:
				isRunning = false;
				break;
		
		}
	}

}


void terminate() {
	std::cout << "Shooter Game terminated..." << std::endl;
	std::cout << "Press Enter to Exit..." << std::endl;
	std::cin.get();
}
