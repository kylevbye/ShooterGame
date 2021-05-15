#pragma once
#include "Game/Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "AssetLoader.h"

namespace Game {
	class Level;
	class MainMenuLevel;
}

class Game::MainMenuLevel : public Game::Level {

	enum Options {
		BEGIN_GAME, HOW_TO_PLAY
	};

private:

	Music *menuMusic;
	Label *gameTitleLabel;
	Label *startLabel;
	Label *instructionLabel;
	std::vector<Entity *> particles;
	Options selectedOption;
	Entity *asgoreEntity;
	int alpha;
	bool fadeIn;

public:

	///	From Level
	void update(float dt, const KeyStates &keyStates);
	void updateEvents(Uint32 time, float dt);
	void setup();

	///	Constructor
	MainMenuLevel();

	///	Destructor
	~MainMenuLevel();


};