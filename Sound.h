#pragma once
#include <SDL_mixer.h>

class Sound {

private:

	Mix_Chunk *sound;
	int volume;
	bool played;

public:

	//	Getters
	Mix_Chunk *getSound() { return sound; }
	int getVolume() { return volume; }
	bool isPlayed() { return played; }

	//	Setters
	void setVolume(int volume);
	void setPlayed(bool playedFlag);

	void play();
	void play(int volume);

	//	Constructor
	Sound(Mix_Chunk *sound, int volume);

	//	Destructor
	virtual ~Sound();

};