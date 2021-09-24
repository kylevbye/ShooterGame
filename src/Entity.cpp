#include "Entity.h"

/*std::string Entity::to_string() {

	char buffer[900];

	char bufferB[70];
	snprintf(bufferB, sizeof(bufferB), "X: %d, Y:%d, W:%d, H:%d", currentFrame.x, currentFrame.y, currentFrame.w, currentFrame.h);

	//	Set up format
	const char *format_str = "Entity::[currentFrame = [%s]; texture = [%p]; activeFlag = [%d]; scaleX = [%f]; scaleY = [%f]; originX = [%f]; originY = [%f]; angleDeg = [%f]; flipSetting = [%d]; positionVector = %s; velocityVector = %s; accelerationVector = %s; maxSpeed=[%f]; decelerationValue = [%f]]";

	//	Format all values of this Entity instance.
	snprintf(buffer, sizeof(buffer), format_str, bufferB, texture, activeFlag, scaleX, scaleY, originX, originY, angleDeg, "flipSetting", positionVector.toCStr(), velocityVector.toCStr(), accelerationVector.toCStr(), maxSpeed, decelerationValue);


	return buffer;

}*/

///
///	Getters
///

bool Entity::isActive() { return activeFlag; }
bool Entity::isCentered() { return centeredFlag; }
Vector2D &Entity::getPosition() { return position; }
float Entity::getX() { return position.x; }
float Entity::getY() { return position.y; }
Uint8 Entity::getAlpha() { return alpha; }
float Entity::getScaleX() { return scaleX; }
float Entity::getScaleY() { return scaleY; }
float Entity::getOriginX() { return originX; }
float Entity::getOriginY() { return originY; }
float Entity::getAngleDeg() { return angleDeg; }
SDL_Color &Entity::getColor() { return color; }
SDL_Rect &Entity::getCurrentFrame() { return currentFrame; }
SDL_Texture *Entity::getTexture() { return texture; }

///
///	Setters
///

void Entity::setX(float x) {
	this->position.x = x;
}

void Entity::setY(float y) {
	this->position.y = y;
}

void Entity::setPosition(float x, float y) {
	setX(x); setY(y);
}

void Entity::setActive(bool activeFlag) {
	this->activeFlag = activeFlag;
}

void Entity::setCentered(bool centeredFlag) {
	this->centeredFlag = centeredFlag;
}

void Entity::setAlpha(Uint8 alpha) {
	this->alpha = alpha;
}

void Entity::setScaleX(float scaleX) { 
	this->scaleX = scaleX; 
}

void Entity::setScaleY(float scaleY) { 
	this->scaleY = scaleY; 
}

void Entity::setScale(float scale) {
	setScaleX(scale); setScaleY(scale);
}

void Entity::setOriginX(float originX) { 
	this->originX = originX; 
}

void Entity::setOriginY(float originY) { 
	this->originY = originY; 
}

void Entity::setOrigin(float originX, float originY) {
	setOriginX(originX); setOriginY(originY);
}

void Entity::setAngleDeg(float angleDeg) { 
	this->angleDeg = angleDeg; 
}

void Entity::setColor(SDL_Color color) {
	this->color = color;
}


///
///	Functions
///

void Entity::update(float dt) {}

void Entity::render(SDL_Renderer *renderer) {

	if (!activeFlag) return;

	SDL_Rect source;
	source.x = currentFrame.x; 
	source.y = currentFrame.y;
	source.w = currentFrame.w; 
	source.h = currentFrame.h;

	///	Apply Scaling
	SDL_Rect destination;
	destination.x = position.x; 
	destination.y = position.y;
	destination.w = currentFrame.w * scaleX; 
	destination.h = currentFrame.h * scaleY;

	//	Center if Neccesary
	if (centeredFlag) {
		destination.x -= destination.w/2.f;
		destination.y -= destination.h/2.f;
	}

	///	Rotation
	SDL_Point origin;
	origin.x = originX * scaleX;
	origin.y = originY * scaleY;

	///	Render Time
	SDL_SetTextureAlphaMod(texture, alpha);
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
	//SDL_RenderCopy(renderer, texture, &source, &destination);
	SDL_RenderCopyEx(renderer, texture, &source, &destination, angleDeg, &origin, flipSetting);

}

/*Entity::Entity(float x, float y, SDL_Texture *texture, bool activeFlag, bool centeredFlag, Uint8 alpha, float scaleX, float scaleY, float originX, float originY, float angleDeg, SDL_RendererFlip flipSetting, SDL_Color color, float maxSpeed, float decelerationValue)
	: texture(nullptr), activeFlag(activeFlag), centeredFlag(centeredFlag), alpha(alpha), scaleX(scaleX), scaleY(scaleY), originX(originX), originY(originY), angleDeg(angleDeg), flipSetting(flipSetting), color(color), positionVector(x,y), velocityVector(0.f, 0.f), accelerationVector(0.f, 0.f), maxSpeed(maxSpeed), decelerationValue(decelerationValue) {

	setTexture(texture);

}*/

///
///	Constructors
///

Entity::Entity(const char *filePath, float x, float y, SDL_Color color) : texture(nullptr), position(x,y), activeFlag(true), centeredFlag(false), alpha(255), scaleX(1.f), scaleY(1.f), originX(0.f), originY(0.f), angleDeg(0.f), flipSetting(SDL_FLIP_NONE), color(color) {

	SDL_Texture *tempTexture = IMG_LoadTexture(asset_renderer, filePath);

	//	Log if texture fails to load.
	if (!tempTexture) {
		SDL_Log("Unable to init load texture at {%s}: %s", filePath, SDL_GetError());
	}

	this->texture = tempTexture;

	if (texture) {
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

}

Entity::Entity(SDL_Texture *texture, float x, float y, SDL_Color color) 
	: texture(texture), position(x,y), activeFlag(true), centeredFlag(false), alpha(255), scaleX(1.f), scaleY(1.f), originX(0.f), originY(0.f), angleDeg(0.f), flipSetting(SDL_FLIP_NONE), color(color) {

	if (texture) {
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

}

/*Entity::Entity(const Entity &other)
	: currentFrame(other.currentFrame), texture(nullptr),
	centeredFlag(other.centeredFlag), alpha(other.alpha), 
	scaleX(other.scaleX), scaleY(other.scaleY), originX(other.originX), originY(other.originY), angleDeg(other.angleDeg), flipSetting(other.flipSetting), color(other.color), positionVector(other.positionVector), velocityVector(other.velocityVector), accelerationVector(other.accelerationVector), maxSpeed(other.maxSpeed), decelerationValue(other.decelerationValue) {

	texture = other.texture;

}

Entity::Entity(Entity &&other) {

}
*/

Entity::~Entity() {

	if (texture) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

