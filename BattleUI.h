#pragma once
#include "SDL.h"
#include "MobileEntity.h"
#include "BattleButton.h"

extern SDL_Renderer *asset_renderer;

class BattleUI {

public:

	enum class Options : int { NONE, FIGHT, ACT, ITEM, SPARE };

private:

	float width;
	float height;
	Vector2D position;
	Options option;
	BattleButton fightButton;
	BattleButton actButton;
	BattleButton itemButton;
	BattleButton spareButton;


public:

	//	Getters
	Vector2D &getPosition();
	float getX();
	float getY();

	//	Setters
	void setPosition(Vector2D position);
	void setX(float x);
	void setY(float y);

	//	Functions
	void update(float dt);
	void render();
	void select(Options option);
	void reset();

	//	Constructors
	BattleUI(float width = 0.f, float height = 0.f, Vector2D position = {});

	//	Destructor
	~BattleUI();

private:

	//	Helpers
	void positionButtons();

};
