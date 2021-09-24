#include "CollisionShapes.h"
#include <typeinfo>

bool Collision::Rectangle::intersectsWith(Rectangle &other) {
	return rectangleInterSectsRectangle(*this, other);
}

void Collision::Rectangle::render() {

	float x = position.x;
	float y = position.y;
	SDL_Point points[5] = {{x, y}, {x+width, y}, {x+width, y+height}, {x, y+height}, {x, y}};
	SDL_Color oldColor;
	SDL_GetRenderDrawColor(asset_renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
	SDL_SetRenderDrawColor(asset_renderer, 255, 255, 0, 125);
	SDL_RenderDrawLines(asset_renderer, points, 5 );
	SDL_SetRenderDrawColor(asset_renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);

}

Collision::Rectangle::Rectangle(float width, float height, Vector2D position)
	: width(width), height(height), position(position) {
}

bool Collision::rectangleInterSectsRectangle(Rectangle &firstRect, Rectangle &secondRect) {

	return firstRect.position.x < (secondRect.position.x+secondRect.width)&&firstRect.position.x+firstRect.width > secondRect.position.x&&firstRect.position.y < secondRect.position.y+secondRect.height&&firstRect.position.y+firstRect.height > secondRect.position.y;

}