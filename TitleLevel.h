#pragma once
#include "Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "AssetLoader.h"
#include "ControlState.h"



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
