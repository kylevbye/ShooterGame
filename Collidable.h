#pragma once
#include "MobileEntity.h"
#include "Math.h"
#include "CollisionShapes.h"

class Collidable {

protected:

	Collision::Rectangle collisionRect;

public:

	Collision::Rectangle &getCollisionRect();

	void setCollisionShape(Collision::Rectangle &collisionRect);

	//	Functions
	bool intersectsWith(Collidable &other);
	//Vector2D preventOverlap(Collidable &other);
	//void rebound(float angle, float elasticity);

	//	Constructors
	Collidable(Collision::Rectangle collisionRect);



};
/*
class Collidable {

private:

	//Polygon boundingPolygon;

public:

	//Polygon getBoundingPolygon();

	//	Setter
	//void setBoundingPolygon(Polygon boundingPolygonIn);

	//Vector2D preventOverlap(Collidable &other);
	//void rebound(float angle, float elasticity);
};*/

