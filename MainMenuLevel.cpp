#include "MainMenuLevel.h"
#include <iostream>

using namespace Game;

void MainMenuLevel::update(float dt, const ControlState &controlState) {

	//	Reset Labels
	startLabel.setColor({255,255,255});
	startLabel.setAlpha(255);
	instructionLabel.setColor({255,255,255});
	instructionLabel.setAlpha(255);

	if(controlState.commitingAction()) {

		switch (selectedOption) {
			case BEGIN_GAME:
				nextLevelCode = Levels::LOADING_BATTLE;
				break;
			case HOW_TO_PLAY:
				nextLevelCode = Levels::INSTRUCTION_MENU;
				break;
			case CREDITS:
				nextLevelCode = Levels::TEST_LEVEL;
				break;
			case QUIT_GAME:
				isRunning = false;
				return;
			default:
				SDL_Log("selectedOption, \"%d\" not in valid parameters.", selectedOption);
				break;
		}

		switch (selectedOption) 

		if (selectedOption == Options::BEGIN_GAME) {
			nextLevelCode = Levels::LOADING_BATTLE;
		}
		else if (selectedOption == Options::HOW_TO_PLAY) {
			nextLevelCode = Levels::INSTRUCTION_MENU;
		}

		menuMusic->stop();
		done = true;

	}

	if (controlState.movedDown()) {

		selectedOption = (selectedOption==QUIT_GAME) ? BEGIN_GAME : (Options) ((int) selectedOption+1);

	}

	if (controlState.movedUp()) {

		selectedOption = (selectedOption==BEGIN_GAME) ? QUIT_GAME : (Options) ((int) selectedOption-1);

	}

	for (MobileEntity * particle : particles) {

		if (particle->getY() >= screenHeight + screenHeight/10) {

			float newX, newY;

			newX = rand() % (int)screenWidth/4;
			newY = -1 * (rand() % (int)screenHeight*2);
			if (rand() % 2 == 0) {
				newX += (.75f*screenWidth);
			} 

			particle->setPosition(newX, newY);
		}

		particle->setVelocityY(100.f);

	}

	//	Call Base
	Level::update(dt, controlState);

}

void MainMenuLevel::updateEvents(Uint32 time, float dt) {

	Level::updateEvents(time,dt);

	if (!menuMusic->isPlayed() && time > 3000) {
		menuMusic->play(20);
	}
	
	//	update alpha
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


	//	Update Gloes
	startLabel.setAlpha(255);
	startLabel.setColor({255, 255, 255});
	instructionLabel.setAlpha(255);
	instructionLabel.setColor({255, 255, 255});
	creditLabel.setAlpha(255);
	creditLabel.setColor({255, 255, 255});
	quitLabel.setAlpha(255);
	quitLabel.setColor({255, 255, 255});

	switch (selectedOption) {
		case BEGIN_GAME:
			startLabel.setAlpha((Uint8)alpha);
			startLabel.setColor({255, 255, 0});
			break;
		case HOW_TO_PLAY:
			instructionLabel.setAlpha((Uint8) alpha);
			instructionLabel.setColor({255, 255, 0});
			break;
		case CREDITS:
			creditLabel.setAlpha((Uint8) alpha);
			creditLabel.setColor({255, 255, 0});
			break;
		case QUIT_GAME:
			quitLabel.setAlpha((Uint8) alpha);
			quitLabel.setColor({255, 255, 0});
			break;
		default:
			SDL_Log("selectedOption, \"%d\" not in valid parameters.", selectedOption);
			break;
	}

}

void MainMenuLevel::setup() {

	Level::setup();

	//	Reset Music
	menuMusic->setPlayed(false);

	//	Reset selectedOption
	selectedOption = Options::BEGIN_GAME;

	//	Reset Particles
	for (Entity *particle : particles) {
		particle->setY(2*screenHeight);
	}

	//	Reset Alpha
	alpha = 0;

}

MainMenuLevel::MainMenuLevel() : menuMusic(nullptr), gameTitleLabel("res/fnt/MonsterFriendFore.ttf", "ShooterGame", 30), startLabel("res/fnt/DTM-Mono.ttf", "Begin Game", 20), instructionLabel("res/fnt/DTM-Mono.ttf", "How to Play", 20), creditLabel("res/fnt/DTM-Mono.ttf", "Credits", 20), quitLabel("res/fnt/DTM-Mono.ttf", "Quit", 20), selectedOption(Options::BEGIN_GAME), asgoreEntity("res/img/asgoreLookDown.png"), alpha(0), fadeIn(true) {

	std::vector<Entity *> screenObjects;

	//	menuMusic
	menuMusic = loadMusic("res/mus/menumusic.wav");

	//	gameTitleLabel
	gameTitleLabel.setCentered(true);
	gameTitleLabel.setActive(true);
	screenObjects.push_back(&gameTitleLabel);

	//	startLabel
	int sW, sH;
	TTF_SizeText(startLabel.getFont(), startLabel.getText().c_str(), &sW, &sH);
	startLabel.setPosition(screenWidth/2-sW/2, screenHeight*(5.f/8.f)-sH/2);
	startLabel.setCentered(false);
	startLabel.setActive(true);
	screenObjects.push_back(&startLabel);

	//	instructionLabel
	int iW, iH;
	TTF_SizeText(instructionLabel.getFont(), instructionLabel.getText().c_str(), &iW, &iH);
	instructionLabel.setPosition(screenWidth/2-iW/2, screenHeight*(5.f/8.f)-iH/2+2*sH);
	instructionLabel.setCentered(false);
	instructionLabel.setActive(true);
	screenObjects.push_back(&instructionLabel);

	//	creditLabel
	int cW, cH;
	TTF_SizeText(creditLabel.getFont(), creditLabel.getText().c_str(), &cW, &cH);
	creditLabel.setPosition(screenWidth/2-cW/2, screenHeight*(5.f/8.f)-cH/2+4*sH);
	creditLabel.setActive(true);
	screenObjects.push_back(&creditLabel);

	//	quitLabel
	int qW, qH;
	TTF_SizeText(quitLabel.getFont(), quitLabel.getText().c_str(), &cW, &cH);
	quitLabel.setPosition(screenWidth/2-cW/2, screenHeight*(5.f/8.f)-cH/2+6*sH);
	quitLabel.setActive(true);
	screenObjects.push_back(&quitLabel);

	//	asgore
	asgoreEntity.setActive(true);
	asgoreEntity.setCentered(true);
	asgoreEntity.setScale(1.8f);
	asgoreEntity.setPosition(screenWidth/2, screenHeight/4);
	screenObjects.push_back(&asgoreEntity);	

	//	particles

	int particleCount = 50;
	for (int i = 0; i<particleCount; ++i) {
		MobileEntity *particle = new MobileEntity("res/img/asgoreParticle2.png");
		particle->setY(2*screenHeight);
		particles.push_back(particle);
		screenObjects.push_back((Entity *)particle);
	}

	//	Positioning
	gameTitleLabel.setPosition(screenWidth/2, screenHeight/2);
	
	Game::Stage *mainStage = loadStage(screenObjects);
	addStage(mainStage);

}

MainMenuLevel::~MainMenuLevel() {

	SDL_Log("MainMenuLevel Destroyed ...");

	delete menuMusic;
	for (MobileEntity *particle : particles) {
		if (particle) {
			delete particle;
			particle = nullptr;
		}
	}
	particles.clear();

	menuMusic = nullptr;


}