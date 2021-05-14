#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Math.h"
#include <string>

using namespace Math;

const float GravityConstant = 9.81f;

class Entity {

private:

	SDL_Rect currentFrame;
	SDL_Texture *texture;

protected:

	bool activeFlag;
	bool centeredFlag;
	Uint8 alpha;
	float scaleX, scaleY;
	float originX, originY;
	float angleDeg;
	SDL_RendererFlip flipSetting;

	Vector2D positionVector;
	Vector2D velocityVector;
	Vector2D accelerationVector;
	float maxSpeed, decelerationValue;

public:

	///	String Representation
	std::string to_string();

	///	Getters
	bool isActive() { return activeFlag; }
	bool isCentered() { return centeredFlag; }
	float getX() { return positionVector.x; }
	float getY() { return positionVector.y; }
	Uint8 getAlpha() { return alpha; }
	float getScaleX() { return scaleX; }
	float getScaleY() { return scaleY; }
	float getOriginX() { return originX; }
	float getOriginY() { return originY; }
	float getAngleDeg() { return angleDeg; }
	Vector2D getPositionVector() { return positionVector; }
	Vector2D getVelocityVector() { return velocityVector; }
	Vector2D getAccelerationVector() { return accelerationVector; }
	float getMaxSpeed() { return maxSpeed; }
	float getDecelerationValue() { return decelerationValue; }
	SDL_Rect getCurrentFrame() { return currentFrame; }
	SDL_Texture *getTexture() { return texture; }

	///	Setters
	void setActive(bool activeFlag);
	void setCentered(bool centeredFlag);
	void setX(float x);
	void setY(float y);
	void setPosition(float x, float y);
	void setVelocityX(float x);
	void setVelocityY(float y);
	void setVelocity(float x, float y);
	void setAlpha(Uint8 alpha);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);
	void setScale(float scale);
	void setOriginX(float originX) { this->originX = originX; }
	void setOriginY(float originY) { this->originY = originY; }
	void setOrigin(float originX, float originY);
	void setAngleDeg(float angleDeg);
	void setMaxSpeed(float speedValue);
	void setDecelerationValue(float decelValue);
	void setSpeed(float speed);

	///	Funct
	void applyPhysics(float dt);
	void moveX(float dx) { positionVector.x += dx; }
	void moveY(float dy) { positionVector.y += dy; }
	void move(float dx, float dy) { moveX(dx); moveY(dy); }
	virtual void update(float dt);
	virtual void render(SDL_Renderer *renderer);

	///	Constructors
	Entity(float x, float y, SDL_Texture *texture);

	///	Destructor
	virtual ~Entity();

};