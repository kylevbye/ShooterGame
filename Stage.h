#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include "Entity.h"
#include <memory>

class Entity;

namespace Game {

	class Stage;

}

class Game::Stage {

	private:
//std::shared_ptr<Entity>
		std::vector<Entity*> screenObjects;
		bool activeFlag;

	public:

		//	Getters
		bool isActive() { return activeFlag; }

		//	Setters
		void setActive(bool activeFlag);

		///
		///	String Representations
		///

		//const char *toCStr() { return to_string().c_str(); }
		//std::string to_string();

		void addScreenObject(Entity *screenObject);
		void removeScreenObject(Entity *screenObject);
		void update(float dt);
		void render(SDL_Renderer *renderer);

		Stage();
		virtual ~Stage();

	private:

		int findIndexOfScreenObject(Entity *screenObject);
		void cleanUp();


	};