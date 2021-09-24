#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"

///
///	Forward Declarations
///
class Entity;

class Renderer {
public:
	virtual void render(SDL_Texture *texture) = 0;
	virtual void render(Entity &entity) = 0;

	virtual ~Renderer() {}
};