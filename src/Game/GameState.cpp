#include "Game/GameState.h"

using namespace Game;

Level &GameState::getCurrentLevel() {
	return *(this->currentLevel);
}

void GameState::loadCurrentLevel(std::shared_ptr<Game::Level> newLevel) {

	if (newLevel) {
		currentLevel = std::shared_ptr<Game::Level>(newLevel);
		currentLevel->setup();
	}

}

void GameState::update(float dt) {

	fpsLabel.setActive(false);
	
	if (keyHandler.getKeyStates().ESC_DOWN) {
		if (lastESCPress == 0) lastESCPress = SDL_GetTicks();
		escapeLabel.setActive(true);
	}
	else {
		escapeLabel.setActive(false);
		lastESCPress = 0;
	}

	if (currentLevel) { 
		currentLevel->update(dt, keyHandler.getKeyStates()); 
	}
	keyHandler.resetHandleStates();

	if (lastESCPress > 0 && SDL_GetTicks() - lastESCPress > 3000) {
		isRunning = false;
	}

	if (currentLevel->isDone()) {
		loadCurrentLevel(
				loadLevel(currentLevel->getNextLevelCode())
				);
	}


}

void GameState::showFPS(Uint32 fps) {
	fpsLabel.setText(std::to_string(fps));
	fpsLabel.setActive(true);
}

void GameState::render() {

	if (!asset_renderer) {
		SDL_Log("Rendering in GameState with a null renderer.");
		isRunning = false;
		return;
	}

	SDL_Rect viewport;
	viewport.x = 0;
	viewport.y = 0;
	viewport.w = screenWidth;
	viewport.h = screenHeight;

	SDL_RenderSetViewport(asset_renderer, &viewport);
	currentLevel->render(asset_renderer);
	if (escapeLabel.isActive()) escapeLabel.render(asset_renderer);
	if (fpsLabel.isActive()) fpsLabel.render(asset_renderer);

}

Game::GameState::GameState() : currentLevel(loadLevel("titleLevel")), escapeLabel("res/fnt/DTM-Mono.ttf", " Quiting...", 20), fpsLabel("res/fnt/DTM-Mono.ttf","", 20),  lastESCPress(0) {
	escapeLabel.setActive(false);
	escapeLabel.setCentered(false);
	fpsLabel.setActive(false);
	fpsLabel.setCentered(false);
}

Game::GameState::~GameState() {}