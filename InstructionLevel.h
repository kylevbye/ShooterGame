#pragma once
#include <vector>
#include "Level.h"
#include "Label.h"
#include "Sound.h"
#include "Music.h"
#include "AnimatedEntity.h"
#include "InstructionLevel.h"
#include "AssetLoader.h"
<<<<<<< HEAD:include/Game/Levels/InstructionLevel.h
#include "KeyEventHandler.h"
=======
#include "ControlState.h"
>>>>>>> 310f83325ba0c0a9120a95c66b1982b8d5a728f6:InstructionLevel.h

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
	void update(float dt, const ControlState &controlState);
	void updateEvents(Uint32 time, float dt);
	void setup();

	//	Constructors
	InstructionLevel();

	//	Destructor
	virtual ~InstructionLevel();

};