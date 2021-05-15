#include "Game/Level.h"

void Game::Level::addStage(Stage *stage) {
	if (stage) stages.push_back(stage);
}

void Game::Level::update(float dt, const KeyStates &keyStates) {
	Uint32 currentTime = SDL_GetTicks()-startTime;
	updateEvents(currentTime, dt);
	for (Stage *stage : stages) {
		if (stage) stage->update(dt);
	}
}

void Game::Level::updateEvents(Uint32 time, float dt) {}

void Game::Level::render(SDL_Renderer *renderer) {

	for (Stage *stage : stages) {
		stage->render(renderer);
	}

}

void Game::Level::setup() {
	startTime = SDL_GetTicks();
	done = false;
	nextLevelCode = Levels::TITLELEVEL;
}

Game::Level::Level() : startTime(SDL_GetTicks()), done(false), nextLevelCode(Levels::TITLELEVEL) {

}

Game::Level::~Level() {

}