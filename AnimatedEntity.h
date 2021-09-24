#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Math.h"
#include "MobileEntity.h"

using namespace Math;

class AnimatedEntity : public MobileEntity {

private:

	int frameCount;
	int frames;
	int frameDelay;
	bool looping;
	bool done;
	Uint32 lastFrameUpdate;
	float accumulator;

public:

	bool isLooping() { return looping; }
	bool isDone() { return done; }

	void setLooping(bool loopingFlag);
	void setDone(bool doneFlag);

	void update(float dt);

	AnimatedEntity(const char *filePath, int frames, int frameDelay, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255});

	virtual ~AnimatedEntity() {}

};