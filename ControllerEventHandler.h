#pragma once
#include <SDL.h>

struct ControllerStates {

	//	For In-Game Movement
	// val = -1 --> Stick Moved Left
	// val = 1  --> Stick Moved Right
	// val = 0  --> Stick in Deadzone/Center.
	int LEFT_STICK_X_AXIS = 0;
	int LEFT_STICK_Y_AXIS = 0;
	int RIGHT_STICK_X_AXIS = 0;
	int RIGHT_STICK_Y_AXIS = 0;
	float leftStickAngle = 0;

	// For Menus
	bool LEFT_STICK_MOVED_UP = false;
	bool LEFT_STICK_MOVED_LEFT = false;
	bool LEFT_STICK_MOVED_DOWN = false;
	bool LEFT_STICK_MOVED_RIGHT = false;
	bool LEFT_STICK_FIRST_UP = false;
	bool LEFT_STICK_FIRST_LEFT = false;
	bool LEFT_STICK_FIRST_DOWN = false;
	bool LEFT_STICK_FIRST_RIGHT = false;

	bool RIGHT_STICK_MOVED_UP = false;
	bool RIGHT_STICK_MOVED_LEFT = false;
	bool RIGHT_STICK_MOVED_DOWN = false;
	bool RIGHT_STICK_MOVED_RIGHT = false;

	//	???
	bool A_DOWN = false;
	bool B_DOWN = false;

	//	For Menu Interaction
	bool A_PRESSED = false;
	bool B_PRESSED = false;

};

class ControllerEventHandler {
	
private:

	int stickDeadZone;
	SDL_GameController *controller;
	ControllerStates controllerStates;

public:

	const ControllerStates &getControllerStates();

	void handleJoyInput(SDL_ControllerAxisEvent event);
	void handleDownInput(SDL_ControllerButtonEvent event);
	void handleUpInput(SDL_ControllerButtonEvent event);

	void resetHandleStates();

	ControllerEventHandler();
	~ControllerEventHandler();


};

