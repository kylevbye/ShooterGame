#pragma once
#include <SDL2/SDL.h>
#include "PlayerController.h"
#include "Game/Level.h"
#include "Label.h"
#include "AssetLoader.h"

///
///	Forward Declarations
///
class PlayerController;

namespace Game {

	class GameState;
	class Level;

}

extern float screenWidth, screenHeight;
extern bool isRunning;

class Game::GameState {

private:

	SDL_Renderer *renderer;
	PlayerController playerController;
	Level *currentLevel;
	KeyEventHandler keyHandler;
	Label *escapeLabel;
	Label *fpsLabel;
	Uint32 lastESCPress;

public:

	///	Getters
	PlayerController &getPlayerController();
	Level &getCurrentLevel();
	KeyEventHandler &getKeyHandler() { return keyHandler; }

	///	Setters
	void setRenderer(SDL_Renderer *renderer);
	void loadCurrentLevel(Level *newLevel);

	void update(float dt);
	void showFPS(int fps);

	void render();

	GameState();
	GameState(SDL_Renderer *renderer);

	~GameState();


};