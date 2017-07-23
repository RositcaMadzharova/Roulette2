//============================================================================
// Name        : Core.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "InfoScreen.h"
#include "LWindow.h"
#include "LTexture.h"
#include "IntroScreen.h"
#include "GameBoard.h"
#include "BonusScreen.h"
#include "WinScreen.h"

int main(int argc, char *argv[])
{
	LWindow myWin;
	myWin.init();
	Credits cr(500);
	cr.setCreditsCollected(500);
//	LTexture myText(0,0);

	IntroScreen intro;
	InfoScreen info;
	GameBoard game;
	BonusScreen bonus;
	WinScreen win;

//	Button myBut(10 , 10 );
	intro.Draw();

//	info.DrawInfo();
//	info.InitInfo();

//	intro.InitIntro( myText.GetPtr());
//
//	Button myButton ;
//
	while (true)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_SPACE)
			{
				break;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (intro.introButtons[0]->isClicked(&e)
						&& intro.getFlag() == true)
				{
					intro.Clear();
					info.Draw();
				}


				if(intro.introButtons[1]->isClicked(&e)
						&& intro.getFlag() == true)
				{

					intro.Clear();
					if(bonus.Draw())

					intro.Draw();
				}
				if(intro.introButtons[2]->isClicked(&e)
									&& intro.getFlag() == true)
				{
					intro.Clear();
					if(win.Draw())
					{
						intro.Draw();
					}

				}
				if (intro.introButtons[3]->isClicked(&e)
						&& intro.getFlag() == true)
				{
					intro.Clear();
					game.Draw();
				}
				if (info.infoBack->isClicked(&e)
						&& info.getFlag() == true)
				{
					info.Clear();
					intro.Draw();
				}


			}
		}
	}

//		switch (SCREENSTATE)
//		{
//
//		case INTRO_SCREEN:
//
//			info.ClearInfo();
//
//			if ( intro.InitIntro() )
//			{
//				std::cout << "Init Intro " << std::endl ;
//				SCREENSTATE = LISTEN_TO_EVENT;
//				continue;
//			}
//			break;
//
//		case INFO_SCREEN:
//
//			intro.ClearIntro();
//
//			if (info.InitInfo())
//			{
//				std::cout << "INIT" << std::endl;
//				SCREENSTATE = LISTEN_TO_EVENT;
//				continue;
//			}
//			break;
//		}

	return 0;
}
