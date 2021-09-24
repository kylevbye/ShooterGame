#pragma once
#include "Game/Level.h"
#include "Game/Levels/TitleLevel.h"
#include "Game/Levels/MainMenuLevel.h"
#include "Game/Levels/InstructionLevel.h"
#include "Game/Levels/LoadingBattleLevel.h"
#include <memory>

namespace Game {
	class Level;
	class TitleLevel;
	class MainMenuLevel;
	class InstructionLevel;
	class LoadingBattleLevel;
}

std::shared_ptr<Game::TitleLevel> TitleLevel;
std::shared_ptr<Game::MainMenuLevel> mainMenuLevel;
std::shared_ptr<Game::InstructionLevel> instructionLevel;
std::shared_ptr<Game::LoadingBattleLevel> loadingBattleLevel;

/*
struct LevelHandler {

	Game::TitleLevel *titleLevel;
	Game::MainMenuLevel *mainMenuLevel;
	Game::InstructionLevel *instructionLevel;
	Game::LoadingBattleLevel *loadingBattleLevel;

};*/

//void cleanupLevels(LevelHandler &levelHandler);