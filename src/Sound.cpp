#include "Sound.h"

Uint32 Sound::timer;
Mix_Chunk* Sound::effect[];
Mix_Music* Sound::num[];

Sound::Sound() 
{
}

void Sound::free() 
{
	for (int i = 0; i < 25; i++) {
		Mix_FreeChunk(effect[i]);
		effect[i] = NULL;
	}

	for (int i = 0; i < 10; i++) {
		Mix_FreeMusic(num[i]);
		num[i] = NULL;
	}

	Mix_Quit();	
}

void Sound::play(Seffect sound)
{
	switch(sound){
		case BUTTON:
			Mix_PlayChannel(-1, effect[0], 0);
			break;
		case SPIN:
			Mix_PlayChannel(-1, effect[1], 0);
			break;

	}
}

bool Sound::playing(){
	return Mix_PlayingMusic();
}

void Sound::music(Number number){
	if(Mix_PlayingMusic()){
		Mix_ResumeMusic();
	}else {
	switch(number){
		case ZERO:
			Mix_PlayMusic(num[0], -1);
			break;
		case ONE:
			Mix_PlayMusic(num[1], -1);
			break;
		case TWO:
			Mix_PlayMusic(num[2], -1);
			break;
		case THREE:
			Mix_PlayMusic(num[3], -1);
			break;
		case FOUR:
			Mix_PlayMusic(num[4], -1);
			break;
	}
	}
}

void Sound::pause(){
	Mix_PauseMusic();
}

Sound::~Sound() 
{
	//free();
}

bool Sound::load() 
{
	bool success = true;
	if(SDL_Init(SDL_INIT_AUDIO)<0){
		cerr << "SDL Audio error: " << SDL_GetError() << endl;
		success = false;
	}

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0){
		cerr << "Audio error: " << Mix_GetError() << endl;
		success = false;
	}

	effect[0] = Mix_LoadWAV("SFX/smb_bump.wav");
	effect[1] = Mix_LoadWAV("SFX/smb_jump-small.wav");


	num[0] = Mix_LoadMUS("0.wav");
	num[1] = Mix_LoadMUS("1.wav");
	num[2] = Mix_LoadMUS("2.wav");
	num[3] = Mix_LoadMUS("3.wav");
	num[4] = Mix_LoadMUS("4.wav");

	for(int i = 0; i < 2; ++i){
		if(effect[i]==NULL){
			cerr << "SFX error: " << Mix_GetError() << endl;
			success = false;
		}
	}
	
	for(int i = 0; i < 5; ++i){
		if(num[i]==NULL){
			cerr << "BGM error: " << Mix_GetError() << endl;
			success = false;
		}
	}
	return success;
}
