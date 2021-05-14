#pragma once
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
#include "Sound.h"


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

///
///	SDL_Texture
///
SDL_Texture *loadTexture(const char *filePath);

///
///	Entity Class
///
Entity *loadEntity(float x, float y, const char *filePath);

///
///	Label Class
///
Label *loadLabel(float x, float y, std::string text, const char *fontFile, int fontSize, SDL_Color color);

///
///	Level Class
///
Game::Level *loadLevel(std::string levelName);

///
///	Stage Class
///
Game::Stage *loadStage(std::vector<Entity *> entityList);

///
///	Sound Class
///
Sound *loadSound(std::string filePath);
