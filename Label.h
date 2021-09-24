#pragma once
#include <SDL_ttf.h>
#include "Entity.h"
#include "MobileEntity.h"
#include <string>

extern SDL_Renderer *asset_renderer;


///
///	Forward Declarations
///

class MobileEntity;

class Label : public MobileEntity {

private:

	std::string text;
	TTF_Font *font;

public:

	int getFontWidth();
	int getFontHeight();
	std::string getText() { return text; }
	TTF_Font *getFont() { return font; }

	///	Setters

	void setText(std::string text);

	///	Constructor

	Label(const char * filePath, std::string text = "", int fontSize = 12, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255});

	///	Destructor
	virtual ~Label();

private:

	void onUpdateTexture();

};