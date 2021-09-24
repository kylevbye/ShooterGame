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

/*Entity *loadEntity(const char *filePath, float x, float y) {

	Entity *returnEntity = nullptr;

	//	Create Texture
	SDL_Texture *texture = loadTexture(filePath);

	//	Create Entity
	returnEntity = new Entity(x, y, texture);

	return returnEntity;

}*/

/*AnimatedEntity *loadAnimatedEntity(const char *filePath, int frames, int frameDelay, float x, float y) {

	AnimatedEntity *returnEntity = nullptr;

	//	Create Texture
	SDL_Texture *texture = loadTexture(filePath);

	//	Create AnimatedEntity
	returnEntity = new AnimatedEntity(texture, frames, frameDelay);

	return returnEntity;

}*/

/*Label *loadLabel(std::string text, const char *fontFile, int fontSize, SDL_Color color, float x, float y) { 

	Label *returnLabel = nullptr;

	//	Create Font
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);

	//	Create Label
	returnLabel = new Label(text, font, asset_renderer, x, y, color);

	return returnLabel;

}*/

std::shared_ptr<Game::Level> loadLevel(const char *levelName) {

	Levels levelCode;

	if (strcmp("titleLevel", levelName) == 0) {
		levelCode = Levels::TITLELEVEL;
	}
	else if (strcmp("mainMenu", levelName) == 0) {
		levelCode = Levels::MAIN_MENU;
	}
	else if (strcmp("instructionMenu", levelName) == 0) {
		levelCode = Levels::INSTRUCTION_MENU;
	}
	else if (strcmp("loadingBattle", levelName) == 0) {
		levelCode = Levels::LOADING_BATTLE;
	}
	else if (strcmp("battleDialogue", levelName) == 0) {
		levelCode = Levels::BATTLE_DIALOGUE;
	}
	else if (strcmp("battleIntro", levelName) == 0) {
		levelCode = Levels::BATTLE_INTRO;
	}
	else if (strcmp("battle", levelName) == 0) {
		levelCode = Levels::BATTLE;
	}
	else if (strcmp("ending", levelName) == 0) {
		levelCode = Levels::ENDING;
	}
	else if (strcmp("gameOver", levelName) == 0) {
		levelCode = Levels::GAME_OVER;
	}
	else {
		
		SDL_Log("loadLevel(std::string) was passed with %s", levelName);

	}

	return loadLevel(levelCode);

}

std::shared_ptr<Game::Level> loadLevel(Levels levelCode) {

	switch (levelCode) {

		case Levels::TITLELEVEL:
			return std::move(std::make_shared<Game::TitleLevel>());
		case Levels::MAIN_MENU:
			return std::move(std::make_shared<Game::MainMenuLevel>());
		case Levels::INSTRUCTION_MENU:
			return std::move(std::make_shared<Game::InstructionLevel>());
		case Levels::LOADING_BATTLE:
			return std::move(std::make_shared<Game::LoadingBattleLevel>());
		case Levels::BATTLE_DIALOGUE:
			return std::move(std::make_shared<Game::TitleLevel>());
		case Levels::BATTLE_INTRO:
			return std::move(std::make_shared<Game::TitleLevel>());
		case Levels::BATTLE:
			return std::move(std::make_shared<Game::TitleLevel>());
		case Levels::ENDING:
			return std::move(std::make_shared<Game::TitleLevel>());
		case Levels::GAME_OVER:
			return std::move(std::make_shared<Game::TitleLevel>());
		default:
			return std::move(std::make_shared<Game::TitleLevel>());

	}

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