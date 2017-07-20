/*
 * Sound.h
 *
 *  Created on: Jul 20, 2017
 *      Author: Rossy
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using namespace std;
class Sound {
public:
	Sound();

	void Play();
	void Stop();

	bool init();
	bool loadMedia(char*);
	void close();
	virtual ~Sound();

private:
	Mix_Music *MyMusic = NULL;

};

#endif /* SOUND_H_ */
