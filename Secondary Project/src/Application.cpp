///*
// * Application.cpp
// *
// *  Created on: 25.07.2017 ã.
// *      Author: Viktor
// */
//
//#include "Application.h"
//
//Application::Application()
//{
//	intro.Draw();
//}
//
//Application::~Application()
//{
//	Mix_Quit();
//	TTF_Quit();
//	IMG_Quit();
//	SDL_Quit();
//}
//
//
//void ActivateGameBoard(SDL_Event e)
//{
//	int x, y;
//	int color;
//
//	for (int i = 0; i < POOLS_BUTTON; i++)
//		if (game.gameBoardPools[i]->isClicked(&e))
//		{
////							TODO: sound for placing pools on board
////							game.sound->play(CLICKBUTTON);
//			SDL_GetMouseState(&x, &y);
//			color = i + 1;
//		}
//	if (e.type == SDL_MOUSEBUTTONDOWN)
//	{
//		if (e.button.button == SDL_BUTTON_LEFT)
//		{
//			SDL_GetMouseState(&x, &x);
//			x = e.button.x;
//			y = e.button.y;
//
//			game.DisplayBets(&credits, x, y, color);
//		}
//	}
//	if (game.spin->isClicked(&e))
//	{
//		game.sound->play(CLICKBUTTON);
//		game.Clear();
//		if (spin.Draw())
//		{
//			spin.Clear();
//			credits.AddCreditsCollected(
//					+0.13 * credits.GetBet());
//			if (credits.CollectProfit(spin.GetWinningNumber()))
//			{
//				win.Draw();
//				win.ShowCredits(&credits);
//				win.Clear();
//			}
//
//			game.Draw();
//			game.DisplayStatistics(&credits,
//					recovery.lastWiningNumbers.back());
//		}
//	}
//	if (game.cashOut->isClicked(&e))
//	{
//		game.sound->play(CLICKBUTTON);
//		game.Clear();
//		if (outro.Draw())
//		{
//			outro.Show(&credits);
//			SDL_Delay(3000); //10000;
//			outro.Clear();
//			intro.Draw();
//		}
//	}
//	if (game.clearBets->isClicked(&e))
//	{
//		game.sound->play(CLICKBUTTON);
//		for (map<int, int>::iterator
//		i = credits.betByNumberCell.begin();
//				i != credits.betByNumberCell.end();
//				i++)
//			i->second = 0;
//		credits.ChangeCredits(credits.GetBet());
//		credits.AddBet(-credits.GetBet());
//		game.Draw();
//		game.DisplayStatistics(&credits,
//				recovery.lastWiningNumbers.back());
//	}
//	if (spin.IsReadyForBonus())
//	{
//		game.Clear();
//		if (bonus.Draw() && bonus.getBonusCreditsText(&credits))
//		{
//			credits.ChangeCredits(
//					credits.GetCreditsCollected());
//			credits.AddCreditsCollected(
//					-credits.GetCreditsCollected());
//			bonus.Clear();
//			game.Draw();
//			game.DisplayStatistics(&credits,
//					recovery.lastWiningNumbers.back());
//		}
//	}
//}
//
//void ActivateIntro(SDL_Event e)
//{
//	if (intro.introButtons[0]->isClicked(&e)
//			&& intro.getFlag() == true)
//	{
//		intro.Clear();
//		info.Draw();
//	}
//	if (intro.introButtons[1]->isRightClicked(&e)
//			&& credits.GetCredit())
//	{
//		credits.ChangeCredits(-ADD_CREDIT_BUTTON_VALUE);
//		intro.IntroScreenShowCredits(credits);
//	}
//	else
//		if (intro.introButtons[1]->isClicked(&e)
//				&& intro.getFlag() == true)
//		{
//			credits.ChangeCredits(ADD_CREDIT_BUTTON_VALUE);
//			intro.IntroScreenShowCredits(credits);
//		}
//	if (intro.introButtons[2]->isClicked(&e)
//			&& intro.getFlag() == true)
//	{
////						TODO: music
//	}
//	if (intro.introButtons[3]->isClicked(&e)
//			&& intro.getFlag() == true)
//	{
//		intro.Clear();
//		game.Draw();
//		game.DisplayStatistics(&credits,
//				recovery.lastWiningNumbers.back());
//	}
//	if (intro.introButtons[4]->isClicked(&e)
//			&& intro.getFlag() == true)
//	{
////						TODO: resume
//	}
//}
//void ActivateInfo(SDL_Event e)
//{
//	if (info.infoBack->isClicked(&e)
//			&& info.getFlag() == true)
//	{
//		info.Clear();
//		intro.Draw();
//	}
//}
//
