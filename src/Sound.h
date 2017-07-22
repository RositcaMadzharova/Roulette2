#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using std::cerr;
using std::endl;

enum EFFECT
{
	CLICKBUTTON,SPINROULETTE,HEART
};

enum NUMBER
{
	N0,N1,N2,N3
};

class Sound
{
public:
	Sound();
	static bool load();
	static void pause();
	static bool playing();
	static void free();
	static void play(EFFECT sound);
	static void music(NUMBER number);
	~Sound();

private:
	static Mix_Chunk* effect[25];
	static Mix_Music* num[10];
};


#endif
