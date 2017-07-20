/*
 * Sound.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: Rossy
 */

#include "Sound.h"
#include <string>
#include <iostream>
using namespace std;

Sound::Sound() {
	init();
}

Sound::~Sound() {
close();
}

bool Sound::init() {

	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

		cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError()

		<< endl;

		success = false;

	} else {

		//Initialize SDL_mixer

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {

			cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n"

			<< endl << Mix_GetError();

			success = false;

		}

	}

	return success;
}

bool Sound::loadMedia(char* name) {
	bool success = true;

	MyMusic = Mix_LoadMUS(name);

	if (MyMusic == NULL) {

		cout << "Failed to load medium sound effect! SDL_mixer Error: %s"

		<< endl << Mix_GetError();

		success = false;

	}

	return success;

}

void Sound::Play() {
	Mix_PlayMusic(MyMusic, -1);
}

void Sound::Stop() {
	Mix_HaltMusic();
}

void Sound::close() {
	Mix_FreeMusic(MyMusic);

	MyMusic = NULL;
	SDL_Quit();
}
