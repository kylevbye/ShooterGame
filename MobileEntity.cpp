#include "MobileEntity.h"

///
///	Getters
///

Vector2D &MobileEntity::getVelocity() { return velocity; }
Vector2D &MobileEntity::getAcceleration() { return acceleration; }
float &MobileEntity::getMaxSpeed() { return maxSpeed; }
float &MobileEntity::getDecelerationValue() { return decelerationValue; }

///
///	Setters
///

void MobileEntity::setVelocityX(float vX) { 
	this->velocity.x = vX; 
}
void MobileEntity::setVelocityY(float vY) { 
	this->velocity.y = vY; 
}
void MobileEntity::setVelocity(float vX, float vY) { 
	setVelocityX(vX); setVelocityY(vY);
}
void MobileEntity::setAccelerationX(float x) {
	this->acceleration.x = x;
}
void MobileEntity::setAccelerationY(float y) {
	this->acceleration.y = y;
}
void MobileEntity::setAcceleration(float x, float y) {
	setAccelerationX(x); setAccelerationY(y);
}
void MobileEntity::setMaxSpeed(float speedValue) { 
	this->maxSpeed = speedValue; 
}
void MobileEntity::setDecelerationValue(float decelerationValue) {
	this->decelerationValue = decelerationValue;
}
void MobileEntity::setSpeed(float speedValue) {
	if (velocity.magnitude() == 0.f) {
		velocity.x = speedValue;
	}
	else velocity.setMagnitude(speedValue);
}

///
///	Functions
///

void MobileEntity::applyPhysics(float dt) {

	float speed = 0.f;

	//	Applying Acceleration
	velocity.x += acceleration.x*dt;
	velocity.y += acceleration.y*dt;

	//	Applying Decel (if needed)
	if (acceleration.magnitude() == 0.f) {
		speed -= decelerationValue*dt;
	}

	//	Bound Speed
	speed = Math::clamp(speed, 0.f, maxSpeed);
	setSpeed(speed);

	//	Apply Motion
	position.x += velocity.x*dt;
	position.y += velocity.y*dt;

	//	Reset Accel
	acceleration.x = 0.f;
	acceleration.y = 0.f;

}

void MobileEntity::update(float dt) {
	Entity::update(dt);
	applyPhysics(dt);
}

///
///	Constructors
///

MobileEntity::MobileEntity(const char *filePath, float x, float y, SDL_Color color, float maxSpeed, float decelerationValue)
	: Entity(filePath, x, y, color), maxSpeed(maxSpeed), decelerationValue(decelerationValue) {}

MobileEntity::MobileEntity(SDL_Texture *texture, float x, float y, float maxSpeed, float decelerationValue) 
	: Entity(texture, x, y), maxSpeed(maxSpeed), decelerationValue(decelerationValue) {}

MobileEntity::MobileEntity(SDL_Texture *texture, float x, float y, SDL_Color color, float maxSpeed, float decelerationValue)
	: Entity(texture, x, y, color), maxSpeed(maxSpeed), decelerationValue(decelerationValue) {}

///
///	Destructors
///

MobileEntity::~MobileEntity() {}
