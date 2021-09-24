#include "TitleLevel.h"

using namespace Game;

void Game::TitleLevel::update(float dt, const ControlState &controlState) {

	//	Handle Controls
	if (controlState.commitingAction()) {
		nextLevelCode = Levels::MAIN_MENU;
		titleMusic->stop();
		done = true;
	}


	//	Call Base Class method
	Game::Level::update(dt, controlState);

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
		titleLabelFront.setActive(true);
		titleLabelBack.setActive(true);
	}
	
	//	Update Activity of InstructLabel
	if (time > 4000) {
		instructionLabel.setActive(true);

		float alphadt = 100.f;
		if (fadeIn) {
			alpha += alphadt*dt;
			if (alpha>255.f) {
				alpha = 255;
				fadeIn = false;
			}
		}
		else {
			alpha -= alphadt*dt;
			if (alpha<0.f) {
				alpha = 0.f;
				fadeIn = true;
			}
		}

		instructionLabel.setAlpha((Uint8)alpha);

	}

}

void TitleLevel::setup() {
	Level::setup();

	//	Labels
	titleLabelFront.setActive(false);
	titleLabelBack.setActive(false);
	instructionLabel.setActive(false);

	//	Sounds
	if (titleDropSound) titleDropSound->setPlayed(false);

	//	Music
	if (titleMusic) titleMusic->setPlayed(false);

	// Alpha
	alpha = 255; 
	fadeIn = false;

}

Game::TitleLevel::TitleLevel() 
	: Game::Level(), 
	titleLabelFront("res/fnt/MonsterFriendFore.ttf", "Undertale AU", 70), 
	titleLabelBack("res/fnt/MonsterFriendFore.ttf", "Undertale AU", 70), 
	instructionLabel("res/fnt/DTM-Mono.ttf", "Press Z to Start", 30, 0, 0, {128,128,128}), 
	titleDropSound(nullptr) ,
	alpha(255), fadeIn(false)
	{

	std::vector<Entity *> screenObjects;

	
	//	Title Label Front
	titleLabelFront.setCentered(true);
	titleLabelFront.setActive(false);
	screenObjects.push_back(&titleLabelFront);

	//	Title Label Back
	titleLabelBack.setCentered(true);
	titleLabelBack.setActive(false);
	screenObjects.push_back(&titleLabelBack);

	//	insLabel
	instructionLabel.setActive(false);
	instructionLabel.setCentered(true);
	screenObjects.push_back(&instructionLabel);

	//	DROP SOUND
	titleDropSound = loadSound("res/snd/titledrop.wav");

	//	Music
	titleMusic = loadMusic("res/mus/titlemusic.wav");

	//	Positioning
	int tL_h = titleLabelFront.getFontHeight();
	titleLabelFront.setPosition(screenWidth/2, screenHeight/2-tL_h);
	titleLabelBack.setPosition(titleLabelFront.getX(), titleLabelFront.getY());
	instructionLabel.setPosition(screenWidth/2, screenHeight-screenHeight/3);

	Game::Stage *titleStage = loadStage(screenObjects);
	addStage(titleStage);

}

TitleLevel::~TitleLevel() {

	SDL_Log("TitleLevel Destroyed...");

	//	Free
	delete titleDropSound;
	delete titleMusic;

	//	Realign Pointers
	titleDropSound = nullptr;
	titleMusic = nullptr;

}