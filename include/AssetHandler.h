#pragma once
#include "Game/Level.h"
#include "Game/Levels/TitleLevel.h"
#include "Game/Levels/MainMenuLevel.h"
#include "Game/Levels/InstructionLevel.h"

namespace Game {
	class Level;
	class TitleLevel;
	class MainMenuLevel;
	class InstructionLevel;
}

struct LevelHandler {

	Game::TitleLevel *titleLevel;
	Game::MainMenuLevel *mainMenuLevel;
	Game::InstructionLevel *instructionLevel;

};

void cleanupLevels(LevelHandler &levelHandler);