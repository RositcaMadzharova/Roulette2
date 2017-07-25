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
	LWindow myWin;

	//resource
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

				if (info.getFlag())
				{
					info.sound->play(CLICKBUTTON);
					if (info.infoBack->isClicked(&e)
							&& info.getFlag() == true)
					{
						info.Clear();
						intro.Draw();
					}
				}
				if (intro.getFlag())
				{
					if (intro.introButtons[0]->isClicked(&e)
							&& intro.getFlag() == true)
					{
						intro.sound->play(CLICKBUTTON);
						intro.Clear();
						info.Draw();
					}
					if (intro.introButtons[1]->isRightClicked(&e)
							&& credits.GetCredit())
					{
						intro.sound->play(CLICKBUTTON);
						credits.ChangeCredits(-ADD_CREDIT_BUTTON_VALUE);
						intro.IntroScreenShowCredits(credits);
					}
					else
						if (intro.introButtons[1]->isClicked(&e)
								&& intro.getFlag() == true)
						{
							intro.sound->play(CLICKBUTTON);
							credits.ChangeCredits(ADD_CREDIT_BUTTON_VALUE);
							intro.IntroScreenShowCredits(credits);
						}
					if (intro.introButtons[2]->isClicked(&e)
							&& intro.getFlag() == true)
					{
						intro.sound->play(CLICKBUTTON);
						if (Mix_PausedMusic() == 1)
						{
							//Resume the music
							Mix_ResumeMusic();
						}
						//If the music is playing
						else
						{
							//Pause the music
							Mix_PauseMusic();
						}
					}
					if (intro.introButtons[3]->isClicked(&e)
							&& intro.getFlag() == true
							&& credits.GetCredit() != 0)
					{
						intro.sound->play(CLICKBUTTON);
						intro.Clear();
						game.Draw();
						game.DisplayStatistics(&credits,
								recovery.lastWiningNumbers.back());
					}
					if (intro.introButtons[4]->isClicked(&e))
					{
						intro.sound->play(CLICKBUTTON);
						intro.Clear();
						if (game.Draw())
						{
							credits = recovery.readXMLWriteCredit(
									"roulette_recovery_credits.xml");
							credits.betByNumberCell = recovery.readXMLWriteMap(
									"roulette_recovery.xml");
							game.DisplayStatistics(&credits,
									recovery.lastWiningNumbers.back());
							for (int y = 285; y < SCREEN_BOARD_H; y += 75)
								for (int x = 77;
										x < SCREEN_BOARD_W - 77; x += 75)
								{
									if (y > 550)
										x += 75;
									if (credits.betByNumberCell[
											game.CalcQuadrandClicked(x, y)] > 0)
										game.DisplayBets(&credits, x, y, 1,
												true, &recovery);
								}
						}
					}
				}
				if (game.getFlag())
				{
					int x, y;
					int color;

					for (int i = 0; i < POOLS_BUTTON; i++)
						if (game.gameBoardPools[i]->isClicked(&e))
						{
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

							game.DisplayBets(&credits, x, y, color, false,
									&recovery);
						}
					}
					if (game.spin->isClicked(&e))
					{
						game.sound->play(CLICKBUTTON);
						game.Clear();
						if (spin.Draw())
						{
							recovery.ShowLastWinningNumber(&spin);

							spin.Clear();
							credits.AddCreditsCollected(
									+0.13 * credits.GetBet());
							if (credits.CollectProfit(spin.GetWinningNumber()))
							{
								win.Draw();
								SDL_Delay(1000);
								win.sound->play(WINSCREEN);
								win.ShowCredits(&credits);
								win.Clear();
							}

							recovery.appendToXML(credits.betByNumberCell);
							recovery.appendToXMLCredits(credits.GetCredit(),
									credits.GetBet(), credits.GetCreditsCollected());

							game.Draw();
							game.DisplayStatistics(&credits,
									recovery.lastWiningNumbers.back());
						}
					}
					if (game.cashOut->isClicked(&e))
					{
						game.sound->play(CLICKBUTTON);
						game.Clear();
						if (outro.Draw())
						{
							outro.Show(&credits);
							credits.ChangeCredits(-credits.GetCredit());
							SDL_Delay(3000); //10000;
							outro.Clear();
							intro.Draw();
						}
					}
					if (game.clearBets->isClicked(&e))
					{
						game.sound->play(CLICKBUTTON);
						for (map<int, int>::iterator
						i = credits.betByNumberCell.begin();
								i != credits.betByNumberCell.end();
								i++)
							i->second = 0;
						credits.ChangeCredits(credits.GetBet());
						credits.AddBet(-credits.GetBet());
						game.Draw();
						game.DisplayStatistics(&credits,
								recovery.lastWiningNumbers.back());
					}
					if (spin.IsReadyForBonus() != 0
							&& credits.GetCreditsCollected() != 0)
					{
						game.Clear();
						if (bonus.Draw() && bonus.getBonusCreditsText(&credits))
						{
							credits.ChangeCredits(
									credits.GetCreditsCollected());
							credits.AddCreditsCollected(
									-credits.GetCreditsCollected());
							bonus.Clear();
							game.Draw();
							game.DisplayStatistics(&credits,
									recovery.lastWiningNumbers.back());
						}
					}
					if (game.history->isClicked(&e))
					{
						int x = 30;
						int y = 180;

						queue<int> historyShow(recovery.lastWiningNumbers);
						int counter = 0;
						SDL_Color red { 255, 0, 0, 255 };
						SDL_Color black { 0, 255, 255, 255 };
						while (!historyShow.empty())
						{
							if (counter == 9)
							{
								x = 30;
								y = 230;
							}
							if (historyShow.front() != -1)
							{
								x += 40;
								if (credits.colorToNumberInRoulette[historyShow.front()]
										== 'r')
									Text historyText(x, y, 35, 30, 20,
											historyShow.front(), red); // view front element
								else
									Text historyText(x, y, 35, 30, 10,
											historyShow.front(), black); // view front element
							}
							historyShow.pop(); // remove element
							counter++;
						}
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
