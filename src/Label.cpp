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

void Label::render(SDL_Renderer *renderer) {
	Entity::render(renderer);
}

Label::Label(float x, float y, std::string text, TTF_Font *font, SDL_Surface *surface, SDL_Texture *texture) 
	: Entity(x, y, texture), text(text), font(font), surface(surface) {}

Label::~Label() {

	if (font) {
		TTF_CloseFont(font);
		font = nullptr;

	}

	if (surface) {
		SDL_FreeSurface(surface);
		surface = nullptr;
	}

}