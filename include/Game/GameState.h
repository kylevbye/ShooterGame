#pragma once

#include <SDL2/SDL.h>
#include "PlayerController.h"
#include "Game/Level.h"

///
///	Forward Declarations
///
class PlayerController;

namespace Game {

	class GameState;
	class Level;

}

extern float screenWidth, screenHeight;

class Game::GameState {

private:

	SDL_Renderer *renderer;
	PlayerController playerController;
	Level *currentLevel;
	KeyEventHandler keyHandler;

public:

	///	Getters
	PlayerController &getPlayerController();
	Level &getCurrentLevel();
	KeyEventHandler &getKeyHandler() { return keyHandler; }

	///	Setters
	void setRenderer(SDL_Renderer *renderer);
	void loadCurrentLevel(Level *newLevel);

	void update(float dt);

	void render();

	GameState();
	GameState(SDL_Renderer *renderer);


};