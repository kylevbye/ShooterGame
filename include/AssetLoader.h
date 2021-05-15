#pragma once
#include "AssetHandler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>
#include "Entity.h"
#include "Label.h"
#include "Game/Level.h"
#include "Game/Stage.h"
#include "Game/Levels/TitleLevel.h"
#include "Game/Levels/MainMenuLevel.h"
#include "Sound.h"
#include "Music.h"

///
///	Forward Declarations
///
class Entity;
class Label;
namespace Game {
	class Level;
	class TitleLevel;
	class Stage;
}

extern SDL_Renderer *asset_renderer;
extern float screenWidth, screenHeight;
extern struct LevelHandler levels;

///
///	SDL_Texture
///
SDL_Texture *loadTexture(const char *filePath);

///
///	Entity Class
///
Entity *loadEntity(const char *filePath, float x = 0.f, float y = 0.f);

///
///	Label Class
///
Label *loadLabel(float x, float y, std::string text, const char *fontFile, int fontSize, SDL_Color color);

///
///	Level Class
///
Game::Level *loadLevel(std::string levelName);
Game::Level *loadLevel(Levels levelCode);

///
///	Stage Class
///
Game::Stage *loadStage(std::vector<Entity *> entityList);

///
///	Sound Class
///
Sound *loadSound(std::string filePath);

///
///	Music Class
///
Music *loadMusic(std::string filePath);
