#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Level.h"
#include "GameState.h"
#include "GameWindow.h"
#include "AssetLoader.h"

float screenWidth, screenHeight;
SDL_Renderer *asset_renderer;
GameWindow *gameWindow;
bool isRunning = true;
bool isDebugging = true;
bool isCapping = true;
Uint64 startPerf = SDL_GetPerformanceCounter();
Uint32 totalFrames = 0;
Uint32 lastDebugFPSUpdate = 0;
Uint32 fpsLabelVal = 0;
float currentFPS = 0.f;
float averageFPS = 0.f;

int allocationCount = 0;
int deleteCount = 0;

int initialize();
void handleInput(Game::GameState &gameState);
void terminate();

void * operator new(size_t size) {
	++allocationCount;
    return malloc(size);
}
 
void operator delete(void * p) {
	++deleteCount;
    free(p);
}


/**
 *	
 */
int main(int argc, char *args[]) {

	SDL_Log("Starting Shooter Game...");

	if (initialize()==1) return 1;
	{
	Game::GameState gameState;

	//	VFR
	Uint32 lastUpdate = SDL_GetTicks();

	//	Game Loop
	while (isRunning) {

		//	Time Update
		++totalFrames;
		Uint32 startTicks = SDL_GetTicks();

		if (lastUpdate<startTicks) {

			Uint64 startPerf = SDL_GetPerformanceCounter();

			//	Process Logic
			handleInput(gameState);

			//	Update
			Uint32 current = SDL_GetTicks();
			float dt = (current-lastUpdate)/1000.f;
			gameState.update(dt);
			lastUpdate = current;

			//	Render
			gameWindow->clear();
			if (isDebugging&&SDL_GetTicks()-lastDebugFPSUpdate>500) {
				fpsLabelVal = currentFPS;
				lastDebugFPSUpdate = SDL_GetTicks();
			}
			gameState.showFPS((Uint32) fpsLabelVal);
			gameState.render();
			gameWindow->display();
			++totalFrames;

			//	Random FPS Test
			//SDL_Delay(rand() % 35);

			if (isCapping) {
				float amountToDelay = (SDL_GetPerformanceCounter()-startPerf)/((float)SDL_GetPerformanceFrequency()*1000.f);
				SDL_Delay(floor(16.7f-amountToDelay));
			}

		}
		else SDL_Delay(1);

		//	End Frame Time
		float frameTime = ((float) (SDL_GetTicks()-startTicks))/1000.f;
		currentFPS = 1.0f/frameTime;
		averageFPS = totalFrames/(SDL_GetTicks()/1000.f);

	}

	//	Termination Sequence
	delete gameWindow;
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	}
	terminate();

	return 0;

}

int initialize() {
	//	Init SDL; Quit if failed.
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		
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
	gameWindow = new GameWindow("ShooterGame", screenWidth, screenHeight);
	asset_renderer = gameWindow->getRenderer();

	return 0;

}

void handleInput(Game::GameState &gameState) {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {

			case SDL_KEYDOWN:
				gameState.getControlState().getKeyHandler().handleDownInput(event.key.keysym.sym);
				if (event.key.keysym.sym == SDLK_F4) { 
					gameWindow->toggleFullScreen(); 
				}
				if (event.key.keysym.sym==SDLK_F5) {
					isCapping = !isCapping;
				}
				break;
			case SDL_CONTROLLERAXISMOTION:
				if (event.caxis.which == 0) {
					gameState.getControlState().getControlHandler().handleJoyInput(event.caxis);
					//gameState.handleControlDownInput(event.jaxis)
				}
				break;
			case SDL_CONTROLLERBUTTONDOWN:
				gameState.getControlState().getControlHandler().handleDownInput(event.cbutton);
				break;
			case SDL_KEYUP:
				gameState.getControlState().getKeyHandler().handleUpInput(event.key.keysym.sym);
				break;
			case SDL_CONTROLLERBUTTONUP:
				gameState.getControlState().getControlHandler().handleUpInput(event.cbutton);
				break;
			case SDL_QUIT:
				isRunning = false;
				break;
		}
	}

}


void terminate() {
	SDL_Log("Shooter Game terminated...");
	SDL_Log("%d Heap Allocations; %d Heap Deallocations.", allocationCount, deleteCount);
}
