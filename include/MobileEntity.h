#pragma once
#include "Entity.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace Math;

const float GravityConstant = 9.81f;

class Entity;

class MobileEntity : public Entity {

protected:

	Vector2D velocity;
	Vector2D acceleration;
	float maxSpeed;
	float decelerationValue;

public:

	///	Getters

	Vector2D &getVelocity();
	Vector2D &getAcceleration();
	float &getMaxSpeed();
	float &getDecelerationValue();

	///	Setters

	void setVelocityX(float x);
	void setVelocityY(float y);
	void setVelocity(float x, float y);
	void setMaxSpeed(float speedValue);
	void setDecelerationValue(float decelerationValue);
	void setSpeed(float speed);

	///	Functions

	void applyPhysics(float dt);
	virtual void update(float dt);

	///	Constructors

public:

	MobileEntity(const char *filePath, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255}, float maxSpeed = 1000.f, float decelerationValue = 0.f);

protected:

	MobileEntity(SDL_Texture *texture, float x = 0.f, float y = 0.f, float maxSpeed = 1000.f, float decelerationValue = 0.f);
	MobileEntity(SDL_Texture *texture, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255}, float maxSpeed = 1000.f, float decelerationValue = 0.f);

public:

	//	Copy Constructor
	//Entity(const Entity &other);

	//	Move Constructor
	//Entity(Entity &&other); 

	//	Destructor

	virtual ~MobileEntity();

};