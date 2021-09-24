#pragma once
#include "CollidableEntity.h"
#include "CollisionShapes.h"
class Rectangle : public CollidableEntity {

private:

	float width;
	float height;
	float scaleW;
	float scaleH;

public:

	float getWidth();
	float getHeight();

	void setWidth(float width);
	void setHeight(float height);
	
	//	Constructors

	Rectangle(float width, float height, float x = 0.f, float y = 0.f, SDL_Color color = {255, 255, 255}, float maxSpeed = 1000.f, float decelerationValue = 0.f);

private:

	//	Helpers
	void onSizeChange();

};

