#include "Game/GameState.h"

using namespace Game;

PlayerController &GameState::getPlayerController() {
	return this->playerController;
}

Level &GameState::getCurrentLevel() {
	return *(this->currentLevel);
}

void GameState::setRenderer(SDL_Renderer *renderer) {
	this->renderer = renderer;
}

void GameState::loadCurrentLevel(Level *newLevel) {

	if (newLevel) {
		currentLevel = newLevel;
		currentLevel->setup();
	}

}

void GameState::update(float dt) {

	playerController.applyKeyState(keyHandler.getKeyStates());
	playerController.update(dt);
	if (currentLevel) { 
		currentLevel->update(dt, keyHandler.getKeyStates()); 
	}
	keyHandler.resetHandleStates();


}

void GameState::render() {

	if (!renderer) {

	}

	SDL_Rect viewport;
	viewport.x = 0;
	viewport.y = 0;
	viewport.w = screenWidth;
	viewport.h = screenHeight;

	SDL_RenderSetViewport(renderer, &viewport);
	currentLevel->render(renderer);

}

Game::GameState::GameState() : renderer(nullptr) {}

Game::GameState::GameState(SDL_Renderer *renderer) : renderer(renderer) {}