#pragma once
#include <SDL2/SDL_ttf.h>
#include "Entity.h"


///
///	Forward Declarations
///
class Entity;

class Label : public Entity {

private:

	std::string text;
	TTF_Font *font;
	SDL_Surface *surface;

public:

	int getFontWidth();
	int getFontHeight();
	std::string getText() { return text; }
	TTF_Font *getFont() { return font; }

	void render(SDL_Renderer *renderer);

	Label(float x, float y, std::string text, TTF_Font *font, SDL_Surface *surface, SDL_Texture *texture);

	///	Destructor
	~Label();

};