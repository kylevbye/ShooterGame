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

void Label::setText(std::string text) {

	this->text = text;
	SDL_Surface *surface;
	SDL_Texture *newTexture;

	surface = TTF_RenderText_Solid(font, text.c_str(), color);
	newTexture = SDL_CreateTextureFromSurface(asset_renderer, surface);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	texture = newTexture;
	onUpdateTexture();

}

/*Label::Label(std::string text, TTF_Font *font, SDL_Renderer *renderer, float x, float y, SDL_Color color) 
	: Entity(x, y, nullptr), text(text), font(font) {

		SDL_Surface *tempSurface = TTF_RenderText_Solid(font, text.c_str(), color);

		setTexture(SDL_CreateTextureFromSurface(renderer,tempSurface));
		SDL_FreeSurface(tempSurface);

	}
*/

///
///	Constructors
///
Label::Label(const char * filePath, std::string text, int fontSize, float x, float y, SDL_Color color) 
	: MobileEntity(texture = nullptr, x, y, color), text(text), font(TTF_OpenFont(filePath, fontSize)) {

	SDL_Surface *tempSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture *tempTexture = SDL_CreateTextureFromSurface(asset_renderer, tempSurface);
	this->texture = tempTexture;
	SDL_FreeSurface(tempSurface);
	onUpdateTexture();

}

Label::~Label() {

	if (font) {
		TTF_CloseFont(font);
		font = nullptr;
	}

}

///
///	Helpers
///

void Label::onUpdateTexture() {
	//	Get Width and Height of texture
	//	SDL_Point.x --> width
	//	SDL_Point.y --> height
	SDL_Point textureSize;
	SDL_QueryTexture(texture, nullptr, nullptr, &textureSize.x, &textureSize.y);

	//	Upper left is 0,0 by default
	currentFrame.x = 0; currentFrame.y = 0;
	currentFrame.w = textureSize.x; 
	currentFrame.h = textureSize.y;
}