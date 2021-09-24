#include "ControlState.h"

bool ControlState::movingUp() const {
    return MOVE_UP;
}

bool ControlState::movingLeft() const {
    return MOVE_LEFT;
}

bool ControlState::movingDown() const {
    return MOVE_DOWN;
}

bool ControlState::movingRight() const {
    return MOVE_RIGHT;
}

bool ControlState::movedUp() const {
    return MOVED_UP;
}

bool ControlState::movedLeft() const {
    return MOVED_LEFT;
}

bool ControlState::movedDown() const {
    return MOVED_DOWN;
}

bool ControlState::movedRight() const {
    return MOVED_RIGHT;
}

bool ControlState::commitingAction() const {
    return ACTION;
}

bool ControlState::cancelingAction() const {
    return CANCEL;
}

void ControlState::processInput() {

    //  MOVE_UP
    if (keyHandler.getKeyStates().W_DOWN||keyHandler.getKeyStates().UP_DOWN||controlHandler.getControllerStates().LEFT_STICK_Y_AXIS == 1) {
        MOVE_UP = true;
    }

    //  MOVE_LEFT
    if (keyHandler.getKeyStates().A_DOWN||keyHandler.getKeyStates().LEFT_DOWN||controlHandler.getControllerStates().LEFT_STICK_X_AXIS == -1) {
        MOVE_LEFT = true;
    }

    //  MOVE_DOWN
    if (keyHandler.getKeyStates().S_DOWN||keyHandler.getKeyStates().DOWN_DOWN||controlHandler.getControllerStates().LEFT_STICK_Y_AXIS==-1) {
        MOVE_DOWN = true;
    }

    //  MOVE_RIGHT
    if (keyHandler.getKeyStates().D_DOWN||keyHandler.getKeyStates().RIGHT_DOWN||controlHandler.getControllerStates().LEFT_STICK_X_AXIS==1) {
        MOVE_RIGHT = true;
    }

    //  MOVED_UP
    if (keyHandler.getKeyStates().W_PRESSED||keyHandler.getKeyStates().UP_PRESSED||controlHandler.getControllerStates().LEFT_STICK_MOVED_UP) {
        MOVED_UP = true;
    }

    //  MOVED_LEFT
    if (keyHandler.getKeyStates().A_PRESSED||keyHandler.getKeyStates().LEFT_PRESSED||controlHandler.getControllerStates().LEFT_STICK_MOVED_LEFT) {
        MOVED_LEFT = true;
    }

    //  MOVED_UP
    if (keyHandler.getKeyStates().S_PRESSED||keyHandler.getKeyStates().DOWN_PRESSED||controlHandler.getControllerStates().LEFT_STICK_MOVED_DOWN) {
        MOVED_DOWN = true;
    }

    //  MOVED_RIGHT
    if (keyHandler.getKeyStates().D_PRESSED||keyHandler.getKeyStates().RIGHT_PRESSED||controlHandler.getControllerStates().LEFT_STICK_MOVED_RIGHT) {
        MOVED_RIGHT = true;
    }

    //  ACTION
    if (keyHandler.getKeyStates().Z_PRESSED||controlHandler.getControllerStates().A_PRESSED) {
        ACTION = true; 
    }

    //  CANCEL
    if (keyHandler.getKeyStates().X_PRESSED||controlHandler.getControllerStates().B_PRESSED) {
        CANCEL = true;
    }

}

void ControlState::reset() {

    MOVE_UP = false;
    MOVE_LEFT = false;
    MOVE_DOWN = false;
    MOVE_RIGHT = false;
    MOVED_UP = false;
    MOVED_LEFT = false;
    MOVED_DOWN = false;
    MOVED_RIGHT = false;
    ACTION = false;
    CANCEL = false;

    keyHandler.resetHandleStates();
    controlHandler.resetHandleStates();

}
