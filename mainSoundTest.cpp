#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
using namespace std;


bool init();

bool loadMedia();

void close();

//The music that will be played
Mix_Music *MyMusic = NULL;

int main(int argc, char* args[]) {

	init() ? cerr << "" : cerr << "Failed to initialize sdl.";
	loadMedia() ? cerr << "" : cerr << "Failed to load media.";

	bool quit = false;
//	SDL_Event e;
	char e;

	while (!quit) {
		cin>>e;
//		while (SDL_PollEvent(&e) != 0) {
//			if (e.type == SDL_QUIT) {
			if(e == 'q'){
				quit = true;
			}
			if (e == 'p') {
				Mix_PlayMusic(MyMusic, -1);
			}
			if (e == 's') {
				Mix_HaltMusic();
			}

//		} //while2
	} //while1
	close();
	return 0;
}
bool init() {

	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError()
				<< endl;
		success = false;
	} else {

				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					cout
							<< "SDL_mixer could not initialize! SDL_mixer Error: %s\n"
							<< endl << Mix_GetError();
					success = false;
				}
			}

	return success;
}

bool loadMedia() {
	bool success = true;
	MyMusic = Mix_LoadMUS("ShakeYourBootay.wav");
	if (MyMusic == NULL) {
		cout << "Failed to load medium sound effect! SDL_mixer Error: %s"
				<< endl << Mix_GetError();
		success = false;
	}

	return success;
}

void close() {
	//Free the music
	Mix_FreeMusic(MyMusic);
	MyMusic = NULL;


	SDL_Quit();
}
