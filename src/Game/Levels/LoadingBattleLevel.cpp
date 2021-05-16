#include "Game/Levels/LoadingBattleLevel.h"

using namespace Game;

void LoadingBattleLevel::update(float dt, const KeyStates &keyStates) {

	if (!knifeSlashSound->isPlayed()) {
		knifeSlashSound->play(70);
	}

	if (!knifeEntity->isDone()) knifeEntity->update(dt);
	else knifeEntity->setActive(false);

	Level::update(dt,keyStates);

}

void LoadingBattleLevel::updateEvents(Uint32 time, float dt) {

	if (!damageSound->isPlayed() && time > 1500) {
		damageSound->play(70);
	}

	if (time > 3000) {
		done = true;
	}

}

void LoadingBattleLevel::setup() {
	Level::setup();

	done = false;
	nextLevelCode = Levels::MAIN_MENU;
	knifeSlashSound->setPlayed(false);
	damageSound->setPlayed(false);
	knifeEntity->setActive(true);
	knifeEntity->setDone(false);

}

LoadingBattleLevel::LoadingBattleLevel() : knifeSlashSound(nullptr), knifeEntity(nullptr) {

	nextLevelCode = Levels::MAIN_MENU;

	std::vector<Entity *> screenObjects;

	//	knifeSlashSound
	knifeSlashSound = loadSound("res/snd/knifeslash.wav");

	//	Impact
	damageSound = loadSound("res/snd/damage.wav");

	//	knifeEnitity
	knifeEntity = loadAnimatedEntity("res/anim/knifeslash1.png", 7, 130);
	knifeEntity->setLooping(false);
	knifeEntity->setScaleX(10);
	knifeEntity->setScaleY(20);

	float offX = knifeEntity->getCurrentFrame().w*knifeEntity->getScaleX()/2;
	float offY = knifeEntity->getCurrentFrame().h*knifeEntity->getScaleY()/2;
	knifeEntity->setX(screenWidth/2 - offX);
	knifeEntity->setY(screenHeight/2 - offY);
	screenObjects.push_back(knifeEntity);

	Game::Stage *mainStage = loadStage(screenObjects);
	addStage(mainStage);

}

LoadingBattleLevel::~LoadingBattleLevel() {

	//	Free
	delete knifeSlashSound;
	delete damageSound;
	delete knifeEntity;

	//	STOP THE DANGLING POINTERS!
	knifeSlashSound = nullptr;
	damageSound = nullptr;
	knifeEntity = nullptr;

}