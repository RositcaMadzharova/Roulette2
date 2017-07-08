/*
 * main.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: kakev
 */
#include "Globals.h"
#include "Background.h"
#include "Button.h"
#include "Pools.h"
#include "Credits.h"

GameState game = INTRO_MENU;
//INFO,GAME_BOARD,SPIN,OUTRO,WIN
static int static_counter = 0;

Pools MenuScreen(Credits cr) {

	//faec backgroud
	if (static_counter == 0) {
		Background back("Intro Screen", SCREEN_W, SCREEN_H, "chessboard.png");
	}
	static_counter++;

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



//	Pools pG(cr, 300, 330, 10);
//	p1.loadFromFile(Background::gRenderer, "Pools.png");
//
//	SDL_Rect rect = { 118, 1, 118, 111 };
//	p1.setHeight(59);
//	p1.setWidth(59);
//	p1.render(Background::gRenderer, &rect);




	return p1;
}

int main(int argc, char *argv[]) {

	Credits cr;

	Pools p1;
	p1 = MenuScreen(cr);

	Pools bMainMenu(cr, 400, 400, 10);

	bool close = false;
	while (!close) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				close = true;
			}
			if (p1.isClicked(&e)) {

				if (game == INTRO_MENU) {

					LTexture tex;
					tex.loadFromFile(Background::gRenderer,
							"rouletterules.jpg");
					SDL_Rect rect2 = { 0, 0, 1600, 1200 };
					tex.setWidth(800);
					tex.setHeight(600);
					tex.render(Background::gRenderer, &rect2);

					bMainMenu.loadFromFile(Background::gRenderer, "Pools.png");

					SDL_Rect rect1 = { 118, 1, 118, 111 };
					bMainMenu.setHeight(59);
					bMainMenu.setWidth(59);
					bMainMenu.render(Background::gRenderer, &rect1);

				}

			}

			//button that returns to MainMenuPage
			if (bMainMenu.isClicked(&e)) {

				Pools p2;
				p2 = MenuScreen(cr);
			}

			if (p1.isHover()) {
				std::cout << "hovered" << endl;
			}

		}
	}

	return 0;
}
