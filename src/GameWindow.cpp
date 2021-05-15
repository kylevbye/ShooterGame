#include "GameWindow.h"

///
///	Functions
///

SDL_Texture *GameWindow::loadTexture(const char *filePath) {
	
	SDL_Texture *returnTexture = nullptr;
	returnTexture = IMG_LoadTexture(renderer, filePath);

	//	Log if texture fails to load.
	if (!returnTexture) {
		SDL_Log("Unable to init load texture at {%s}: %s", filePath, SDL_GetError());
	}

	return returnTexture;

}

void GameWindow::clear() {

	SDL_RenderClear(renderer);

}

void GameWindow::render(SDL_Texture *texture) {

	SDL_RenderCopy(renderer, texture, nullptr, nullptr);

}

void GameWindow::render(Entity &entity) {

	SDL_Rect source;
	source.x = entity.getCurrentFrame().x; 
	source.y = entity.getCurrentFrame().y;
	source.w = entity.getCurrentFrame().w; 
	source.h = entity.getCurrentFrame().h;


	SDL_Rect destination;
	destination.x = entity.getX(); 
	destination.y = entity.getY();
	destination.w = entity.getCurrentFrame().w; 
	destination.h = entity.getCurrentFrame().h;

	SDL_RenderCopy(renderer, entity.getTexture(), &source, &destination);

}

void GameWindow::display() {

	SDL_RenderPresent(renderer);

}

void GameWindow::toggleFullScreen() {

	SDL_SetWindowFullscreen(window,
                             isFullScreen);

	isFullScreen = !isFullScreen;
}

///
///	Constructors
///

GameWindow::GameWindow(const char *title, int width, int height) 
	: width(width), height(height), isFullScreen(false), window(nullptr), renderer(nullptr), windowIcon(nullptr) {

	//	Create a resizable SDL Window w/ unknown coords
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		width, height, SDL_WINDOW_RESIZABLE);

	//	Log if window failed to create.
	if (!window) {
		SDL_Log("Unable to init SDL_Window: %s", SDL_GetError());
	}

	//	Create a renderer that prioritizes the GPU
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, width, height);

	//	Set the window icon (use CPU for creating)
	windowIcon = IMG_Load("res/img/asgoreLookDown.png");
	SDL_SetWindowIcon(window, windowIcon);

}

///
///	Destructor
///

GameWindow::~GameWindow() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(windowIcon);

	window = nullptr;
	renderer = nullptr;
	windowIcon = nullptr;
}
