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

public:

	int getFontWidth();
	int getFontHeight();
	std::string getText() { return text; }
	TTF_Font *getFont() { return font; }

	void setText(std::string text, SDL_Renderer *renderer);

	Label(std::string text, TTF_Font *font, SDL_Renderer * renderer, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255});

	///	Destructor
	~Label();

};