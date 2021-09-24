#pragma once
#include <vector>
#include "Game/Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "AnimatedEntity.h"
#include "InstructionLevel.h"
#include "AssetLoader.h"
#include "KeyEventHandler.h"

///	Forward Declarations
class Music;
namespace Game {
	class Level;
	class InstructionLevel;
}

class Game::InstructionLevel : public Game::Level {

private:

	AnimatedEntity asgore;
	Music *instructionMusic;
	Label titleLabel;
	std::vector<Label *> instructionLabels;
	Label doneLabel;
	int alpha;
	bool fadeIn;

public:

	///	From Level
	void update(float dt, const KeyStates &keyStates);
	void updateEvents(Uint32 time, float dt);
	void setup();

	//	Constructors
	InstructionLevel();

	//	Destructor
	virtual ~InstructionLevel();

};