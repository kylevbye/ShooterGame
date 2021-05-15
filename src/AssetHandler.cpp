#include "AssetHandler.h"

void cleanupLevels(LevelHandler &levelHandler) {

	//	Delete
	delete levelHandler.titleLevel;
	delete levelHandler.mainMenuLevel;
	delete levelHandler.instructionLevel;

	//	Avoid DANGLING POINTERS!
	levelHandler.titleLevel = nullptr;
	levelHandler.mainMenuLevel = nullptr;
	levelHandler.instructionLevel = nullptr;

}