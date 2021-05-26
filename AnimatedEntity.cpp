#include "AnimatedEntity.h"

///
///	Setters
///

void AnimatedEntity::setLooping(bool loopingFlag) {
	this->looping = loopingFlag;
}

void AnimatedEntity::setDone(bool doneFlag) {
	this->done = doneFlag;
	frameCount = 0;
}

///
///	Functions
///

void AnimatedEntity::update(float dt) {

	//	Base update
	Entity::update(dt);

	//	Update frameCount based on DT
	//	NOTE: Working in MS
	accumulator += dt*1000.f;
	if ((int)accumulator>=frameDelay) {
		if (frameCount <frames-1) {
			++frameCount;
			accumulator -= frameDelay;
		}
		else {
			if (!looping) done = true;
			frameCount = 0;
		}
	}

	//	Update currentFrame
	if (!done) {
		currentFrame.y = (currentFrame.h) * frameCount;
	}

}

///
///	Constructors
///

AnimatedEntity::AnimatedEntity(const char *filePath, int frames, int frameDelay, float x, float y, SDL_Color color)
	: MobileEntity(filePath, x, y, color), frameCount(0), frames(frames), frameDelay(frameDelay), looping(true), done(false), lastFrameUpdate(SDL_GetTicks()), accumulator(0) {

	currentFrame.h /= frames;
}