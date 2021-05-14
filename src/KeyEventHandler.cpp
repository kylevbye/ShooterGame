#include "KeyEventHandler.h"

void KeyEventHandler::handleDownInput(int key_sym) {

	switch (key_sym) {

		case SDLK_w:
			keyStates.W_DOWN = true;
			break;
		case SDLK_a:
			keyStates.A_DOWN = true;
			break;
		case SDLK_s:
			keyStates.S_DOWN = true;
			break;
		case SDLK_d:
			keyStates.D_DOWN = true;
			break;
		case SDLK_UP:
			keyStates.UP_DOWN = true;
			break;
		case SDLK_RIGHT:
			keyStates.RIGHT_DOWN = true;
			break;
		case SDLK_DOWN:
			keyStates.DOWN_DOWN = true;
			break;
		case SDLK_LEFT:
			keyStates.LEFT_DOWN = true;
			break;
		case SDLK_z:
			keyStates.Z_DOWN = true;
			break;
		case SDLK_x:
			keyStates.X_DOWN = true;
			break;

	}

}

void KeyEventHandler::handleUpInput(int key_sym) {
	
	switch (key_sym) {

		case SDLK_w:
			keyStates.W_DOWN = false;
			break;
		case SDLK_a:
			keyStates.A_DOWN = false;
			break;
		case SDLK_s:
			keyStates.S_DOWN = false;
			break;
		case SDLK_d:
			keyStates.D_DOWN = false;
			break;
		case SDLK_UP:
			keyStates.UP_DOWN = false;
			break;
		case SDLK_RIGHT:
			keyStates.RIGHT_DOWN = false;
			break;
		case SDLK_DOWN:
			keyStates.DOWN_DOWN = false;
			break;
		case SDLK_LEFT:
			keyStates.LEFT_DOWN = false;
			break;
		case SDLK_z:
			keyStates.Z_DOWN = false;
			break;
		case SDLK_x:
			keyStates.X_DOWN = false;
			break;

	}

}
