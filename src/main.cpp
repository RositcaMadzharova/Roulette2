/*

 * main.cpp
 *
 *  Created on: Jul 89, 2017
 *      Author: pepi
 */
#include "Globals.h"
#include "Background.h"
#include "Button.h"
#include "Pools.h"
#include "Credits.h"

GameState game = INTRO_MENU;
//INFO,GAME_BOARD,SPIN,OUTRO,WIN

Pools MenuScreen(Credits cr) {

	game = INTRO_MENU;

	Background back("INTRO_MENU", SCREEN_W, SCREEN_H, "chessboard.png");

	//display image
	LTexture tex1;
	tex1.loadFromFile(Background::gRenderer, "chessboard.png");
	SDL_Rect rect32 = { 0, 0, 1600, 1200 };
	tex1.setWidth(800);
	tex1.setHeight(600);
	tex1.render(Background::gRenderer, &rect32);

	Pools p1(cr, 300, 330, 10);
	p1.loadFromFile(Background::gRenderer, "Pools.png");

	SDL_Rect rect = { 118, 1, 118, 111 };
	p1.setHeight(59);
	p1.setWidth(59);
	p1.render(Background::gRenderer, &rect);

	return p1;
}

void destroyWindow()
{
	//Destroy window
	SDL_DestroyRenderer( Background::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Background::gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
    //End destroy window

}
int main(int argc, char *argv[]) {



	Credits cr;

	Pools p1;
	p1 = MenuScreen(cr);

	Pools bMainMenu(cr, 400, 400, 10);
	int counter=0;


	bool close = false;
	while (!close) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				close = true;
			}
			if (p1.isClicked(&e)) {

				if (game == INTRO_MENU) {

					p1.free();
					destroyWindow();
					game = INFO;

				}

				if(game == INFO)
				{
					Background secondWindow("INFO WINDOW", SCREEN_W, SCREEN_H, "rouletterules.jpg");


					bMainMenu.loadFromFile(Background::gRenderer, "Pools.png");
					SDL_Rect rect1 = { 118, 1, 118, 111 };
					bMainMenu.setHeight(59);
					bMainMenu.setWidth(59);
					bMainMenu.render(Background::gRenderer, &rect1);


				}

			}

			//button that returns to MainMenuPage
			if (bMainMenu.isClicked(&e)) {

				bMainMenu.free();
				destroyWindow();

				p1 = MenuScreen(cr);
				game = INTRO_MENU;


			}


//			if (p1.isHover()) {
//				std::cout << "hovered" << endl;
//			}

		}
	}

	return 0;
}
