#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Math.h"
#include "Entity.h"
#include <string>

using namespace Math;

class AnimatedEntity : public Entity {

private:

	int frameCount;
	int frames;
	int frameDelay;
	bool looping;
	bool done;
	Uint32 lastFrameUpdate;

public:

	bool isLooping() { return looping; }
	bool isDone() { return done; }

	void setLooping(bool loopingFlag);
	void setDone(bool doneFlag);

	void update(float dt);

	AnimatedEntity(SDL_Texture *texture, int frames, int frameDelay, float x = 0.f, float y = 0.f, bool activeFlag = true, bool centeredFlag = false, Uint8 alpha = 255, float scaleX = 1.f, float scaleY = 1.f, float originX = 0.f, float originY = 0.f, float angleDeg = 0.f, SDL_RendererFlip flipSetting = SDL_FLIP_NONE, SDL_Color color = {255,255,255}, float maxSpeed = 10000000.f, float decelerationValue = 0.f);

};