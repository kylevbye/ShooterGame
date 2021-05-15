#pragma once
#include <vector>
#include "Game/Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "AssetLoader.h"

///	Forward Declarations
namespace Game {
	class Level;
	class InstructionLevel;
}

class Game::InstructionLevel : public Game::Level {

private:

	Music *instructionMusic;
	Label *titleLabel;
	std::vector<Label *> instructionLabels;
	Label *doneLabel;

public:

	///	From Level
	void update(float dt, const KeyStates &keyStates);
	void updateEvents(Uint32 time, float dt);
	void setup();

	//	Constructors
	InstructionLevel();

	//	Destructor
	~InstructionLevel();

};