#pragma once
#include "Level.h"
#include "AnimatedEntity.h"
#include "Label.h"
#include "Sound.h"
#include "AssetLoader.h"
<<<<<<< HEAD:include/Game/Levels/LoadingBattleLevel.h
#include "KeyEventHandler.h"
=======
#include "ControlState.h"
>>>>>>> 310f83325ba0c0a9120a95c66b1982b8d5a728f6:LoadingBattleLevel.h

namespace Game {
	class Level;
	class LoadingBattleLevel;
}

class Game::LoadingBattleLevel : public Game::Level {

private:

	Sound *knifeSlashSound;
	Sound *damageSound;
	AnimatedEntity knifeEntity;

public:

	///	From Level
	void update(float dt, const ControlState &controlState);
	void updateEvents(Uint32 time, float dt);
	void setup();

	//	Constructor
	LoadingBattleLevel();

	//	Destructor
	virtual ~LoadingBattleLevel();

};