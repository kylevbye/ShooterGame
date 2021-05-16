#pragma once
#include "Game/Level.h"
#include "AnimatedEntity.h"
#include "Label.h"
#include "Sound.h"
#include "AssetLoader.h"

namespace Game {
	class Level;
	class LoadingBattleLevel;
}

class Game::LoadingBattleLevel : public Game::Level {

private:

	Sound *knifeSlashSound;
	Sound *damageSound;
	AnimatedEntity *knifeEntity;

public:

	///	From Level
	void update(float dt, const KeyStates &keyStates);
	void updateEvents(Uint32 time, float dt);
	void setup();

	//	Constructor
	LoadingBattleLevel();

	//	Destructor
	~LoadingBattleLevel();

};