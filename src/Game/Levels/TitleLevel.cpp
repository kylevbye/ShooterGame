#include "Game/Levels/TitleLevel.h"

using namespace Game;

void Game::TitleLevel::update(float dt) {

	//	Call Base Class method
	Game::Level::update(dt);

}

void Game::TitleLevel::updateEvents(Uint32 time, float dt) {

	if (time == 2700) {
		titleDropSound->play();
	}

	//	Update Activity of TitleLabel
	if (time > 3000) {
		titleLabel->setActive(true);
	}
	
	//	Update Activity of InstructLabel
	if (time > 4000) {
		instructionLabel->setActive(true);
		int alpha = (time/20)%511;
		if (alpha > 255) alpha = 511 - alpha;
		instructionLabel->setAlpha(alpha);
	}

}

Game::TitleLevel::TitleLevel() : Game::Level(), titleLabel(nullptr), instructionLabel(nullptr), titleDropSound(nullptr) {

	std::vector<Entity *> screenObjects;

	//	Title Label
	titleLabel = loadLabel(0, 0, "Undertale AU", "res/fnt/DTM-Mono.ttf", 70, {255,255,255});
	titleLabel->setCentered(true);
	titleLabel->setActive(false);
	screenObjects.push_back(titleLabel);

	//	insLabel
	instructionLabel = loadLabel(0, 0, "Press Z to Start", "res/fnt/DTM-Mono.ttf", 30, {128,128,128});
	screenObjects.push_back(instructionLabel);
	instructionLabel->setActive(false);
	instructionLabel->setCentered(true);

	//	DROP SOUND
	titleDropSound = loadSound("res/snd/titledrop.wav");

	//	Positioning
	int tL_h = titleLabel->getFontHeight();
	titleLabel->setPosition(screenWidth/2, screenHeight/2-tL_h);
	instructionLabel->setPosition(screenWidth/2, screenHeight-screenHeight/3);

	Game::Stage *titleStage = loadStage(screenObjects);
	addStage(titleStage);

}