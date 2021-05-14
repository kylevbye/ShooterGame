#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include "Game/Stage.h"

///
///	Forward Declarations
///

class Entity; 

namespace Game {

	class Level;
	class Stage;

}

class Game::Level {

protected:

	std::vector<Stage *> stages;
	Entity *playerEntity;
	Uint32 startTime;

public:

	//	Getter
	Entity *getPlayerEntity() { return playerEntity; }

	//	Setter
	void setPlayerEntity(Entity *entity) {
		this->playerEntity = entity;
	}

	void addStage(Game::Stage *stage);

	virtual void update(float dt);
	virtual void updateEvents(Uint32 time, float dt) = 0;
	virtual void render(SDL_Renderer *renderer);

	Level();
	virtual ~Level();

};