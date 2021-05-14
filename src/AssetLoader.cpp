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

Entity *loadEntity(float x, float y, const char *filePath) {

	Entity *returnEntity = nullptr;

	//	Create Texture
	SDL_Texture *texture = loadTexture(filePath);

	//	Create Entity
	returnEntity = new Entity(x, y, texture);

	return returnEntity;

}

Label *loadLabel(float x, float y, std::string text, const char *fontFile, int fontSize, SDL_Color color = {255,255,255}) { 

	Label *returnLabel = nullptr;

	//	Create Font
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);

	//	Create Surface
	SDL_Surface *surface = TTF_RenderText_Solid(font,
        text.c_str(), color);

	//	Create Texture
	SDL_Texture *texture = SDL_CreateTextureFromSurface(asset_renderer, surface);

	//	Create Label
	returnLabel = new Label(x, y, text, font, surface, texture);

	return returnLabel;

}

Game::Level *loadLevel(std::string levelName) {

	Game::Level *level = nullptr;

	if (levelName == "testLevel") {

		std::vector<Entity *> screenObjects;

		//	Entity Test
		Entity *yeeter = loadEntity(110, 0, "res/img/yeetus.png");
		yeeter->setScaleX(.25f);
		level->setPlayerEntity(yeeter);
		screenObjects.push_back(yeeter);

		//	Label *label;
		Label *label = loadLabel(0, 0, "YEETERS! LOL!", "res/fnt/DTM-Mono.ttf", 25, {255,255,255}); 
		screenObjects.push_back(label);

		Game::Stage *testStage = loadStage(screenObjects);

		level->addStage(testStage);

	}
	else if (levelName == "TitleScreen") {

		Game::TitleLevel *title = new Game::TitleLevel();

		level = title;

	}
	else {
		delete level;
		level = nullptr;
	}

	return level;

}

Game::Level *loadLevel(Levels levelCode) {

	Game::Level *level = nullptr;

	switch (levelCode) {
		case Levels::TITLELEVEL:
			level = new Game::TitleLevel();
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