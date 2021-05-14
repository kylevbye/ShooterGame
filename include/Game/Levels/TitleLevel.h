#pragma once
#include "Game/Level.h"
#include "Label.h"
#include "Sound.h"
#include "AssetLoader.h"



namespace Game {
	class Level;
	class TitleLevel;
}

class Game::TitleLevel : public Game::Level {

private:

	Label *titleLabel;
	Label *instructionLabel;
	Sound *titleDropSound;

public:

	//	From Level
	void update(float dt);
	void updateEvents(Uint32 time, float dt);

	///	Constructors
	TitleLevel();
	~TitleLevel() {}

};
