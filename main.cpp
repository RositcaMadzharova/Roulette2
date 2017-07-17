#include "Texture.h"
#include <SDL2/SDL_mixer.h>


const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

const int RECT_WIDTH = 200;
const int RECT_HEIGHT = 200;

bool init();

bool loadMedia();

void close();

bool IsInsideImage(SDL_Event& e, SDL_Rect& imageRect);

SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;

SDL_Renderer* gRenderer = NULL;
SDL_Rect gSpriteClips[2];

//The music that will be played
Mix_Music *MyMusic = NULL;

Texture gPromptTexture;
Texture gSpriteSheetTexture;
int main(int argc, char* args[]) {

	init() ? cerr << "" : cerr << "Failed to initialize sdl.";
	loadMedia() ? cerr << "" : cerr << "Failed to load media.";

	bool quit = false;
	SDL_Event e;
	SDL_RenderClear(gRenderer);
	//Render the cards
	int xPos = 50;
	for (int i = 0; i < 2; i++) {
		gSpriteSheetTexture.Render(xPos, 50, &gSpriteClips[i]);
		xPos += 250;
	}

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (IsInsideImage(e, gSpriteClips[0])) {
				Mix_PlayMusic(MyMusic, -1);

			}
			if (IsInsideImage(e, gSpriteClips[1])) {


				Mix_HaltMusic();


			}



			//Update screen
			SDL_RenderPresent(gRenderer);

		} //while2
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

		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cerr << "Window could not be created! SDL Error: %s"
					<< SDL_GetError() << endl;
			success = false;
		} else {

			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				cerr << "Renderer could not be created! SDL Error: %s"
						<< SDL_GetError() << endl;
				success = false;
			} else {

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cerr
							<< "SDL_image could not initialize! SDL_image Error: %s"
							<<
							IMG_GetError() << endl;
					success = false;

				}
				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					cout
							<< "SDL_mixer could not initialize! SDL_mixer Error: %s\n"
							<< endl << Mix_GetError();
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia() {
	bool success = true;
	gSpriteSheetTexture.gRenderer = gRenderer;
	if (!gSpriteSheetTexture.LoadFromFile("Buttons.png")) {
		cout << "Failed to load sprite sheet texture!\n";
		success = false;
	} else {
		int offsetX = 200;
		for (int i = 0; i < 2; i++) {
			gSpriteClips[i].x = i * offsetX;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 200;
			gSpriteClips[i].h = 200;
		}
	}

	MyMusic = Mix_LoadMUS("ShakeYourBootay.wav");
	if (MyMusic == NULL) {
		cout << "Failed to load medium sound effect! SDL_mixer Error: %s"
				<< endl << Mix_GetError();
		success = false;
	}

	return success;
}

void close() {

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	//Free the music
	Mix_FreeMusic(MyMusic);
	MyMusic = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool IsInsideImage(SDL_Event& e, SDL_Rect& imageRect) {
	bool check = false;
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < imageRect.x) {
			inside = false;
		} else if (x > imageRect.x + imageRect.w) {
			inside = false;
		} else if (y < imageRect.y) {
			inside = false;
		} else if (y > imageRect.y + imageRect.h) {
			inside = false;
		}

		if (inside) {
			check = true;
		}
	}
	return check;
}

