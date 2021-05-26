#pragma once
#include "Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "Entity.h"
#include "AssetLoader.h"
#include "ControlState.h"
#include <memory>

namespace Game {
	class Level;
	class MainMenuLevel;
}

extern bool isRunning;

class Game::MainMenuLevel : public Game::Level {

public:

	enum Options : int {
		BEGIN_GAME, HOW_TO_PLAY, CREDITS, QUIT_GAME
	};

private:

	Music *menuMusic;
	Label gameTitleLabel;
	Label startLabel;
	Label instructionLabel;
	Label creditLabel;
	Label quitLabel;
	std::vector<MobileEntity *> particles;
	Options selectedOption;
	Entity asgoreEntity;
	float alpha;
	bool fadeIn;

public:

	///	From Level
	void update(float dt, const ControlState &controlState);
	void updateEvents(Uint32 time, float dt);
	void setup();

	///	Constructor
	MainMenuLevel();

	///	Destructor
	virtual ~MainMenuLevel();


};