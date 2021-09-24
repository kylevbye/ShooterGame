#include "ControllerEventHandler.h"

const ControllerStates &ControllerEventHandler::getControllerStates() {
	return controllerStates;
}

void ControllerEventHandler::handleJoyInput(SDL_ControllerAxisEvent event) {

	//	X Axis
	if (event.axis==SDL_CONTROLLER_AXIS_LEFTX) {

		//	Left 
		if (event.value<-stickDeadZone) {
			controllerStates.LEFT_STICK_X_AXIS = -1;
			if (!controllerStates.LEFT_STICK_FIRST_LEFT) {
				controllerStates.LEFT_STICK_MOVED_LEFT = true;
				controllerStates.LEFT_STICK_FIRST_LEFT = true;
			}
		}
		//	Right
		else if (event.value>stickDeadZone ) {
			controllerStates.LEFT_STICK_X_AXIS = 1;
			if (!controllerStates.LEFT_STICK_FIRST_RIGHT) {
				controllerStates.LEFT_STICK_MOVED_RIGHT = true;
				controllerStates.LEFT_STICK_FIRST_RIGHT = true;
			}
		}
		//	In Deadzone
		else {
			controllerStates.LEFT_STICK_FIRST_LEFT = false;
			controllerStates.LEFT_STICK_FIRST_RIGHT = false;
			controllerStates.LEFT_STICK_X_AXIS = 0;
		}

	}
	//	Y Axis
	else if (event.axis==SDL_CONTROLLER_AXIS_LEFTY) {

		//	UP
		if (event.value<-stickDeadZone) {
			controllerStates.LEFT_STICK_Y_AXIS = 1;
			if (!controllerStates.LEFT_STICK_FIRST_UP) {
				controllerStates.LEFT_STICK_MOVED_UP = true;
				controllerStates.LEFT_STICK_FIRST_UP = true;
			}

		}
		//	DOWN
		else if (event.value>stickDeadZone) {
			controllerStates.LEFT_STICK_Y_AXIS = -1;
			if (!controllerStates.LEFT_STICK_FIRST_DOWN) {
				controllerStates.LEFT_STICK_MOVED_DOWN = true;
				controllerStates.LEFT_STICK_FIRST_DOWN = true;
			}
		}
		//	In Deadzone
		else {
			controllerStates.LEFT_STICK_FIRST_DOWN = false;
			controllerStates.LEFT_STICK_FIRST_UP = false;
			controllerStates.LEFT_STICK_Y_AXIS = 0;
		}

	}

}

void ControllerEventHandler::handleDownInput(SDL_ControllerButtonEvent event) {

	switch (event.button) {

		case SDL_CONTROLLER_BUTTON_A:
			controllerStates.A_DOWN = true;
			controllerStates.A_PRESSED = true;
			break;

		case SDL_CONTROLLER_BUTTON_B:
			controllerStates.B_DOWN = true;
			controllerStates.B_PRESSED = true;
			break;

	}

}

void ControllerEventHandler::handleUpInput(SDL_ControllerButtonEvent event) {

	switch (event.button) {

		case SDL_CONTROLLER_BUTTON_A:
			controllerStates.A_DOWN = false;
			break;

		case SDL_CONTROLLER_BUTTON_B:
			controllerStates.B_DOWN = false;
			break;

	}

}

void ControllerEventHandler::resetHandleStates() {

	controllerStates.A_PRESSED = false;
	controllerStates.B_PRESSED = false;

	controllerStates.LEFT_STICK_MOVED_UP = false;
	controllerStates.LEFT_STICK_MOVED_LEFT = false;
	controllerStates.LEFT_STICK_MOVED_DOWN = false;
	controllerStates.LEFT_STICK_MOVED_RIGHT = false;

	controllerStates.RIGHT_STICK_MOVED_UP = false;
	controllerStates.RIGHT_STICK_MOVED_LEFT = false;
	controllerStates.RIGHT_STICK_MOVED_DOWN = false;
	controllerStates.RIGHT_STICK_MOVED_RIGHT = false;

}

ControllerEventHandler::ControllerEventHandler()
	: stickDeadZone(8000), controller(nullptr), controllerStates() {

	if (SDL_NumJoysticks()>=1) {
		SDL_Log("CONTROLLER DETECTED!");
		if (SDL_IsGameController(0)) {
			controller = SDL_GameControllerOpen(0);
			if (controller) {
				SDL_Log("%s CONTROLLER OPENED!", SDL_GameControllerNameForIndex(0));
			}
			else SDL_Log("Unable to open controller. %s", SDL_GetError());
		}
		else SDL_Log("Controller @%d is not supported", 0);
	}
	else SDL_Log("NO CONTROLLER DETECTED!");

}

ControllerEventHandler::~ControllerEventHandler() {

	//	Close Controller
	SDL_GameControllerClose(controller);
	controller = nullptr;

}
