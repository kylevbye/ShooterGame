#include "Game/Levels/InstructionLevel.h"

using namespace Game;

void InstructionLevel::update(float dt, const KeyStates &keyStates) {

	if (keyStates.Z_PRESSED) {
		nextLevelCode = Levels::MAIN_MENU;
		instructionMusic->stop();
		done = true;
	}

	if (!instructionMusic->isPlayed()) {
		instructionMusic->play(20);
	}

	Level::update(dt, keyStates);
}

void InstructionLevel::updateEvents(Uint32 time, float dt) {

	Level::updateEvents(time, dt);

	//	update alpha
	if (time % 5*dt == 0) {
		if (fadeIn) {
			++alpha;
			if (alpha >= 255) fadeIn = false;
		}
		else {
			--alpha;
			if(alpha <= 0) fadeIn = true;
		}
	}

	doneLabel->setAlpha(alpha);

}

void InstructionLevel::setup() {

	done = false;
	nextLevelCode = Levels::MAIN_MENU;
	instructionMusic->setPlayed(false);

}

InstructionLevel::InstructionLevel() : asgore(nullptr),instructionMusic(nullptr), titleLabel(nullptr), doneLabel(nullptr), alpha(0), fadeIn(false) {

	std::vector<Entity *> screenObjects;

	//	asgore
	asgore = loadAnimatedEntity("res/anim/knifeslash1.png", 7, 150);
	asgore->setScaleX(10);
	asgore->setScaleY(20);
	screenObjects.push_back(asgore);

	//	instructionMusic
	instructionMusic = loadMusic("res/mus/instructionmusic.wav");

	//	titleLabel
	titleLabel = loadLabel("Instructions", "res/fnt/DTM-Mono.ttf", 100, {255,255,255});
	titleLabel->setCentered(true);
	titleLabel->setPosition(screenWidth/2, screenHeight/6);
	screenObjects.push_back(titleLabel);

	//	instructionLabels
	for (int i = 0; i<6; ++i) {

		Label *instructionLabel;

		std::string text;
		switch (i) {
			case 0:
				text = "W / Up    ==> MOVE UP";
				break;
			case 1:
				text = "A / Left  ==> MOVE LEFT";
				break;
			case 2:
				text = "S / Down  ==> MOVE DOWN";
				break;
			case 3:
				text = "D / Right ==> MOVE RIGHT";
				break;
			case 4:
				text = "Z         ==> ACTION / ACCEPT";
				break;
			case 5:
				text = "X         ==> CANCEL / REJECT";
				break;
		}

		instructionLabel = loadLabel(text, "res/fnt/DTM-Mono.ttf", 25, {255,255,255}, screenWidth*.375f, screenHeight/3+((screenHeight/15)*i));
		instructionLabel->setCentered(false);

		instructionLabels.push_back(instructionLabel);
		screenObjects.push_back(instructionLabel);

	}

	//	doneLabel
	doneLabel = loadLabel("Z TO EXIT", "res/fnt/DTM-Mono.ttf", 35, {255,255,0});
	doneLabel->setCentered(true);
	doneLabel->setPosition(screenWidth/2, screenHeight-(screenHeight/12));
	screenObjects.push_back(doneLabel);

	Game::Stage *mainStage = loadStage(screenObjects);
	addStage(mainStage);

}

InstructionLevel::~InstructionLevel() {

	//	Free 
	delete asgore;
	delete instructionMusic;
	delete titleLabel;
	for (Label *instructionLabel : instructionLabels) {
		delete instructionLabel;
	}
	instructionLabels.clear();
	delete doneLabel;

	//	UNDANGLE THEM POINTERS!
	asgore = nullptr;
	instructionMusic = nullptr;
	titleLabel = nullptr;
	doneLabel = nullptr;
}