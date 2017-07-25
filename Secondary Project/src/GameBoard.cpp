/*
 * GameBoard.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: kakev
 */

#include "GameBoard.h"

int value[POOLS_BUTTON] = { 2, 10, 20, 50, 100 };

GameBoard::GameBoard()
{
	double scaleX = 1200 / 1300.0;
	double scaleY = 750 / 800.0;
	background->loadFromFile("EuropeanRouletteFinal.bmp");
	background->setWidth(1200);
	background->setHeight(750);

	cashOut = new Button(958 * scaleX, 120 * scaleY);
	cashOut->loadFromFile("1.png");
	cashOut->setWidth(GAME_BOARD_BUTTON_W);
	cashOut->setHeight(GAME_BOARD_BUTTON_H);

	spin = new Button(1035 * scaleX, 725 * scaleY);
	spin->loadFromFile("1.png");
	spin->setWidth(GAME_BOARD_BUTTON_W);
	spin->setHeight(GAME_BOARD_BUTTON_H);

	history = new Button(150 * scaleX, 120 * scaleY);
	history->loadFromFile("1.png");
	history->setWidth(GAME_BOARD_BUTTON_W);
	history->setHeight(GAME_BOARD_BUTTON_H);

	accounting = new Button(555 * scaleX, 120 * scaleY);
	accounting->loadFromFile("1.png");
	accounting->setWidth(GAME_BOARD_BUTTON_W);
	accounting->setHeight(GAME_BOARD_BUTTON_H);

	clearBets = new Button(70 * scaleX, 725 * scaleY);
	clearBets->loadFromFile("1.png");
	clearBets->setWidth(GAME_BOARD_BUTTON_W);
	clearBets->setHeight(GAME_BOARD_BUTTON_H);

	for (int i = 0; i < POOLS_BUTTON; i++)
	{
		gameBoardPools[i] = new Button(335 + i * 123 * scaleX, 710 * scaleY);
		gameBoardPools[i]->loadFromFile("Pools.png");
		gameBoardPools[i]->setHeight(4 * POOLS_W);
		gameBoardPools[i]->setWidth(4 * POOLS_H);
	}
	isActive = false;
	sound = new Sound;
}

GameBoard::~GameBoard()
{
	for (int i = 0; i < POOLS_BUTTON; i++)
	{
		delete gameBoardPools[i];
	}
	cashOut->free();
	delete cashOut;

	spin->free();
	delete spin;

	history->free();
	delete history;

	accounting->free();
	delete accounting;

	clearBets->free();
	delete clearBets;

	delete sound;
}

bool GameBoard::Draw()
{
	background->render(NULL, 0, NULL);

// we have already the buttons dont need to render them :)

//	for(int i = 0 ; i < POOLS_BUTTON ; i++)
//	{
//		SDL_Rect rectButton = { 113 * i + 3, 1, 112, 111 };
//		gameBoardPools[i]->render(&rectButton,0,NULL);
//	}
//	cashOut->render(NULL,0,NULL);
//	spin->render(NULL,0,NULL);
//	history->render(NULL,0,NULL);
//	accounting->render(NULL,0,NULL);
//	clearBets->render(NULL,0,NULL);
	isActive = true;
	return true;
}

bool GameBoard::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;
	return true;
}

int GameBoard::CalcQuadrandClicked(int x, int y)
{
//help variable that starts from 0 to 39 in the loops below
	int sequence = -1;
	int clickedCell = -1;

//for 3 lines
	for (int line = 0; line < 3; line++)
	{
		//for each cell in each line
		for (int i = 0; i < 13; i++)
		{
			sequence++;

			//step is 75 ; start position of table is from x=70 and y=140
			if (x >= 76 + (75 * i)
					&& x <= (151 + 75 * i)
					&& y >= 280 + (75 * line)
					&& y <= 350 + (75 * line))
			{

				clickedCell = sequence;
			}
		}
	}
	//separate logic or 40, 41, 42, 43 (event, red, black, odd)
	//even  [40 number cell]
	//red   [41 number cell]
	//black [42 number cell]
	//odd   [43 number cell]
	//start from x=300; step = 150; y btw 585 and 650
	for (int i = 0; i < 4; i++)
	{
		if (x >= 300 + (150 * i) && x <= 450 + (150 * i) && y >= 585
				&& y <= 650)
		{
			clickedCell = 39 + i;
		}
	}

//	cout << "clickedCell:" << clickedCell << endl;
	return clickedCell;
}

void GameBoard::DisplayBets(Credits* credits, int x, int y, int color,
							bool resume, Recovery* recovery)
// also use for the credit calculations
{
	int coordX = -1;
	int coordY = -1;

	int clickedCell = CalcQuadrandClicked(x, y);

	for (int j = 0; j < POOLS_BUTTON; j++)
		if (color == j + 1)
		{

			//for all 39 cells
			for (int i = 0; i <= 39; i++)
			{
				if (i == 0 || i == 26)
					continue;
				if (clickedCell == i)
				{
					coordX = 77 + (i - ((i / 13) * 13)) * 75 + i % 13;
					coordY = 280 + (i / 13) * 77;
				}
			}

			//separate logic for Even, Red, Black, Odd (Cell with numbers: 40,41,42,43)
			for (int i = 39; i <= 43; i++)

				if (clickedCell == i)
				{

					//start from x=350, step = 150, i-40 used to get sequence 0,1,2,3
					coordX = 342 + (150 * (i - 39));
					coordY = 587;

				}

			if (coordX != -1 && coordY != -1)
			{
				if (credits->GetCredit() >= value[j])	//credits logic
				{
					Button gameBoardPools(coordX, coordY);
					gameBoardPools.loadFromFile("Pools.png");
					gameBoardPools.setWidth(POOLS_W);
					gameBoardPools.setHeight(POOLS_H);

					SDL_Rect rec = { j * 111 + 5, 1, 111, 110 };

					gameBoardPools.render(&rec, 0, NULL, SDL_FLIP_NONE, 60, 60);

					//while piece to write on
					LTexture overPullUnderText(coordX + 17, coordY + 17);
					overPullUnderText.loadFromFile("BALL.png");
					overPullUnderText.setWidth(POOLS_W);
					overPullUnderText.setHeight(POOLS_H);
					overPullUnderText.render(NULL, 0, NULL, SDL_FLIP_NONE,
							POOLS_W / 3, POOLS_H / 3);
					sound->play(CLICKBUTTON);

					if (!resume)
					{
						credits->AddBet(value[j]);
						credits->ChangeCredits(-value[j]);
						credits->betByNumberCell[clickedCell] += value[j];
					}
					Text textInPool(coordX + 20, coordY + 22, POOLS_W / 2 + 8,
							POOLS_H / 2 + 8, 15,
							credits->betByNumberCell[clickedCell]
							, { 0, 0, 0, 255 }, "Intro.otf");

					Text textBet(SCREEN_BOARD_W / 2 + 25, 40, 45, 35, 15,
							credits->GetBet(),
							{ 200, 200, 200, 255 });

					recovery->appendToXML(credits->betByNumberCell);
					recovery->appendToXMLCredits(credits->GetCredit(),
							credits->GetBet(), credits->GetCreditsCollected());
				}					//end credits
			}
		}					//end if and for

	LTexture underTextLayer(SCREEN_W / 2 - 25, 40);
	underTextLayer.loadFromFile("EuropeanRouletteFinalGreen.bmp");
	underTextLayer.setWidth(50);
	underTextLayer.setHeight(35);
	underTextLayer.render(NULL);

	Text textBet(SCREEN_BOARD_W / 2 + 25, 40, 45, 35, 15, credits->GetBet(),
			{ 200, 200, 200, 255 });

}

void GameBoard::DisplayStatistics(Credits* credits, int lastWinningNumber)
{
	Text textCash(SCREEN_BOARD_W / 5, 40, 45, 35, 15,
			credits->GetCredit() * DENOMINATION,
			{ 200, 200, 200, 255 });

	Text textBet(SCREEN_BOARD_W / 2 + 25, 40, 45, 35, 15,
			credits->GetBet(),
			{ 200, 200, 200, 255 });

	if (lastWinningNumber != -1)
		Text textWin(SCREEN_W * 3 / 4, 40, 45, 35, 15,
				lastWinningNumber,
				{ 200, 200, 200, 255 });
	else
		Text textWin(SCREEN_W * 3 / 4, 40, 100, 35, 15,
				"no spins yet", { 200,
						200, 200, 255 });
}

