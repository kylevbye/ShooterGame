#include "KeyEventHandler.h"

void KeyEventHandler::handleDownInput(int key_sym) {

	switch (key_sym) {

		case SDLK_w:
			keyStates.W_DOWN = true;
			keyStates.W_PRESSED = true;
			break;
		case SDLK_a:
			keyStates.A_DOWN = true;
			keyStates.A_PRESSED = true;
			break;
		case SDLK_s:
			keyStates.S_DOWN = true;
			keyStates.S_PRESSED = true;
			break;
		case SDLK_d:
			keyStates.D_DOWN = true;
			keyStates.D_PRESSED = true;
			break;
		case SDLK_UP:
			keyStates.UP_DOWN = true;
			keyStates.UP_PRESSED = true;
			break;
		case SDLK_RIGHT:
			keyStates.RIGHT_DOWN = true;
			keyStates.RIGHT_PRESSED = true;
			break;
		case SDLK_DOWN:
			keyStates.DOWN_DOWN = true;
			keyStates.DOWN_PRESSED = true;
			break;
		case SDLK_LEFT:
			keyStates.LEFT_DOWN = true;
			keyStates.LEFT_PRESSED = true;
			break;
		case SDLK_z:
			keyStates.Z_DOWN = true;
			keyStates.Z_PRESSED = true;
			break;
		case SDLK_x:
			keyStates.X_DOWN = true;
			keyStates.X_PRESSED = true;
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

void KeyEventHandler::resetHandleStates() {

	keyStates.W_PRESSED = false;
	keyStates.A_PRESSED = false;
	keyStates.S_PRESSED = false;
	keyStates.D_PRESSED = false;
	keyStates.UP_PRESSED = false;
	keyStates.RIGHT_PRESSED = false;
	keyStates.DOWN_PRESSED = false;
	keyStates.LEFT_PRESSED = false;
	keyStates.Z_PRESSED = false;
	keyStates.X_PRESSED = false;

}
