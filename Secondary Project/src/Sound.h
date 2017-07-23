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
	N0,N1,N2,N3,N4,N5,N6,N7,N8,N9,N10,N11,
	N12,N13,N14,N15,N16,N17,N18,N19,N20,N21,
	N22,N23,N24,N25,N26,N27,N28,N29,N30,N31,
	N32,N33,N34,N35,N36,WINNUM
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
	static Mix_Chunk* effect[3];
	static Mix_Music* num[38];
};


#endif
