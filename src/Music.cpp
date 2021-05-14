#include "Music.h"

void Music::setPlayed(bool playedFlag) {
	this->played = playedFlag;
}

void Music::setVolume(int volume) {
	this->volume = volume;
}

void Music::play() {
	Mix_VolumeMusic(volume);
	Mix_PlayMusic(music, -1*looping);
	setPlayed(true);
}

void Music::play(int volume) {
	setVolume(volume);
	play();
}

void Music::stop() {
	Mix_PauseMusic();
}

Music::Music(Mix_Music *music, bool looping) : music(music), looping(looping) {

}

Music::~Music() {
	Mix_FreeMusic(music);
	music = nullptr;
}