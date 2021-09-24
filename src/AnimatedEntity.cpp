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

	//	Update frameCount
	Uint32 now = SDL_GetTicks();
	if (looping) { 
		frameCount = (SDL_GetTicks()/frameDelay) % frames;
	}
	else if (!done && now > lastFrameUpdate + frameDelay) {
		++frameCount;
		if (frameCount > frames - 1) {
			done = true;
			frameCount = 0;
		}
		//frameCount = (frameCount < frames-1) ? ++frameCount : 0;
		lastFrameUpdate = now;
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
	: MobileEntity(filePath, x, y, color), frames(frames), frameDelay(frameDelay), looping(true), done(false), lastFrameUpdate(SDL_GetTicks()) {

	currentFrame.h /= frames;
}