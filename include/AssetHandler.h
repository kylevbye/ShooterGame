#pragma once
#include "Game/Level.h"
#include "Game/Levels/TitleLevel.h"
#include "Game/Levels/MainMenuLevel.h"
#include "Game/Levels/InstructionLevel.h"
#include "Game/Levels/LoadingBattleLevel.h"

namespace Game {
	class Level;
	class TitleLevel;
	class MainMenuLevel;
	class InstructionLevel;
	class LoadingBattleLevel;
}

struct LevelHandler {

	Game::TitleLevel *titleLevel;
	Game::MainMenuLevel *mainMenuLevel;
	Game::InstructionLevel *instructionLevel;
	Game::LoadingBattleLevel *loadingBattleLevel;

};

void cleanupLevels(LevelHandler &levelHandler);