#include "Label.h"

int Label::getFontWidth() {

	int width = 0;
	int buffer;

	TTF_SizeText(font, text.c_str(), &width, &buffer);

	return width;

}

int Label::getFontHeight() {

	int height = 0;
	int buffer;

	TTF_SizeText(font, text.c_str(), &buffer, &height);

	return height;

}

void Label::setText(std::string text, SDL_Renderer *renderer) {

	this->text = text;
	SDL_Surface *surface;
	SDL_Texture *newTexture;

	surface = TTF_RenderText_Solid(font, text.c_str(), color);
	newTexture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	setTexture(newTexture);

}

Label::Label(std::string text, TTF_Font *font, SDL_Renderer *renderer, float x, float y, SDL_Color color) 
	: Entity(x, y, nullptr), text(text), font(font) {

		SDL_Surface *tempSurface = TTF_RenderText_Solid(font, text.c_str(), color);

		setTexture(SDL_CreateTextureFromSurface(renderer,tempSurface));
		SDL_FreeSurface(tempSurface);

	}

Label::~Label() {

	if (font) {
		TTF_CloseFont(font);
		font = nullptr;
	}

}