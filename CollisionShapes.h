#pragma once
#include "Math.h"
#include <SDL.h>

using namespace Math;

extern SDL_Renderer *asset_renderer;

namespace Collision {

	/// <summary>
	/// Position is based on top left corner.
	/// </summary>
	struct Rectangle {

		float width;
		float height;
		Vector2D position;

		bool intersectsWith(Rectangle &other);
		void render();

		Rectangle(float width = 0.f, float height = 0.f, Vector2D position = {0.f, 0.f});

	};

	bool rectangleInterSectsRectangle(Rectangle &firstRect, Rectangle &secondRect);

	

}