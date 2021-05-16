#include "AssetLoader.h"

SDL_Texture *loadTexture(const char *filePath) {

	SDL_Texture *returnTexture = nullptr;
	returnTexture = IMG_LoadTexture(asset_renderer, filePath);

	//	Log if texture fails to load.
	if (!returnTexture) {
		SDL_Log("Unable to init load texture at {%s}: %s", filePath, SDL_GetError());
	}

	return returnTexture;

}

Entity *loadEntity(const char *filePath, float x, float y) {

	Entity *returnEntity = nullptr;

	//	Create Texture
	SDL_Texture *texture = loadTexture(filePath);

	//	Create Entity
	returnEntity = new Entity(x, y, texture);

	return returnEntity;

}

AnimatedEntity *loadAnimatedEntity(const char *filePath, int frames, int frameDelay, float x, float y) {

	AnimatedEntity *returnEntity = nullptr;

	//	Create Texture
	SDL_Texture *texture = loadTexture(filePath);

	//	Create AnimatedEntity
	returnEntity = new AnimatedEntity(texture, frames, frameDelay);

	return returnEntity;

}

Label *loadLabel(std::string text, const char *fontFile, int fontSize, SDL_Color color, float x, float y) { 

	Label *returnLabel = nullptr;

	//	Create Font
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);

	//	Create Label
	returnLabel = new Label(text, font, asset_renderer, x, y, color);

	return returnLabel;

}

Game::Level *loadLevel(std::string levelName) {

	Levels levelCode;

	if (levelName == "titleLevel") {
		levelCode = Levels::TITLELEVEL;
	}
	else if (levelName == "mainMenu") {
		levelCode = Levels::MAIN_MENU;
	}
	else if (levelName == "instructionMenu") {
		levelCode = Levels::INSTRUCTION_MENU;
	}
	else if (levelName == "loadingBattle") {
		levelCode = Levels::LOADING_BATTLE;
	}
	else if (levelName == "battleDialogue") {
		levelCode = Levels::BATTLE_DIALOGUE;
	}
	else if (levelName == "battleIntro") {
		levelCode = Levels::BATTLE_INTRO;
	}
	else if (levelName == "battle") {
		levelCode = Levels::BATTLE;
	}
	else if (levelName == "ending") {
		levelCode = Levels::ENDING;
	}
	else if (levelName == "gameOver") {
		levelCode = Levels::GAME_OVER;
	}
	else {
		return nullptr;
	}

	return loadLevel(levelCode);

}

Game::Level *loadLevel(Levels levelCode) {

	Game::Level *level = nullptr;

	switch (levelCode) {
		case Levels::TITLELEVEL:
			if (!levels.titleLevel) {
				level = new Game::TitleLevel();
				levels.titleLevel = (Game::TitleLevel *)level;
			}
			else level = levels.titleLevel;
			break;
		case Levels::MAIN_MENU:
			if (!levels.mainMenuLevel) {
				level = new Game::MainMenuLevel();
				levels.mainMenuLevel = (Game::MainMenuLevel *)level;
			}
			else level = levels.mainMenuLevel;
			break;
		case Levels::INSTRUCTION_MENU:
			if(!levels.instructionLevel) {
				level = new Game::InstructionLevel();
				levels.instructionLevel = (Game::InstructionLevel *)level;
			}
			else level = levels.instructionLevel;
			break;
		case Levels::LOADING_BATTLE:
			if(!levels.loadingBattleLevel) {
				level = new Game::LoadingBattleLevel();
				levels.loadingBattleLevel = (Game::LoadingBattleLevel *)level;
			}
			else level = levels.loadingBattleLevel;
			break;
		case Levels::BATTLE_DIALOGUE:
			break;
		case Levels::BATTLE_INTRO:
			break;
		case Levels::BATTLE:
			break;
		case Levels::ENDING:
			break;
		case Levels::GAME_OVER:
			break;
		default:
			break;

	}

	return level;

}

Game::Stage *loadStage(std::vector<Entity *> entityList) {

	Game::Stage *returnStage = new Game::Stage();

	for (Entity *entity : entityList) {

		//	If an entity is null, don't add it.
		if (!entity) continue;

		//	Reset position to 0, 0
		//entity->setPosition(0.f, 0.f);
		returnStage->addScreenObject(entity);

	}
	
	returnStage->setActive(true);

	return returnStage;

}

Sound *loadSound(std::string filePath) {

	Sound *returnSound = nullptr;

	Mix_Chunk *chunk = Mix_LoadWAV(filePath.c_str());
	if (chunk) returnSound = new Sound(chunk, 64);
	else SDL_Log("%s failed to load.", filePath.c_str());

	return returnSound;

}

Music *loadMusic(std::string filePath) {

	Music *returnMusic = nullptr;

	Mix_Music *mus = Mix_LoadMUS(filePath.c_str());
	if (mus) returnMusic = new Music(mus);
	else SDL_Log("%s failed to load.", filePath.c_str());

	return returnMusic;

}