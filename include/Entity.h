#pragma once
#include "Math.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace Math;

extern SDL_Renderer *asset_renderer;

class Entity {

protected:

	SDL_Rect currentFrame;
	SDL_Texture *texture;

	Vector2D position;
	bool activeFlag;
	bool centeredFlag;
	Uint8 alpha;
	float scaleX, scaleY;
	float originX, originY;
	float angleDeg;
	SDL_RendererFlip flipSetting;
	SDL_Color color;

	//void setTexture(SDL_Texture *texture);

public:

	///	String Representation
	//std::string to_string();

	///	Getters

	bool isActive();
	bool isCentered();
	Vector2D &getPosition();
	float getX();
	float getY();
	Uint8 getAlpha();
	float getScaleX();
	float getScaleY();
	float getOriginX();
	float getOriginY();
	float getAngleDeg();
	SDL_Color &getColor();
	SDL_Rect &getCurrentFrame();
	SDL_Texture *getTexture();

	///	Setters

	void setX(float x);
	void setY(float y);
	void setPosition(float x, float y);
	void setActive(bool activeFlag);
	void setCentered(bool centeredFlag);
	void setAlpha(Uint8 alpha);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);
	void setScale(float scale);
	void setOriginX(float originX);
	void setOriginY(float originY);
	void setOrigin(float originX, float originY);
	void setAngleDeg(float angleDeg);
	void setColor(SDL_Color color);

	///	Funct

	void moveX(float dx) { position.x += dx; }
	void moveY(float dy) { position.y += dy; }
	void move(float dx, float dy) { moveX(dx); moveY(dy); }
	virtual void update(float dt);
	virtual void render(SDL_Renderer *renderer);

	//Entity(float x = 0.f, float y = 0.f, SDL_Texture *texture = nullptr, bool activeFlag = true, bool centeredFlag = true, Uint8 alpha = 255, float scaleX = 1.f, float scaleY = 1.f, float originX = 0.f, float originY = 0.f, float angleDeg = 0.f, SDL_RendererFlip flipSetting = SDL_FLIP_NONE, SDL_Color color = {255,255,255}, float maxSpeed = 1000000.f, float decelerationValue = 0.f);

	///	Constructors

public:

	Entity(const char *filePath, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255});

protected:

	Entity(SDL_Texture *texture, float x = 0.f, float y = 0.f, SDL_Color color = {255,255,255}); 

	//	Copy Constructor
	//Entity(const Entity &other);

	//	Move Constructor
	//Entity(Entity &&other); 

public:

	///	Destructor
	virtual ~Entity();

};