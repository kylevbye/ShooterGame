#include "Sound.h"

void Sound::setVolume(int volume) {
	this->volume = volume;
}

void Sound::setPlayed(bool playedFlag) {
	this->played = playedFlag;
}

void Sound::play() {
	played = true;
	Mix_VolumeChunk(sound, volume);
	Mix_PlayChannel(-1, sound, 0);
}

void Sound::play(int volume) {
	setVolume(volume);
	play();
}

Sound::Sound(Mix_Chunk *sound, int volume = 64) : sound(sound), volume(volume), played(false) {

}

Sound::~Sound() {
	Mix_FreeChunk(sound);
	sound = nullptr;
}