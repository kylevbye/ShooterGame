#pragma once
#include <SDL.h>
#include "Level.h"
#include "Label.h"
#include "AssetLoader.h"
#include "ControlState.h"
#include <memory>

///
///	Forward Declarations
///

namespace Game {

	class GameState;
	class Level;

}

extern float screenWidth, screenHeight;
extern bool isRunning;
extern SDL_Renderer *asset_renderer;

class Game::GameState {

private:

	std::shared_ptr<Game::Level> currentLevel;
	ControlState controlState;
	Label escapeLabel;
	Label fpsLabel;
	Uint32 lastESCPress;

public:

	///	Getters
	Level &getCurrentLevel();
	ControlState &getControlState() { return controlState; }

	///	Setters
	void loadCurrentLevel(std::shared_ptr<Game::Level> newLevel);

	void update(float dt);
	void showFPS(Uint32 fps);

	void render();

	GameState();

	virtual ~GameState();


};