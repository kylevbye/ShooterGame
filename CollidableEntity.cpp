#include "CollidableEntity.h"

void CollidableEntity::update(float dt) {

	//	Update Physics First
	MobileEntity::update(dt);

	//	Update Collision Rectangle
	collisionRect.position.x = position.x-collisionRect.width/2;
	collisionRect.position.y = position.y-collisionRect.height/2;
	if (!centeredFlag) {
		collisionRect.position.x += getWidth()/2;
		collisionRect.position.y += getHeight()/2;
	}

}

CollidableEntity::CollidableEntity(const char *filePath, Collision::Rectangle collisionRect, float x, float y, SDL_Color color, float maxSpeed, float decelerationValue)
	: MobileEntity(filePath, x, y, color, maxSpeed, decelerationValue), Collidable(collisionRect) {}

CollidableEntity::CollidableEntity(SDL_Texture *texture, Collision::Rectangle collisionRect, float x, float y, SDL_Color color, float maxSpeed, float decelerationValue)
	: MobileEntity(texture, x, y, color, maxSpeed, decelerationValue), Collidable(collisionRect) {}
