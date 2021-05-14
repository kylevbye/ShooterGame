#pragma once
#include "Entity.h"
#include "KeyEventHandler.h"


///
///	Forward Declarations
///
class Entity;
class KeyEventHandler;

class PlayerController {

private:

	Entity *entity;


public: 

	///	Setters
	void setEntity(Entity *entity) { this->entity = entity; }

	void applyKeyState(const KeyStates &keyStates);
	void applyPhysics(float dt);
	void update(float dt);
	void controlEntity(float dx, float dy, bool isVelocity);

	///	Constructors
	PlayerController();
	PlayerController(Entity *entity);
};