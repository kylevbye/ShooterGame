#include "Game/Stage.h"

using namespace Game;

void Stage::setActive(bool activeFlag) { 
	this->activeFlag = activeFlag; 
}


std::string Stage::to_string() {

	std::string returnString = "[";

	//	Process screenObjects
	if (!screenObjects.empty()) {

		std::string sO_list_str = "screenObjects = {";

		#pragma GCC diagnostic push
		#pragma GCC diagnostic ignored "-Wsign-compare"

		for (int i = 0; i<screenObjects.size(); ++i) {
			//	Make sure NULL objects are marked appropriately.
			if (screenObjects[i]) {
				sO_list_str += screenObjects[i]->to_string();
			}
			else sO_list_str += "NULL";
			//	If there's another object to process, add a comma.
			if (i != screenObjects.size()-1) sO_list_str += ", ";
		}

		#pragma GCC diagnostic pop

		//	Done Processing
		sO_list_str += "}";
		returnString += sO_list_str;

	}

	returnString += "]";

	return returnString;
}

void Stage::addScreenObject(Entity *screenObject) {
	//	Avoid adding duplicate screen object.
	if (findIndexOfScreenObject(screenObject) == -1) {
		screenObjects.push_back(screenObject);
	}
}

void Stage::removeScreenObject(Entity *screenObject) {
	int index = findIndexOfScreenObject(screenObject);
	if (index != -1) screenObjects.erase(screenObjects.begin() +index);
}

void Stage::update(float dt) {
	for (Entity *screenObject : screenObjects) {
		screenObject->update(dt);
	}
}

void Stage::render(SDL_Renderer *renderer) {
	cleanUp();
	for (Entity *screenObject : screenObjects) {
		screenObject->render(renderer);
	}
}

Stage::Stage() : activeFlag(true) {}

Stage::~Stage() {

	//	Clean Up screenObjects
	for (Entity *entity : screenObjects) {

		if (entity) {
			delete entity;
			entity = nullptr;
		}

	}
}

int Stage::findIndexOfScreenObject(Entity *screenObject) {
	int index = -1;

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wsign-compare"

	for (int i = 0; i<screenObjects.size(); ++i) {
		if (screenObject == screenObjects[i]) {
			index = i;
			break;
		}
	}

	#pragma GCC diagnostic pop

	return index;
}

void Stage::cleanUp() {
	for (Entity *screenObject : screenObjects) {
		if (!screenObject) removeScreenObject(screenObject);
	}
}