#pragma once
#include <SDL_mixer.h>

class Music {

private:

	Mix_Music *music;
	int volume;
	bool looping;
	bool played;

public:

	//	Getters
	Mix_Music *getMusic() { return music; }
	bool isPlayed() { return played; }
	int getVolume() { return volume; }

	//	Setters
	void setPlayed(bool playedFlag);
	void setVolume(int volume);

	void play();
	void play(int volume);
	void stop();

	Music(Mix_Music *music, bool looping = true);
	virtual ~Music();

};