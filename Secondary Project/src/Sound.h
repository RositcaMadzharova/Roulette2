/*
 * Sound.h
 *
 *  Created on: Jul 24, 2017
 *      Author: kakev
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using std::cerr;
using std::endl;

enum EFFECT
{
	CLICKBUTTON,SPINROULETTE,HEART,WINING_NUMBER
};

class Sound
{
public:
	Sound();
	 bool load();
	 void pause();
	 bool playing();
	 void free();
	 void play(EFFECT sound);
	 void music(int number);
	~Sound();

private:
	 Mix_Chunk* effect[4];
	 Mix_Chunk* num[36];
};


#endif /* SOUND_H_ */
