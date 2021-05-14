#include "PlayerController.h"

void PlayerController::applyKeyState(const KeyStates &keyStates) {

		float dx = 0.f; 
		float dy = 0.f;

		//	dx
		if (keyStates.D_DOWN || keyStates.RIGHT_DOWN) dx += 10.f;
		if (keyStates.A_DOWN || keyStates.LEFT_DOWN) dx -= 10.f;

		//	dy
		if (keyStates.W_DOWN || keyStates.UP_DOWN) dy -= 10.f;
		if (keyStates.S_DOWN || keyStates.DOWN_DOWN) dy += 10.f;

		controlEntity(dx, dy, false);
		
}

void PlayerController::applyPhysics(float dt) {

	if (entity) entity->applyPhysics(dt);

}

void PlayerController::update(float dt) {
	if (entity) entity->applyPhysics(dt);
}

void PlayerController::controlEntity(float dx, float dy, bool isVelocity = false) {

	//	If there's no Entity this instance is controlling
	//	Don't either bother doing anything.
	if (!entity) return;

	if (!isVelocity) {
		entity->setVelocity(dx, dy);
	} 

}

PlayerController::PlayerController() : entity(nullptr) {}

PlayerController::PlayerController(Entity *entity) 
	: entity(entity) {}

