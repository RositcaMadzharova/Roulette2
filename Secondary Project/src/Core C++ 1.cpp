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
#include "SpinScreen.h"
#include "OutroScreen.h"
#include "Recovery.h"
#include "Sound.h"

int main(int argc, char *argv[])
{
	int numberOfSpins = 0;


	LWindow myWin;
	myWin.init();

	//resourse
	Recovery recovery;

	Credits credits;

	//screens
	IntroScreen intro;
	InfoScreen info;
	GameBoard game;
	SpinScreen spin;
	BonusScreen bonus;
	WinScreen win;
	OutroScreen outro;

	intro.Draw();

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
				//Not in game board
				if(!game.getFlag())
				{
					//Intro
					if (intro.introButtons[0]->isClicked(&e)
							&& intro.getFlag() == true)
					{
						intro.Clear();
						info.Draw();
					}
					if (intro.introButtons[1]->isRightClicked(&e)
							&& credits.GetCredit())
					{
						credits.ChangeCredits(-ADD_CREDIT_BUTTON_VALUE);
						intro.IntroScreenShowCredits(credits);
					}
					else if(intro.introButtons[1]->isClicked(&e)
							&& intro.getFlag() == true)
					{
						credits.ChangeCredits(ADD_CREDIT_BUTTON_VALUE);

						intro.IntroScreenShowCredits(credits);
					}
					if(intro.introButtons[2]->isClicked(&e)
							&& intro.getFlag() == true)
					{
						//TODO: music
	//					intro.Clear();
	//					if(win.Draw())
	//					{
	//						win.Clear();
	//						intro.Draw();
	//					}
					}
					if (intro.introButtons[3]->isClicked(&e)
							&& intro.getFlag() == true)
					{
						intro.Clear();
						game.Draw();
						game.DisplayStatistics(&credits,recovery.lastWiningNumbers.back());
					}
					if(intro.introButtons[4]->isClicked(&e)
							&& intro.getFlag() == true)
					{

					}
					//Info
					if (info.infoBack->isClicked(&e)
							&& info.getFlag() == true)
					{
						info.Clear();
						intro.Draw();
					}
				}
				//Game board
				else
				{
					int x, y;
					int color;

					for (int i = 0; i < POOLS_BUTTON; i++)
						if (game.gameBoardPools[i]->isClicked(&e))
						{

							game.sound->play(CLICKBUTTON);//					click->Play();
							SDL_GetMouseState(&x, &y);
							color = i + 1;
						}
					if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						if (e.button.button == SDL_BUTTON_LEFT)
						{
							SDL_GetMouseState(&x, &x);
							x = e.button.x;
							y = e.button.y;

							cout << x << ":" << y << endl;

							game.DisplayBets(&credits,x, y, color);//, v_pointsBetInfo);
						}
					}
					if(game.spin->isClicked(&e) )
					{
						game.sound->play(CLICKBUTTON);
						game.Clear();
						if(spin.Draw())
						{
							spin.Clear();
							game.Draw();
							game.DisplayStatistics(&credits ,recovery.lastWiningNumbers.back());
						}

						numberOfSpins ++;
					}
					if(game.cashOut->isClicked(&e))
					{
						game.sound->play(CLICKBUTTON);
						game.Clear();
						if(outro.Draw())
						{
							outro.Clear();
							intro.Draw();
						}
					}
					if(game.clearBets->isClicked(&e))
					{
						game.sound->play(CLICKBUTTON);
						for (map<int, int>::iterator i =
													credits.betByNumberCell.begin();
													i != credits.betByNumberCell.end(); i++)
												i->second = 0;
											credits.ChangeCredits(credits.GetBet());
											credits.AddBet(-credits.GetBet());
											game.Draw();
											game.DisplayStatistics(&credits , recovery.lastWiningNumbers.back());
					}
					if(numberOfSpins == SPINS_TO_BONUS)
					{
						game.sound->play(CLICKBUTTON);
						game.Clear();
						if(bonus.Draw(credits))
						{
							bonus.Clear();
							game.Draw();
							game.DisplayStatistics(&credits , recovery.lastWiningNumbers.back());
						}
						numberOfSpins = 0;
					}
				}
			}
		}
	}
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();


	return 0;
}
