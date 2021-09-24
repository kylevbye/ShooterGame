#pragma once
#include "KeyEventHandler.h"
#include "ControllerEventHandler.h"

class ControlState {

	KeyEventHandler keyHandler;
	ControllerEventHandler controlHandler;

private:

	bool MOVE_UP = false;
	bool MOVE_LEFT = false;
	bool MOVE_DOWN = false;
	bool MOVE_RIGHT = false;

	bool MOVED_UP = false;
	bool MOVED_LEFT = false;
	bool MOVED_DOWN = false;
	bool MOVED_RIGHT = false;

	bool ACTION = false;
	bool CANCEL = false;

public:

	KeyEventHandler &getKeyHandler() {
		return keyHandler;
	}

	ControllerEventHandler &getControlHandler() {
		return controlHandler;
	}

	bool movingUp() const;
	bool movingLeft() const;
	bool movingDown() const;
	bool movingRight() const;

	bool movedUp() const;
	bool movedLeft() const;
	bool movedDown() const;
	bool movedRight() const;

	bool commitingAction() const;
	bool cancelingAction() const;

	void processInput();
	void reset();

};