#pragma once
#include <SDL2/SDL.h>


struct KeyStates {

	///	Movement
	bool W_DOWN = false;
	bool A_DOWN = false;
	bool S_DOWN = false;
	bool D_DOWN = false;

	bool UP_DOWN = false;
	bool RIGHT_DOWN = false;
	bool DOWN_DOWN = false;
	bool LEFT_DOWN = false;

	///	Actions
	bool Z_DOWN = false;
	bool X_DOWN = false;

};

class KeyEventHandler {

private:

	KeyStates keyStates;

public:

	const KeyStates &getKeyStates() { return keyStates; }

	void handleDownInput(int key_sym);

	void handleUpInput(int key_sym);





};
