#include "Collidable.h"

Collision::Rectangle &Collidable::getCollisionRect() { return collisionRect; }

void Collidable::setCollisionShape(Collision::Rectangle &collisionRect) {
	this->collisionRect = collisionRect;
}

bool Collidable::intersectsWith(Collidable &other) {
	return this->collisionRect.intersectsWith(other.collisionRect);
}

Collidable::Collidable(Collision::Rectangle collisionRect) 
	: collisionRect(collisionRect) {}
