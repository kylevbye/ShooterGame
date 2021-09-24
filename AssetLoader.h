#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <memory>
#include <vector>
#include "Level.h"
#include "Stage.h"
#include "TitleLevel.h"
#include "MainMenuLevel.h"
#include "LoadingBattleLevel.h"
#include "InstructionLevel.h"
#include "TestLevel.h"
#include "Sound.h"
#include "Music.h"

///
///	Forward Declarations
///
//class Entity;
//class AnimatedEntity;
//class Label;
namespace Game {
	class Level;
	class TitleLevel;
	class Stage;
}

extern SDL_Renderer *asset_renderer;
extern float screenWidth, screenHeight;
//extern struct LevelHandler levels;

///
///	SDL_Texture
///
SDL_Texture *loadTexture(const char *filePath);

///
///	Entity Class
///
//Entity *loadEntity(const char *filePath, float x = 0.f, float y = 0.f);

///
///	AnimatedEntity Class
///
//AnimatedEntity *loadAnimatedEntity(const char *filePath, int frames, int frameDelay, float x = 0.f, float y = 0.f);

///
///	Label Class
///
//Label *loadLabel(std::string text = "", const char *fontFile = "res/fnt/DTM-Mono.ttf", int fontSize = 12, SDL_Color color = {255,255,255}, float x = 0.f, float y = 0.f);

///
///	Level Class
///
std::shared_ptr<Game::Level> loadLevel(const char *levelName);
std::shared_ptr<Game::Level> loadLevel(Levels levelCode);

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
