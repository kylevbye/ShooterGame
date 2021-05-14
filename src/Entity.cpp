#include "Entity.h"
#include <stdio.h>

std::string Entity::to_string() {

	char buffer[900];

	char bufferB[70];
	snprintf(bufferB, sizeof(bufferB), "X: %d, Y:%d, W:%d, H:%d", currentFrame.x, currentFrame.y, currentFrame.w, currentFrame.h);

	//	Set up format
	const char *format_str = "Entity::[currentFrame = [%s]; texture = [%p]; activeFlag = [%d]; scaleX = [%f]; scaleY = [%f]; originX = [%f]; originY = [%f]; angleDeg = [%f]; flipSetting = [%d]; positionVector = %s; velocityVector = %s; accelerationVector = %s; maxSpeed=[%f]; decelerationValue = [%f]]";

	//	Format all values of this Entity instance.
	snprintf(buffer, sizeof(buffer), format_str, bufferB, texture, activeFlag, scaleX, scaleY, originX, originY, angleDeg, "flipSetting", positionVector.toCStr(), velocityVector.toCStr(), accelerationVector.toCStr(), maxSpeed, decelerationValue);


	return buffer;

}

void Entity::setActive(bool activeFlag) {
	this->activeFlag = activeFlag;
}

void Entity::setCentered(bool centeredFlag) {
	this->centeredFlag = centeredFlag;
}

void Entity::setX(float x) {
	positionVector.x = x;
}

void Entity::setY(float y) {
	positionVector.y = y;
}

void Entity::setVelocityX(float vX) {
	velocityVector.x = vX;
}

void Entity::setVelocityY(float vY) {
	velocityVector.y = vY;
}

void Entity::setVelocity(float vX, float vY) {
	setVelocityX(vX);
	setVelocityY(vY);
}

void Entity::setPosition(float x, float y) {
	setX(x);
	setY(y);
}

void Entity::setAlpha(Uint8 alpha) {
	this->alpha = alpha;
}

void Entity::setScaleX(float scaleX) { 
	this->scaleX = scaleX; 
}

void Entity::setScaleY(float scaleY) { 
	this->scaleY = scaleY; 
}

void Entity::setScale(float scale) {
	setScaleX(scale); 
	setScaleY(scale);
}

void Entity::setOrigin(float originX, float originY) {
	setOriginX(originX);
	setOriginY(originY);
}

void Entity::setAngleDeg(float angleDeg) { 
	this->angleDeg = angleDeg; 
}

void Entity::setMaxSpeed(float speedValue) { 
	if (speedValue >= 0) {
		this->maxSpeed = speedValue; 
	}
}

void Entity::setSpeed(float speedValue) {
	if (velocityVector.magnitude() == 0.f) {
		velocityVector.x = speedValue;
	}
	else velocityVector.setMagnitude(speedValue);
}

void Entity::applyPhysics(float dt) {

	float speed = 0.f;

	//	Applying Acceleration
	velocityVector.x += accelerationVector.x*dt;
	velocityVector.y += accelerationVector.y*dt;

	//	Applying Decel (if needed)
	if (accelerationVector.magnitude() == 0.f) {
		speed -= decelerationValue*dt;
	}

	//	Bound Speed
	speed = Math::clamp(speed, 0.f, maxSpeed);
	setSpeed(speed);

	//	Apply Motion
	positionVector.x += velocityVector.x*dt;
	positionVector.y += velocityVector.y*dt;

	//	Reset Accel
	accelerationVector.x = 0.f;
	accelerationVector.y = 0.f;

}

void Entity::update(float dt) {
	applyPhysics(dt);
}

void Entity::render(SDL_Renderer *renderer) {

	if (!activeFlag) return;

	SDL_Rect source;
	source.x = currentFrame.x; 
	source.y = currentFrame.y;
	source.w = currentFrame.w; 
	source.h = currentFrame.h;

	///	Apply Scaling
	SDL_Rect destination;
	destination.x = positionVector.x; 
	destination.y = positionVector.y;
	destination.w = currentFrame.w * scaleX; 
	destination.h = currentFrame.h * scaleY;

	//	Center if Neccesary
	if (centeredFlag) {
		destination.x -= destination.w/2;
		destination.y -= destination.h/2;
	}

	///	Rotation
	SDL_Point origin;
	origin.x = originX * scaleX;
	origin.y = originY * scaleY;

	///	Render Time
	SDL_SetTextureAlphaMod(texture, alpha);
	//SDL_RenderCopy(renderer, texture, &source, &destination);
	SDL_RenderCopyEx(renderer, texture, &source, &destination, angleDeg, &origin, flipSetting);

}

Entity::Entity(float x, float y, SDL_Texture *texture)
	: texture(texture), activeFlag(true), centeredFlag(false), alpha(255), scaleX(1.f), scaleY(1.f), originX(0.f), originY(0.f), angleDeg(0.f),flipSetting(SDL_FLIP_NONE), positionVector(x,y), velocityVector(0.f, 0.f), accelerationVector(0.f, 0.f), maxSpeed(1000000.f), decelerationValue(0.f) {

	//	Get Width and Height of texture
	//	SDL_Point.x --> width
	//	SDL_Point.y --> height
	SDL_Point textureSize;
	SDL_QueryTexture(texture, nullptr, nullptr, &textureSize.x, &textureSize.y);

	//	Upper left is 0,0 by default
	currentFrame.x = 0; currentFrame.y = 0;
	currentFrame.w = textureSize.x; 
	currentFrame.h = textureSize.y;

	//	Origin is at the center by default
	setOriginX(currentFrame.w/2.f);
	setOriginY(currentFrame.h/2.f);

}

Entity::~Entity() {

	if (texture) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

}