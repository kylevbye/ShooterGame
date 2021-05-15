#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include "Game/Stage.h"
#include "KeyEventHandler.h"

///
///	Forward Declarations
///

class Entity; 
struct KeyStates;

namespace Game {

	class Level;
	class Stage;

}

enum Levels {
	TITLELEVEL,
	MAIN_MENU,
	INSTRUCTION_MENU,
	BATTLE_DIALOGUE,
	BATTLE_INTRO,
	BATTLE,
	ENDING,
	GAME_OVER
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

	virtual void update(float dt, const KeyStates &keyStates);
	virtual void updateEvents(Uint32 time, float dt) = 0;
	virtual void render(SDL_Renderer *renderer);

	virtual void setup();

	Level();
	virtual ~Level();

};