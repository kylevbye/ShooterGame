#pragma once
#include <vector>
<<<<<<< HEAD:include/Game/Level.h
#include <SDL2/SDL.h>
#include "Game/Stage.h"
#include "KeyEventHandler.h"
=======
#include <SDL.h>
#include "Stage.h"
#include "ControlState.h"
>>>>>>> 310f83325ba0c0a9120a95c66b1982b8d5a728f6:Level.h
#include "Entity.h"

///
///	Forward Declarations
///

<<<<<<< HEAD:include/Game/Level.h
struct KeyStates;
=======
class ControlState;
>>>>>>> 310f83325ba0c0a9120a95c66b1982b8d5a728f6:Level.h

namespace Game {

	class Level;
	class Stage;

}

enum Levels {
	TITLELEVEL,
	MAIN_MENU,
	INSTRUCTION_MENU,
	LOADING_BATTLE,
	BATTLE_DIALOGUE,
	BATTLE_INTRO,
	BATTLE,
	ENDING,
	GAME_OVER,
	TEST_LEVEL
};

class Game::Level {

protected:

	std::vector<Stage *> stages;
	Entity *playerEntity;
	Uint32 startTime;
	bool done;
	Levels nextLevelCode;

public:

	//	Getter
	Entity *getPlayerEntity() { return playerEntity; }
	bool isDone() { return done; }
	Levels getNextLevelCode() { return nextLevelCode; } 

	//	Setter
	void setPlayerEntity(Entity *entity) {
		this->playerEntity = entity;
	}

	void addStage(Game::Stage *stage);

	virtual void update(float dt, const ControlState &keyStates);
	virtual void updateEvents(Uint32 time, float dt) = 0;
	virtual void render(SDL_Renderer *renderer);

	virtual void setup();

	Level();
	virtual ~Level();

};