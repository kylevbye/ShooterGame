#pragma once
#include "Level.h"
#include "TitleLevel.h"
#include "MainMenuLevel.h"
#include "InstructionLevel.h"
#include "LoadingBattleLevel.h"
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