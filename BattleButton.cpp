#include "BattleButton.h"

bool BattleButton::isSelected() {
	return selected;
}

void BattleButton::setSelected(bool selectedFlag) {
	this->selected = selectedFlag;
}

void BattleButton::update(float dt) {

	MobileEntity::update(dt);
	otherEntity.setPosition(position.x, position.y);
	otherEntity.setActive(activeFlag);
	otherEntity.setCentered(centeredFlag);
	otherEntity.setAlpha(alpha);
	otherEntity.setScaleX(scaleX);
	otherEntity.setScaleY(scaleY);
	otherEntity.setOrigin(originX, originY);
	otherEntity.setAngleDeg(angleDeg);
	otherEntity.setFlipSetting(flipSetting);
	otherEntity.setColor(color);
	otherEntity.setVelocity(velocity.x, velocity.y);
	otherEntity.setAcceleration(acceleration.x, acceleration.y);

}

void BattleButton::render(SDL_Renderer *renderer) {

	if (selected) otherEntity.render(renderer);
	else MobileEntity::render(renderer);

}

BattleButton::BattleButton(const char *filePath1, const char *filePath2, float x, float y, SDL_Color color, float maxSpeed, float decelerationValue)
	: MobileEntity(filePath1, x, y, color, maxSpeed, decelerationValue), otherEntity(filePath2, x, y, color, maxSpeed, decelerationValue), selected(false) {}



