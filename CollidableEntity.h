#pragma once
#include "MobileEntity.h"
#include "Collidable.h"
class CollidableEntity : public MobileEntity, public Collidable {

public:

	virtual void update(float dt);

public:

	CollidableEntity(const char *filePath, Collision::Rectangle collisionRect = {}, float x = 0.f, float y = 0.f, SDL_Color color = {255, 255, 255}, float maxSpeed = 1000.f, float decelerationValue = 0.f);

	CollidableEntity(SDL_Texture *texture, Collision::Rectangle collisionRect = {}, float x = 0.f, float y = 0.f, SDL_Color color = {255, 255, 255}, float maxSpeed = 1000.f, float decelerationValue = 0.f);

};

