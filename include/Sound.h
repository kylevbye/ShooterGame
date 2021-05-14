#pragma once
#include <SDL2/SDL_mixer.h>

class Sound {

private:

	Mix_Chunk *sound;
	int volume;

public:

	//	Getters
	Mix_Chunk *getSound() { return sound; }
	int getVolume() { return volume; }

	//	Setters
	void setVolume(int volume);

	void play();
	void play(int volume);

	//	Constructor
	Sound(Mix_Chunk *sound, int volume);

	//	Destructor
	~Sound();

};