#pragma once
#include "MobileEntity.h"

class BattleButton : public MobileEntity {

private:

	MobileEntity otherEntity;
	bool selected;

public:

	bool isSelected();

	void setSelected(bool selectedFlag);

	virtual void update(float dt);
	void render(SDL_Renderer *renderer);
	

	BattleButton(const char *filePath1, const char *filePath2, float x = 0.f, float y = 0.f, SDL_Color color = {255, 255, 255}, float maxSpeed = 1000.f, float decelerationValue = 0.f);

};
