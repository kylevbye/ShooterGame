#pragma once
#include "Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "AssetLoader.h"
<<<<<<< HEAD:include/Game/Levels/TitleLevel.h
#include "KeyEventHandler.h"
=======
#include "ControlState.h"
>>>>>>> 310f83325ba0c0a9120a95c66b1982b8d5a728f6:TitleLevel.h



namespace Game {
	class Level;
	class TitleLevel;
}

class Game::TitleLevel : public Game::Level {

private:

	Label titleLabelFront;
	Label titleLabelBack;
	Label instructionLabel;
	Sound *titleDropSound;
	Music *titleMusic;
	float alpha;
	bool fadeIn;

public:

	//	From Level
	void update(float dt, const ControlState &controlState);
	void updateEvents(Uint32 time, float dt);
	void setup();

	///	Constructors
	TitleLevel();

	//	Destructor
	virtual ~TitleLevel();

};
