/*
 * Sound.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: kakev
 */

#include "Sound.h"

Sound::Sound()
{
	bool done = load();
	if (!done)
		cerr << "Sound loading failed" << endl;
}

void Sound::free()
{
	for (int i = 0; i < SPECIAL_SOUNDS; i++)
	{
		Mix_FreeChunk(effect[i]);
		effect[i] = NULL;
	}

	for (int i = 0; i < NUMBER_SOUNDS; i++)
	{
		Mix_FreeChunk(num[i]);
		num[i] = NULL;
	}

	Mix_Quit();
}

void Sound::play(EFFECT sound)
{
	switch (sound)
	{
	case CLICKBUTTON:
		Mix_PlayChannel(-1, effect[0], 0);
		break;
	case SPINROULETTE:
		Mix_PlayChannel(-1, effect[1], 0);
		break;
	case WIN:
		Mix_PlayChannel(-1, effect[2], 0);
		break;
	case WINING_NUMBER:
		Mix_PlayChannel(-1, effect[3], 0);
		break;
	case WINSCREEN:
		Mix_PlayChannel(-1, effect[4], 0);
		break;
	}
}

void Sound::music(int number)
{
	Mix_PlayChannel(-1, num[number], 0);
}

Sound::~Sound()
{
	free();
}

bool Sound::load()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		cerr << "SDL Audio error: " << SDL_GetError() << endl;
		success = false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cerr << "Audio error: " << Mix_GetError() << endl;
		success = false;
	}

	effect[0] = Mix_LoadWAV("button.wav");
	effect[1] = Mix_LoadWAV("Wheel Spinning.mp3");
	effect[2] = Mix_LoadWAV("You win.mp3");
	effect[3] = Mix_LoadWAV("the-winning-number-is.wav");
	effect[4] = Mix_LoadWAV("Winning Sound.mp3");

	num[0] = Mix_LoadWAV("0.wav");
	num[1] = Mix_LoadWAV("1.wav");
	num[2] = Mix_LoadWAV("2.wav");
	num[3] = Mix_LoadWAV("3.wav");
	num[4] = Mix_LoadWAV("4.wav");
	num[5] = Mix_LoadWAV("5.wav");
	num[6] = Mix_LoadWAV("6.wav");
	num[7] = Mix_LoadWAV("7.wav");
	num[8] = Mix_LoadWAV("8.wav");
	num[9] = Mix_LoadWAV("9.wav");
	num[10] = Mix_LoadWAV("10.wav");
	num[11] = Mix_LoadWAV("11.wav");
	num[12] = Mix_LoadWAV("12.wav");
	num[13] = Mix_LoadWAV("13.wav");
	num[14] = Mix_LoadWAV("14.wav");
	num[15] = Mix_LoadWAV("15.wav");
	num[16] = Mix_LoadWAV("16.wav");
	num[17] = Mix_LoadWAV("17.wav");
	num[18] = Mix_LoadWAV("18.wav");
	num[19] = Mix_LoadWAV("19.wav");
	num[20] = Mix_LoadWAV("20.wav");
	num[21] = Mix_LoadWAV("21.wav");
	num[22] = Mix_LoadWAV("22.wav");
	num[23] = Mix_LoadWAV("23.wav");
	num[24] = Mix_LoadWAV("24.wav");
	num[25] = Mix_LoadWAV("25.wav");
	num[26] = Mix_LoadWAV("26.wav");
	num[27] = Mix_LoadWAV("27.wav");
	num[28] = Mix_LoadWAV("28.wav");
	num[29] = Mix_LoadWAV("29.wav");
	num[30] = Mix_LoadWAV("30.wav");
	num[31] = Mix_LoadWAV("31.wav");
	num[32] = Mix_LoadWAV("32.wav");
	num[33] = Mix_LoadWAV("33.wav");
	num[34] = Mix_LoadWAV("34.wav");
	num[35] = Mix_LoadWAV("35.wav");
	num[36] = Mix_LoadWAV("36.wav");

	for (int i = 0; i < 3; ++i)
	{
		if (effect[i] == NULL)
		{
			cerr << "EFFECT error: " << Mix_GetError() << endl;
			success = false;
		}
	}

	for (int i = 0; i < 37; ++i)
	{
		if (num[i] == NULL)
		{
			cerr << "NUMBER error: " << Mix_GetError() << endl;
			success = false;
		}
	}
	return success;
}
