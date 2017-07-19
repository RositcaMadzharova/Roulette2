#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using std::cerr;
using std::endl;

enum Seffect
{
	BUTTON,SPIN
	//buttons
};

enum Number
{
	ZERO,ONE,TWO,THREE,FOUR
	//numbers
};

class Sound
{
public:
	Sound();
	static bool load();
	static void pause();
	static bool playing();
	static void free();
	static void play(Seffect sound);
	static void music(Number number);
	~Sound();

private:
	static Uint32 timer;
	static Mix_Chunk* effect[2];
	static Mix_Music* num[5];
};


#endif
