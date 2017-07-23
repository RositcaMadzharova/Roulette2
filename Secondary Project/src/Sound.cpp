#include "Sound.h"

Mix_Chunk* Sound::effect[];
Mix_Music* Sound::num[];

Sound::Sound() 
{
	//if(!load())
	//	cerr << "Sound loading failed" << endl;
}

void Sound::free() 
{
	for (int i = 0; i < 3; i++) {
		Mix_FreeChunk(effect[i]);
		effect[i] = NULL;
	}

	for (int i = 0; i < 38; i++) {
		Mix_FreeMusic(num[i]);
		num[i] = NULL;
	}

	Mix_Quit();	
}

void Sound::play(EFFECT sound)
{
	switch(sound){
		case CLICKBUTTON:
			Mix_PlayChannel(-1, effect[0], 0);
			break;
		case SPINROULETTE:
			Mix_PlayChannel(-1, effect[1], 0);
			break;
		case HEART:
			Mix_PlayChannel(-1, effect[2], 0);
			break;

	}
}

bool Sound::playing(){
	return Mix_PlayingMusic();
}

void Sound::music(NUMBER number){
	if(Mix_PlayingMusic()){
		Mix_ResumeMusic();
	}else {
	switch(number){
		case N0:
			Mix_PlayMusic(num[0], -1);
			break;
		case N1:
			Mix_PlayMusic(num[1], -1);
			break;
		case N2:
			Mix_PlayMusic(num[2], -1);
			break;
		case N3:
			Mix_PlayMusic(num[3], -1);
			break;
		case N4:
			Mix_PlayMusic(num[4], -1);
			break;
		case N5:
			Mix_PlayMusic(num[5], -1);
			break;
		case N6:
			Mix_PlayMusic(num[6], -1);
			break;
		case N7:
			Mix_PlayMusic(num[7], -1);
			break;
		case N8:
			Mix_PlayMusic(num[8], -1);
			break;
		case N9:
			Mix_PlayMusic(num[9], -1);
			break;
		case N10:
			Mix_PlayMusic(num[10], -1);
			break;
		case N11:
			Mix_PlayMusic(num[11], -1);
			break;
		case N12:
			Mix_PlayMusic(num[12], -1);
			break;
		case N13:
			Mix_PlayMusic(num[13], -1);
			break;
		case N14:
			Mix_PlayMusic(num[14], -1);
			break;
		case N15:
			Mix_PlayMusic(num[15], -1);
     		break;
		case N16:
			Mix_PlayMusic(num[16], -1);
			break;
		case N17:
			Mix_PlayMusic(num[17], -1);
			break;
		case N18:
			Mix_PlayMusic(num[18], -1);
			break;
		case N19:
			Mix_PlayMusic(num[19], -1);
			break;
		case N20:
			Mix_PlayMusic(num[20], -1);
			break;
		case N21:
			Mix_PlayMusic(num[21], -1);
			break;
		case N22:
			Mix_PlayMusic(num[22], -1);
			break;
		case N23:
			Mix_PlayMusic(num[23], -1);
	     	break;
		case N24:
	    	Mix_PlayMusic(num[24], -1);
			break;
		case N25:
			Mix_PlayMusic(num[25], -1);
			break;
		case N26:
			Mix_PlayMusic(num[26], -1);
			break;
		case N27:
			Mix_PlayMusic(num[27], -1);
			break;
		case N28:
			Mix_PlayMusic(num[28], -1);
			break;
		case N29:
			Mix_PlayMusic(num[29], -1);
			break;
		case N30:
			Mix_PlayMusic(num[30], -1);
			break;
		case N31:
			Mix_PlayMusic(num[31], -1);
			break;
		case N32:
			Mix_PlayMusic(num[32], -1);
			break;
		case N33:
			Mix_PlayMusic(num[33], -1);
			break;
		case N34:
			Mix_PlayMusic(num[34], -1);
			break;
		case N35:
			Mix_PlayMusic(num[35], -1);
			break;
		case N36:
			Mix_PlayMusic(num[36], -1);
			break;
		case WINNUM:
			Mix_PlayMusic(num[37], -1);
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

	effect[0] = Mix_LoadWAV("button.wav");
	effect[1] = Mix_LoadWAV("spin.wav");
	effect[2] = Mix_LoadWAV("heartbeat.wav");


	    num[0] = Mix_LoadMUS("0.wav");
		num[1] = Mix_LoadMUS("1.wav");
		num[2] = Mix_LoadMUS("2.wav");
		num[3] = Mix_LoadMUS("3.wav");
		num[4] = Mix_LoadMUS("4.wav");
		num[5] = Mix_LoadMUS("5.wav");
		num[6] = Mix_LoadMUS("6.wav");
		num[7] = Mix_LoadMUS("7.wav");
		num[8] = Mix_LoadMUS("8.wav");
		num[9] = Mix_LoadMUS("9.wav");
		num[10] = Mix_LoadMUS("10.wav");
		num[11] = Mix_LoadMUS("11.wav");
		num[12] = Mix_LoadMUS("12.wav");
		num[13] = Mix_LoadMUS("13.wav");
		num[14] = Mix_LoadMUS("14.wav");
		num[15] = Mix_LoadMUS("15.wav");
		num[16] = Mix_LoadMUS("16.wav");
		num[17] = Mix_LoadMUS("17.wav");
		num[18] = Mix_LoadMUS("18.wav");
		num[19] = Mix_LoadMUS("19.wav");
		num[20] = Mix_LoadMUS("20.wav");
		num[21] = Mix_LoadMUS("21.wav");
		num[22] = Mix_LoadMUS("22.wav");
		num[23] = Mix_LoadMUS("23.wav");
		num[24] = Mix_LoadMUS("24.wav");
		num[25] = Mix_LoadMUS("25.wav");
		num[26] = Mix_LoadMUS("26.wav");
		num[27] = Mix_LoadMUS("27.wav");
		num[28] = Mix_LoadMUS("28.wav");
		num[29] = Mix_LoadMUS("29.wav");
		num[30] = Mix_LoadMUS("30.wav");
		num[31] = Mix_LoadMUS("31.wav");
		num[32] = Mix_LoadMUS("32.wav");
		num[33] = Mix_LoadMUS("33.wav");
		num[34] = Mix_LoadMUS("34.wav");
		num[35] = Mix_LoadMUS("35.wav");
		num[36] = Mix_LoadMUS("36.wav");
		num[37] = Mix_LoadMUS("winnum.wav");

	for(int i = 0; i < 3; ++i){
		if(effect[i]==NULL){
			cerr << "EFFECT error: " << Mix_GetError() << endl;
			success = false;
		}
	}
	
	for(int i = 0; i < 37; ++i){
		if(num[i]==NULL){
			cerr << "NUMBER error: " << Mix_GetError() << endl;
			success = false;
		}
	}
	return success;
}
