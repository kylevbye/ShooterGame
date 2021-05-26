#include "BattleUI.h"

Vector2D &BattleUI::getPosition() {
	return position;
}

float BattleUI::getX() {
	return position.x;
}

float BattleUI::getY() {
	return position.y;
}

void BattleUI::setPosition(Vector2D position) {
	this->position = position;
}

void BattleUI::setX(float x) {
	this->position.x = x;
}

void BattleUI::setY(float y) {
	this->position.y = y;
}

void BattleUI::update(float dt) {

	positionButtons();
	fightButton.update(dt);
	actButton.update(dt);
	itemButton.update(dt);
	spareButton.update(dt);

}

void BattleUI::render() {
	
	if (fightButton.isActive()) fightButton.render(asset_renderer);
	if (actButton.isActive()) actButton.render(asset_renderer);
	if (itemButton.isActive()) itemButton.render(asset_renderer);
	if (spareButton.isActive()) spareButton.render(asset_renderer);

}

void BattleUI::select(Options option) {

	switch (option) {

		case Options::FIGHT:
			fightButton.setSelected(true);
			break;

		case Options::ACT:
			actButton.setSelected(true);
			break;

		case Options::ITEM:
			itemButton.setSelected(true);
			break;

		case Options::SPARE:
			spareButton.setSelected(true);
			break;

	}

}

void BattleUI::reset() {

	fightButton.setSelected(false);
	actButton.setSelected(false);
	itemButton.setSelected(false);
	spareButton.setSelected(false);

}

BattleUI::BattleUI(float width, float height, Vector2D position)
	: width(width), height(height), position(position), option(Options::NONE), fightButton("res/img/fight.png", "res/img/fight2.png"), actButton("res/img/act.png", "res/img/act2.png"), itemButton("res/img/item.png", "res/img/item2.png"), spareButton("res/img/mercy.png", "res/img/mercy2.png") {

	positionButtons();

}

BattleUI::~BattleUI() {
}

void BattleUI::positionButtons() {

	//	Calculate Width, Height and space
	float buttonWidth = width/5;
	float space = width/15;
	float scaleWidth = (width/5)/fightButton.getWidth();
	float scaleHeight = (height)/fightButton.getHeight();
	float spaceW = scaleWidth*fightButton.getWidth();

	//	Scale
	fightButton.setScaleX(scaleWidth);
	fightButton.setScaleY(scaleHeight);
	actButton.setScaleX(scaleWidth);
	actButton.setScaleY(scaleHeight);
	itemButton.setScaleX(scaleWidth);
	itemButton.setScaleY(scaleHeight);
	spareButton.setScaleX(scaleWidth);
	spareButton.setScaleY(scaleHeight);
	
	//	Position
	fightButton.setPosition(position.x, position.y);
	actButton.setPosition(fightButton.getX()+space+spaceW, position.y);
	itemButton.setPosition(actButton.getX()+space+spaceW, position.y);
	spareButton.setPosition(itemButton.getX()+space+spaceW, position.y);
	SDL_Log("{x: %f, y: %f, bW:%f w:%f, sW:%f, sH:%f, sS:%f}", position.x, position.y, buttonWidth, width, scaleWidth, scaleHeight, space);
	
}