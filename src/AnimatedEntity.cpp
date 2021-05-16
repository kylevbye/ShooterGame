#include "AnimatedEntity.h"

void AnimatedEntity::setLooping(bool loopingFlag) {
	this->looping = loopingFlag;
}

void AnimatedEntity::setDone(bool doneFlag) {
	this->done = doneFlag;
	frameCount = 0;
}

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

AnimatedEntity::AnimatedEntity(SDL_Texture *texture, int frames, int frameDelay, float x, float y, bool activeFlag, bool centeredFlag, Uint8 alpha, float scaleX, float scaleY, float originX, float originY, float angleDeg, SDL_RendererFlip flipSetting, SDL_Color color, float maxSpeed, float decelerationValue) 
	: Entity(x, y, texture, activeFlag, centeredFlag, alpha, scaleX, scaleY, originX, originY, angleDeg, flipSetting, color, maxSpeed, decelerationValue), 
	frameCount(0), frames(frames), frameDelay(frameDelay), looping(true), done(false), lastFrameUpdate(SDL_GetTicks()) {
		
		setTexture(texture);
		currentFrame.h /= frames;

	}