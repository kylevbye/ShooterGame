#include "Rectangle.h"

float Rectangle::getWidth() { return width; }

float Rectangle::getHeight() { return height; }

void Rectangle::setWidth(float width) { 
	this->width = width; 
	onSizeChange();
}
void Rectangle::setHeight(float height) { 
	this->height = height; 
	onSizeChange();
}

Rectangle::Rectangle(float width, float height, float x, float y, SDL_Color color, float maxSpeed, float decelerationValue) : CollidableEntity("res/img/rectangle.png", {}, x, y, color, maxSpeed, decelerationValue), width(width), height(height), scaleW(width/currentFrame.w), scaleH(height/currentFrame.h) {
	
	onSizeChange();

}

void Rectangle::onSizeChange() {
	collisionRect.width = width;
	collisionRect.height = height;
	scaleW = width/currentFrame.w;
	scaleH = height/currentFrame.h;
	setScaleX(scaleW);
	setScaleY(scaleH);
	SDL_Log("Y");
}
