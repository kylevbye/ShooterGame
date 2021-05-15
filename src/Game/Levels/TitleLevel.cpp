#include "Game/Levels/TitleLevel.h"

using namespace Game;

void Game::TitleLevel::update(float dt, const KeyStates &keyStates) {

	//	Handle Controls
	if (keyStates.Z_PRESSED) {
		nextLevelCode = Levels::MAIN_MENU;
		titleMusic->stop();
		done = true;
	}


	//	Call Base Class method
	Game::Level::update(dt, keyStates);

}

void Game::TitleLevel::updateEvents(Uint32 time, float dt) {

	//	play sound
	if (!titleDropSound->isPlayed() && time > 2700) {
		titleDropSound->play(80);
	}

	if (!titleMusic->isPlayed() && time > 4000) {
		titleMusic->play(30);
	}

	//	Update Activity of TitleLabels
	if (time > 3000) {
		titleLabelFront->setActive(true);
		titleLabelBack->setActive(true);
	}
	
	//	Update Activity of InstructLabel
	if (time > 4000) {
		instructionLabel->setActive(true);
		int alpha = (time/20)%511;
		if (alpha > 255) alpha = 511 - alpha;
		instructionLabel->setAlpha(alpha);
	}

}

void TitleLevel::setup() {
	Level::setup();

	//	Labels
	titleLabelFront->setActive(false);
	titleLabelBack->setActive(false);
	instructionLabel->setActive(false);

	//	Sounds
	titleDropSound->setPlayed(false);

	//	Music
	titleMusic->setPlayed(false);

}

Game::TitleLevel::TitleLevel() : Game::Level(), titleLabelFront(nullptr), titleLabelBack(nullptr), instructionLabel(nullptr), titleDropSound(nullptr) {

	std::vector<Entity *> screenObjects;

	//	Title Label Front
	titleLabelFront = loadLabel(0, 0, "Undertale AU", "res/fnt/MonsterFriendFore.ttf", 70, {255,255,255});
	titleLabelFront->setCentered(true);
	titleLabelFront->setActive(false);
	screenObjects.push_back(titleLabelFront);

	//	Title Label Back
	titleLabelBack = loadLabel(0, 0, "Undertale AU", "res/fnt/MonsterFriendBack.ttf", 70, {255,255,255});
	titleLabelBack->setCentered(true);
	titleLabelBack->setActive(false);
	screenObjects.push_back(titleLabelBack);

	//	insLabel
	instructionLabel = loadLabel(0, 0, "Press Z to Start", "res/fnt/DTM-Mono.ttf", 30, {128,128,128});
	screenObjects.push_back(instructionLabel);
	instructionLabel->setActive(false);
	instructionLabel->setCentered(true);

	//	DROP SOUND
	titleDropSound = loadSound("res/snd/titledrop.wav");

	//	Music
	titleMusic = loadMusic("res/mus/titlemusic.wav");

	//	Positioning
	int tL_h = titleLabelFront->getFontHeight();
	titleLabelFront->setPosition(screenWidth/2, screenHeight/2-tL_h);
	titleLabelBack->setPosition(titleLabelFront->getX(), titleLabelFront->getY());
	instructionLabel->setPosition(screenWidth/2, screenHeight-screenHeight/3);

	Game::Stage *titleStage = loadStage(screenObjects);
	addStage(titleStage);

}

TitleLevel::~TitleLevel() {

	//	Free
	delete titleLabelFront;
	delete titleLabelBack;
	delete instructionLabel;
	delete titleDropSound;
	delete titleMusic;

	//	Realign Pointers
	titleLabelFront = nullptr;
	titleLabelBack = nullptr;
	instructionLabel = nullptr;
	titleDropSound = nullptr;
	titleMusic = nullptr;

}