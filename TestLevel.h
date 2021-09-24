#pragma once
#include "Level.h"
#include "AssetLoader.h"
#include "CollidableEntity.h"
#include "Rectangle.h"
#include "BattleUI.h"
#include "EdgeHandler.h"
#include "ControlState.h"

namespace Game {
	class Level;
	class TestLevel;
}

class Game::TestLevel : public Game::Level {

private:

	CollidableEntity entity1;
	CollidableEntity entity2;
	CollidableEntity rectangle;
	BattleUI bui;
	BattleUI::Options option;
	float upAndDownThing;
	bool goUp;
	EdgeHandler locker;

public:

	//	From Level
	void update(float dt, const ControlState &controlState);
	void updateEvents(Uint32 time, float dt);
	void setup();
	void render(SDL_Renderer *renderer);

	///	Constructors
	TestLevel();

	//	Destructor
	virtual ~TestLevel();
};

