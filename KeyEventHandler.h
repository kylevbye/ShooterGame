#pragma once
#include <SDL.h>


struct KeyStates {

	bool ESC_DOWN = false;

	/*
	 *	Active States
	 */
	//	Movement
	bool W_DOWN = false;
	bool A_DOWN = false;
	bool S_DOWN = false;
	bool D_DOWN = false;
	bool UP_DOWN = false;
	bool RIGHT_DOWN = false;
	bool DOWN_DOWN = false;
	bool LEFT_DOWN = false;
	//	Actions
	bool Z_DOWN = false;
	bool X_DOWN = false;

	/*
	 *	Handle States
	 */
	bool ESC_PRESSED = false;

	//	Movement
	bool W_PRESSED = false;
	bool A_PRESSED = false;
	bool S_PRESSED = false;
	bool D_PRESSED = false;
	bool UP_PRESSED = false;
	bool RIGHT_PRESSED = false;
	bool DOWN_PRESSED = false;
	bool LEFT_PRESSED = false;
	//	Actions
	bool Z_PRESSED = false;
	bool X_PRESSED = false;

};

class KeyEventHandler {

private:

	KeyStates keyStates;

public:

	const KeyStates &getKeyStates() { return keyStates; }

	void handleDownInput(int key_sym);

	void handleUpInput(int key_sym);

	void resetHandleStates();

};
