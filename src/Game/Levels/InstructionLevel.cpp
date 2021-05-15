#include "Game/Levels/InstructionLevel.h"

using namespace Game;

void InstructionLevel::update(float dt, const KeyStates &keyStates) {

	Level::update(dt, keyStates);
}

void InstructionLevel::updateEvents(Uint32 time, float dt) {

	Level::updateEvents(time, dt);

}

void InstructionLevel::setup() {

}

InstructionLevel::InstructionLevel() {

	std::vector<Entity *> screenObjects;

	//	instructionMusic
	instructionMusic = loadMusic("res/mus/titlemusic.wav");

	//	titleLabel
	titleLabel = loadLabel(0, 0, "Instructions", "res/fnt/DTM-Mono.ttf", 100, {255,255,255});
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

		instructionLabel = loadLabel(screenWidth*.375f, screenHeight/3+((screenHeight/15)*i), text, "res/fnt/DTM-Mono.ttf", 25, {255,255,255});
		instructionLabel->setCentered(false);

		instructionLabels.push_back(instructionLabel);
		screenObjects.push_back(instructionLabel);

	}

	//	doneLabel
	doneLabel = loadLabel(0,0,"Z TO EXIT", "res/fnt/DTM-Mono.ttf", 35, {255,255,255});
	doneLabel->setCentered(true);
	doneLabel->setPosition(screenWidth/2, screenHeight-(screenHeight/12));
	screenObjects.push_back(doneLabel);

	Game::Stage *mainStage = loadStage(screenObjects);
	addStage(mainStage);

}

InstructionLevel::~InstructionLevel() {

	//	Free 
	delete instructionMusic;
	delete titleLabel;
	for (Label *instructionLabel : instructionLabels) {
		delete instructionLabel;
	}
	instructionLabels.clear();
	delete doneLabel;

	//	UNDANGLE THEM POINTERS!
	instructionMusic = nullptr;
	titleLabel = nullptr;
	doneLabel = nullptr;
}