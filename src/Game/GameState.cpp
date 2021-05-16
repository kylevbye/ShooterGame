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

	fpsLabel->setActive(false);
	
	if (keyHandler.getKeyStates().ESC_DOWN) {
		if (lastESCPress == 0) lastESCPress = SDL_GetTicks();
		escapeLabel->setActive(true);
	}
	else {
		escapeLabel->setActive(false);
		lastESCPress = 0;
	}

	if (currentLevel) { 
		currentLevel->update(dt, keyHandler.getKeyStates()); 
	}
	keyHandler.resetHandleStates();

	if (lastESCPress > 0 && SDL_GetTicks() - lastESCPress > 3000) {
		isRunning = false;
	}


}

void GameState::showFPS(int fps) {
	fpsLabel->setText(std::to_string(fps), renderer);
	fpsLabel->setActive(true);
}

void GameState::render() {

	if (!renderer) {
		SDL_Log("Rendering in GameState with a null renderer.");
		isRunning = false;
	}

	SDL_Rect viewport;
	viewport.x = 0;
	viewport.y = 0;
	viewport.w = screenWidth;
	viewport.h = screenHeight;

	SDL_RenderSetViewport(renderer, &viewport);
	currentLevel->render(renderer);
	if (escapeLabel && escapeLabel->isActive()) escapeLabel->render(renderer);
	if (fpsLabel->isActive()) fpsLabel->render(renderer);

}

Game::GameState::GameState() : renderer(nullptr), escapeLabel(nullptr), lastESCPress(0) {
}

Game::GameState::GameState(SDL_Renderer *renderer) : renderer(renderer), escapeLabel(nullptr), fpsLabel(nullptr),  lastESCPress(0) {
	escapeLabel = loadLabel(" Quiting...", "res/fnt/DTM-Mono.ttf", 20);
	escapeLabel->setActive(false);
	escapeLabel->setCentered(false);

	fpsLabel = loadLabel("", "res/fnt/DTM-Mono.ttf", 20);
	fpsLabel->setActive(false);
	fpsLabel->setCentered(false);
}

Game::GameState::~GameState() {

	delete escapeLabel;
	delete fpsLabel;

	escapeLabel = nullptr;
	fpsLabel = nullptr;

}