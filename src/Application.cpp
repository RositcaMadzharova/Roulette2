/*
 * Application.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: pEftimov
 */

#include "Application.h"



string colors[POOLS_BUTTON] = { "yellow", "green", "red", "blue", "black" };
int value[POOLS_BUTTON] = { 2, 10, 20, 50, 100 };
string introButtonText[INTRO_BUTTONS] = { "     INFO     ", " ADD 100 CREDIT ",
		"    VOLUME    ", "START NEW GAME", " RESUME GAME " };
map<int, int> posissionToNumberInRoulette;
map<int, char> colorToNumberInRoulette;

int NumberInCell(int i)
{
	if (i == 14)
		return 0;
	if (i > 0 && i <= 13)
		return i * 3;
	if (i > 14 && i <= 26)
		return (i - 13) * 3 - 1;
	if (i > 27 && i <= 39)
		return (i - 26) * i - 2;
	return -100;
}

void FillTheMapsOfRoulette()
{
	posissionToNumberInRoulette[6] = 0;
	posissionToNumberInRoulette[27] = 1;
	posissionToNumberInRoulette[13] = 2;
	posissionToNumberInRoulette[36] = 3;
	posissionToNumberInRoulette[11] = 4;
	posissionToNumberInRoulette[30] = 5;
	posissionToNumberInRoulette[8] = 6;
	posissionToNumberInRoulette[23] = 7;
	posissionToNumberInRoulette[10] = 8;
	posissionToNumberInRoulette[5] = 9;
	posissionToNumberInRoulette[24] = 10;
	posissionToNumberInRoulette[16] = 11;
	posissionToNumberInRoulette[33] = 12;
	posissionToNumberInRoulette[1] = 13;
	posissionToNumberInRoulette[20] = 14;
	posissionToNumberInRoulette[14] = 15;
	posissionToNumberInRoulette[31] = 16;
	posissionToNumberInRoulette[9] = 17;
	posissionToNumberInRoulette[22] = 18;
	posissionToNumberInRoulette[18] = 19;
	posissionToNumberInRoulette[29] = 20;
	posissionToNumberInRoulette[7] = 21;
	posissionToNumberInRoulette[28] = 22;
	posissionToNumberInRoulette[12] = 23;
	posissionToNumberInRoulette[35] = 24;
	posissionToNumberInRoulette[3] = 25;
	posissionToNumberInRoulette[26] = 26;
	posissionToNumberInRoulette[0] = 27;
	posissionToNumberInRoulette[32] = 28;
	posissionToNumberInRoulette[15] = 29;
	posissionToNumberInRoulette[19] = 30;
	posissionToNumberInRoulette[4] = 31;
	posissionToNumberInRoulette[21] = 32;
	posissionToNumberInRoulette[2] = 33;
	posissionToNumberInRoulette[25] = 34;
	posissionToNumberInRoulette[17] = 35;
	posissionToNumberInRoulette[34] = 36;

	colorToNumberInRoulette[6] = 'b';
	colorToNumberInRoulette[27] = 'r';
	colorToNumberInRoulette[13] = 'b';
	colorToNumberInRoulette[36] = 'r';
	colorToNumberInRoulette[11] = 'b';
	colorToNumberInRoulette[30] = 'r';
	colorToNumberInRoulette[8] = 'b';
	colorToNumberInRoulette[23] = 'r';
	colorToNumberInRoulette[10] = 'b';
	colorToNumberInRoulette[5] = 'r';
	colorToNumberInRoulette[24] = 'b';
	colorToNumberInRoulette[16] = 'r';
	colorToNumberInRoulette[33] = 'b';
	colorToNumberInRoulette[1] = 'r';
	colorToNumberInRoulette[20] = 'b';
	colorToNumberInRoulette[14] = 'r';
	colorToNumberInRoulette[31] = 'b';
	colorToNumberInRoulette[9] = 'r';
	colorToNumberInRoulette[22] = 'b';
	colorToNumberInRoulette[18] = 'r';
	colorToNumberInRoulette[29] = 'b';
	colorToNumberInRoulette[7] = 'r';
	colorToNumberInRoulette[28] = 'b';
	colorToNumberInRoulette[12] = 'r';
	colorToNumberInRoulette[35] = 'b';
	colorToNumberInRoulette[3] = 'r';
	colorToNumberInRoulette[26] = 'b';
	colorToNumberInRoulette[0] = 'g';
	colorToNumberInRoulette[32] = 'r';
	colorToNumberInRoulette[15] = 'b';
	colorToNumberInRoulette[19] = 'r';
	colorToNumberInRoulette[4] = 'b';
	colorToNumberInRoulette[21] = 'r';
	colorToNumberInRoulette[2] = 'b';
	colorToNumberInRoulette[25] = 'r';
	colorToNumberInRoulette[17] = 'b';
	colorToNumberInRoulette[34] = 'r';
}

Application::Application()
{

	intro = NULL;
	for (unsigned int i = 0; i < INTRO_BUTTONS; i++)
	{
		introButtons[i] = NULL;
	}
	info = NULL;
	infoBackToIntro = NULL;
	gameBoard = NULL;
	roulette = NULL; // spin roulette
	ball = NULL;
	outro = NULL; // Animation who backs to Intro 10 sec;
	win = NULL; // anima
	cashOut = NULL;
	spin = NULL;

	for (unsigned int i = 0; i < POOLS_BUTTON; i++)
	{
		gameBoardPools[i] = NULL;
		betPools[i] = NULL;
	}

	for (unsigned int i = 0; i < COIN_COUNT; i++)
	{
		coin[i] = NULL;
	}
	FillTheMapsOfRoulette();

	creditsCollected = 0;
	numberOfSpins = 0;

	lastWiningNumbers.push(-1);

	click = new Sound;
	click->loadMedia("clickSound.wav");

	initIntro();
}

Application::~Application()
{
	delete click;

	for (unsigned int i = 0; i < 5; i++)
	{
		delete introButtons[i];
	}
	delete intro;

	Free();
}

void Application::initIntro()
{
	MenuState = INTRO_MENU;
	intro = new Background("INTROSCREEN", SCREEN_W, SCREEN_H,
			"IntroBackgroundFinal.bmp");
	for (int i = 0; i < INTRO_BUTTONS; i++)
	{
		introButtons[i] = new Button(SCREEN_W / 2 - 600 / 2,
				SCREEN_H / 13 - INTRO_BUTTON_H / 2 + i * (INTRO_BUTTON_H + 20));
		introButtons[i]->loadFromFile(Background::gRenderer, "1.png");
		introButtons[i]->setWidth(600);
		introButtons[i]->setHeight(50);
		SDL_Rect rectButton = { 0, 0, 1000, 300 };
//		introButtons[i]->render(Background::gRenderer, &rectButton, 0, 500, 50);
//		Text text(SCREEN_W / 2 - 500 / 2 + 50,
//				SCREEN_H / 10 - INTRO_BUTTON_H / 2 + i * (INTRO_BUTTON_H + 10)
//						+ 5, 400, 30, 20, introButtonText[i],
//				{ 100, 200, 100 });
	}

}

void Application::initInfo()
{
	MenuState = INFO;
	info = new Background("INFOSCREEN", SCREEN_W, SCREEN_H,
			"rouletterules.jpg");
	infoBackToIntro = new Button(10, 10);
	infoBackToIntro->loadFromFile(Background::gRenderer, "BackButton.png");
	infoBackToIntro->setHeight(INTRO_BUTTON_H);
	infoBackToIntro->setWidth(INTRO_BUTTON_W);
	infoBackToIntro->render(Background::gRenderer, NULL);

	Text textDenomination(SCREEN_W * 3 / 5, SCREEN_H - 30, 150, 15, 20,
			"*DENOMINATION IS 0.01", { 30, 30, 30, 255 });
}

void Application::initGameBoard()
{
	MenuState = GAME_BOARD;
//display background
	gameBoard = new Background("GameBoard", SCREEN_BOARD_W, SCREEN_BOARD_H,
			"EuropeanRouletteFinal.bmp");

	Text textCash(SCREEN_BOARD_W / 5, 40, 50, 35, 15,
			credits.GetCredit() * DENOMINATION, { 200, 200, 200, 255 });

	Text textBet(SCREEN_BOARD_W / 2 - 20, 40, 50, 35, 15, credits.GetBet(),
			{ 200, 200, 200, 255 });

	if (lastWiningNumbers.back() != -1)
		Text textWin(SCREEN_BOARD_W * 4 / 5, 40, 50, 35, 15,
				lastWiningNumbers.back(), { 200,
						200, 200, 255 });
	else
		Text textWin(SCREEN_BOARD_W * 4 / 5, 40, 100, 35, 15,
				"no spins yet", { 200,
						200, 200, 255 });

//display cashout button
	cashOut = new Button(SCREEN_BOARD_W - BUTTON_W - 130, 73);
	cashOut->loadFromFile(Background::gRenderer, "Cash OUT.png");
	cashOut->setWidth(215);
	cashOut->setHeight(135);
//	cashOut->render(Background::gRenderer, NULL);

//this will be spin button need picture ;
	spin = new Button(SCREEN_BOARD_W - BUTTON_W - 58, SCREEN_BOARD_H - 105);
	spin->loadFromFile(Background::gRenderer, "Cash OUT.png");
	spin->setWidth(213);
	spin->setHeight(125);
//	spin->render(Background::gRenderer, NULL);

	history = new Button(SCREEN_BOARD_W - BUTTON_W - 130 - 377, 73);
	history->loadFromFile(Background::gRenderer, "Cash OUT.png");
	history->setWidth(215);
	history->setHeight(135);
//	history->render(Background::gRenderer, NULL);

	accounting = new Button(SCREEN_BOARD_W - BUTTON_W - 130 - 755, 73);
	accounting->loadFromFile(Background::gRenderer, "Cash OUT.png");
	accounting->setWidth(210);
	accounting->setHeight(132);
//	accounting->render(Background::gRenderer, NULL);

	clearBets = new Button(38, SCREEN_BOARD_H - 105);
	clearBets->loadFromFile(Background::gRenderer, "Cash OUT.png");
	clearBets->setWidth(213);
	clearBets->setHeight(125);
//	clearBets->render(Background::gRenderer, NULL);

//draw 5 Pulls and PICK PICK >>>>!!!!!!
	for (int i = 0; i < POOLS_BUTTON; i++)
	{
		Credits cr;
		gameBoardPools[i] = new Pools(cr, 113 * i + SCREEN_BOARD_W - 865,
				SCREEN_BOARD_H - 90);
		gameBoardPools[i]->loadFromFile(Background::gRenderer, "Pools.png");
		gameBoardPools[i]->setHeight(2 * PULLS_W);
		gameBoardPools[i]->setWidth(2 * PULLS_H);
//		SDL_Rect rectButton = { 113 * i + 3, 1, 118, 111 };
//		gameBoardPools[i]->render(Background::gRenderer, &rectButton);
	}

}

void Application::initBonus()
{
	MenuState = BONUS;
	bonus = new Background("Mystery Jackpot !", SCREEN_BONUS_W, SCREEN_BONUS_H,
			"Lucky.jpg");

	Text textYouWin(SCREEN_BONUS_W / 4, SCREEN_BONUS_H / 4, SCREEN_BONUS_W / 2,
			SCREEN_BONUS_H / 8, 20,
			"You Win", { 100, 250, 0 });

	Text textWinnings(SCREEN_BONUS_W / 3, SCREEN_BONUS_H * 2 / 4,
			SCREEN_BONUS_W / 3,
			SCREEN_BONUS_H / 8, 20, creditsCollected, { 0, 250, 100 });

	Text textCredits(SCREEN_BONUS_W / 4, SCREEN_BONUS_H * 3 / 4,
			SCREEN_BONUS_W / 2, SCREEN_BONUS_H / 8,
			20, "credits", { 100, 250, 0 });

}

void Application::initOutro()
{
	MenuState = OUTRO;
	outro = new Background("Outro", SCREEN_W, SCREEN_H, "OutroScreen2.jpg");

	double scale = 0.6;

	Text textThankYou(SCREEN_W / 8 * scale, 30 * scale, 900 * scale,
			200 * scale, 20,
			"THANK YOU FOR PLAYING", { 0, 200, 0, 155 });
	Text textYouHave(SCREEN_W / 8 * scale, 400 * scale, 500 * scale,
			200 * scale, 15,
			"You have", //{ 80, 80, 120, 255 });
			{ 255, 255, 255 });
	Text textMoneyNumber((SCREEN_W / 8 + 520) * scale, 400 * scale, 180 * scale,
			200 * scale, 15,
			credits.GetCredit() * DENOMINATION, { 200, 10, 10, 255 });
	Text textMoney((SCREEN_W / 8 + 520 + 180) * scale, 400 * scale, 220 * scale,
			200 * scale, 15,
			"BGN", // { 80, 80, 160, 255 });
			{ 255, 255, 255 });

}

void Application::initWin()
{
	MenuState = WIN;
	win = new Background("Win", SCREEN_ROULETTE_W, SCREEN_ROULETTE_H,
			"CoinBag.png");
	for (int i = 0; i < COIN_COUNT; i++)
	{
		coin[i] = new LTexture(rand() % 200 + 100, rand() % SCREEN_ROULETTE_W);
		coin[i]->loadFromFile(Background::gRenderer, "coin.png");
		coin[i]->setWidth(COIN_W);
		coin[i]->setHeight(COIN_H);
	}
	WinAnimation();
}

void Application::initSpin()
{
	MenuState = SPIN;
	roulette = new Background("spin", SCREEN_ROULETTE_W, SCREEN_ROULETTE_H,
			"RouletteBoard.png");
	wheel = new LTexture(120, 120);
	wheel->loadFromFile(Background::gRenderer, "wheel2.png");
	wheel->setWidth(560);
	wheel->setHeight(560);
	wheel->render(Background::gRenderer, NULL, 0);
	ball = new Button(SCREEN_ROULETTE_W, SCREEN_ROULETTE_H);
	ball->loadFromFile(Background::gRenderer, "BALL.png");
	ball->setWidth(BALL_W);
	ball->setHeight(BALL_H);
//ball->render(Background::gRenderer, NULL);
}

//return the number of cell
//cells: From 0 to 39
// cell[i] = 0 (if i==13);
// cell[i] = 3*i (if i/13==0, i!= 0);
// cell[i] = 3*(i-13)-1 (if i/13==1, i!=13);
// cell[i] = 3*(i-26)-2 (if i/13==2, i!=26);
//get parameters: positionX, positionY
int Application::CalcQuadrandClicked(int x, int y)
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

	cout << "clickedCell:" << clickedCell << endl;
	return clickedCell;
}

void Application::DisplayBets(int x, int y, int color,
								vector<Point> v_allBetPoints)
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
					coordY = 285 + (i / 13) * 77;
				}
			}

			//separate logic for Even, Red, Black, Odd (Cell with numbers: 40,41,42,43)

			for (int i = 39; i <= 43; i++)

				if (clickedCell == i)
				{

					//start from x=350, step = 150, i-40 used to get sequence 0,1,2,3
					coordX = 350 + (150 * (i - 39));
					coordY = 590;

				}

			//TODO add logic for 40,41,42,43
			//Viktor TODO: later in function below to be added logic for : red,black, event, odd

			if (coordX != -1 && coordY != -1)
			{
				if (credits.GetCredit() >= value[j])	//credits logic
				{
					credits.AddBet(value[j]);
					credits.ChangeCredits(-value[j]);
//					credits.betByNumberCell[Credits::NumberInCell(clickedCell)] +=
//							value[j];

					Credits cr(value[j]);
					Pools gameBoardPools(cr, coordX, coordY);
					gameBoardPools.loadFromFile(Background::gRenderer,
							"Pools.png");
					gameBoardPools.setWidth(PULLS_W);
					gameBoardPools.setHeight(PULLS_H);
//					cout << x << ":" << y << endl;
					SDL_Rect rec =
							{ j * 112 + 3, 1, 112, 111 };
					gameBoardPools.render(Background::gRenderer, &rec);

					//while piece to write on
					LTexture overPullUnderText(coordX + 20, coordY + 20);
					overPullUnderText.loadFromFile(Background::gRenderer,
							"BALL.png");
					overPullUnderText.setWidth(PULLS_W / 3);
					overPullUnderText.setHeight(PULLS_H / 3);
					overPullUnderText.render(Background::gRenderer, NULL);

					Text textInPool(coordX + 20, coordY + 20, PULLS_W / 3,
							PULLS_H / 3, 20,
							credits.betByNumberCell[	//Credits::NumberInCell(
							clickedCell] +=
									value[j]
									, { 0, 0, 0, 255 });

					//Open existing XML and append into it for each bet
					//read from
					appendToXML(credits.betByNumberCell);

					Point p(x, y, colors[j], value[j]);
					v_allBetPoints.push_back(p);
				}					//end credits
			}
		}					//end if and for

	if (MenuState == GAME_BOARD)
	{
		LTexture underTextLayer(SCREEN_BOARD_W / 2 - 20, 40);
		underTextLayer.loadFromFile(Background::gRenderer,
				"EuropeanRouletteFinalGreen.bmp", 0, 0);
		underTextLayer.setWidth(50);
		underTextLayer.setHeight(35);
		underTextLayer.render(Background::gRenderer, NULL);

		Text textBet(SCREEN_BOARD_W / 2 - 20, 40, 50, 35, 15, credits.GetBet(),
				{ 200, 200, 200, 255 });
	}

}

bool Application::WinAnimation()

{
	bool isDone = false;
	short int timeout = 6000;
	vector<SDL_Rect> goldCoins;
	for (int i = 0; i < 10; i++)
		goldCoins.push_back(
				{ COIN_W * i, 0, COIN_W, COIN_H });

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
	{

		for (int i = 0; i < COIN_COUNT; i++)
		{
			coin[i]->setX(rand() % 350 + 140);
			coin[i]->setY(rand() % 110 + 20);

			for (int j = 0; j < 10; j++)
			{
				coin[i]->render(Background::gRenderer, &goldCoins[j]);
				SDL_Delay(10);
			}
			SDL_Delay(60);
			isDone = true;
		}
	}
	return isDone;
}

int Application::spinBall()
{
	srand(time(NULL));
	int result = rand() % 37;

	if (lastWiningNumbers.size() >= 18)
		lastWiningNumbers.pop();
	lastWiningNumbers.push(result);

	appendToXMLHistory(lastWiningNumbers);

	cout << result << endl;

	double angleBall = -0.03
			+ 0.168 * (posissionToNumberInRoulette[result] - 13);
	double angleWheel = 0; //2 * M_PI * result / 37;

	double radius = 330;
	const double minRaduis = 210;
	double andleEnd = 82 * M_PI;
	double stepBall = M_PI / 36;
	double stepWheel = 0.2;

	bool isTimeToDraw = false;
	bool isTimeToDraw2 = true;

	do
	{
		const double MAGIC_NUMBER = 0.08;

		SDL_Delay(3);

		isTimeToDraw = !isTimeToDraw;
		if (isTimeToDraw)
			isTimeToDraw2 = !isTimeToDraw2;
		if (isTimeToDraw && isTimeToDraw2)
		{
//			isTimeToDraw2 = !isTimeToDraw2;
			roulette->Show();
			wheel->render(Background::gRenderer, NULL, -angleWheel);
		}

		ball->setX(
				SCREEN_ROULETTE_W / 2 - BALL_W / 2 + cos(angleBall) * radius);
		ball->setY(
				SCREEN_ROULETTE_H / 2 - BALL_H / 2 + sin(angleBall) * radius);

		ball->render(Background::gRenderer, NULL, 0);
		angleWheel += stepWheel;
		if (angleWheel < andleEnd)
			angleBall += stepBall - MAGIC_NUMBER * (minRaduis / radius);
		else
			angleBall -= M_PI / 900;
		radius -= 0.1;
	}
	while (angleWheel < andleEnd + 10 * M_PI);



//	while (radius > minRaduis);

//	delete wheel;
//	wheel = new LTexture(SCREEN_ROULETTE_W, SCREEN_ROULETTE_H);
//	wheel->loadFromFile(Background::gRenderer, "wheel2.png");

//	wheel->setWidth(640);
//	wheel->setHeight(640);
//	wheel->render(Background::gRenderer, NULL, result * 2 * M_PI / 37);
	SDL_Delay(4000);

	return 5; //result;
}

void Application::GamePlay()
{
	bool close = false;

	vector<Point> v_pointsBetInfo;

	while (!close)
	{

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{

			switch (MenuState)
			{
			case INTRO_MENU:
				if (introButtons[0]->isClicked(&e))
				{
					//					click->Play();
					Free();
					MenuState = INFO;
					initInfo();
				}
				if (introButtons[1]->isClicked(&e))
				{
					//					click->Play();
					credits.ChangeCredits(ADD_CREDIT_BUTTON_VALUE);
					intro->Show();
					if (credits.GetCredit())
					{
						Text textCredit(SCREEN_W / 2 - 500 / 2 + 50 + 470,
								SCREEN_H / 10 - INTRO_BUTTON_H / 2
										+ (INTRO_BUTTON_H + 10)
										, 230, 40, 20, "Credits: ", { 100,
										200, 100, 255 });

						Text textCreditsNumber(
								SCREEN_W / 2 - 500 / 2 + 50 + 690,
								SCREEN_H / 10 - INTRO_BUTTON_H / 2
										+ (INTRO_BUTTON_H + 10)
										, 60, 40, 20, credits.GetCredit(),
								{ 100, 200, 100 });
					}
				}
				if (introButtons[1]->isRightClicked(&e) && credits.GetCredit())
				{
					credits.ChangeCredits(-ADD_CREDIT_BUTTON_VALUE);
					intro->Show();
					if (credits.GetCredit())
					{
						Text textCredit(SCREEN_W / 2 - 500 / 2 + 50 + 470,
								SCREEN_H / 10 - INTRO_BUTTON_H / 2
										+ (INTRO_BUTTON_H + 10)
										, 230, 40, 20, "Credits: ", { 100,
										200, 100, 255 });

						Text textCreditsNumber(
								SCREEN_W / 2 - 500 / 2 + 50 + 690,
								SCREEN_H / 10 - INTRO_BUTTON_H / 2
										+ (INTRO_BUTTON_H + 10)
										, 60, 40, 20, credits.GetCredit(),
								{ 100, 200, 100 });
					}
				}
				if (introButtons[3]->isClicked(&e) && credits.GetCredit() > 0)
				{
					//					click->Play();
					Free();
					MenuState = GAME_BOARD;
					initGameBoard();
				}
				break;
			case INFO:
				if (infoBackToIntro->isClicked(&e))
				{
					//					click->Play();
					Free();
					MenuState = INTRO_MENU;
					initIntro();
				}
				break;
			case GAME_BOARD:

				if (cashOut->isClicked(&e))
				{
					//					click->Play();
					credits.ChangeCredits(credits.GetBet());

					Free();
					initOutro();

					for (map<int, int>::iterator i =
							credits.betByNumberCell.begin();
							i != credits.betByNumberCell.end(); i++)
						i->second = 0;
					credits.ChangeCredits(-credits.GetCredit());
					credits.SetBet(0);

					appendToXML(credits.betByNumberCell);

					SDL_Delay(10000);
					Free();
					initIntro();
				}

				if (clearBets->isClicked(&e))
				{

					  //start test function readXMLWriteMap
					  //create map m_FromXmlRead
					  //map m_FromXmlRead  is populated with returned map from function readXMLWriteMap()
					  //below just for test: iterate over map and count its content
					  map<int, int> m_FromXmlRead   = readXMLWriteMap("roulette_recovery.xml");
					  for(map<int,int>::iterator it = m_FromXmlRead.begin(); it != m_FromXmlRead.end(); it++ )
					  {
						  cout << "Read From xmlMap:  " << it->first << ":" << it->second << endl;
					  }
					  //end test function readXMLWriteMap


					//					click->Play();
					for (map<int, int>::iterator i =
							credits.betByNumberCell.begin();
							i != credits.betByNumberCell.end(); i++)
						i->second = 0;
					credits.ChangeCredits(credits.GetBet());
					credits.SetBet(0);
					gameBoard->Show();

					Text textCash(SCREEN_BOARD_W / 5, 40, 50, 35, 15,
							credits.GetCredit() * DENOMINATION, { 200, 200, 200,
									255 });

					Text textBet(SCREEN_BOARD_W / 2 - 20, 40, 50, 35, 15,
							credits.GetBet(),
							{ 200, 200, 200, 255 });

					if (lastWiningNumbers.back() != -1)
						Text textWin(SCREEN_BOARD_W * 4 / 5, 40, 50, 35, 15,
								lastWiningNumbers.back(), { 200,
										200, 200, 255 });
					else
						Text textWin(SCREEN_BOARD_W * 4 / 5, 40, 100, 35, 15,
								"no spins yet", { 200,
										200, 200, 255 });

				}

				//TODO: here we are more than 10 times in a second. to be fixed
				int x, y;
				int color;

				for (int i = 0; i < POOLS_BUTTON; i++)
					if (gameBoardPools[i]->isClicked(&e))
					{
						//					click->Play();
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

						DisplayBets(x, y, color, v_pointsBetInfo);
					}
				}

				if (spin->isClicked(&e))
				{
					//					click->Play();
					creditsCollected += credits.GetBet() * 0.13;
					numberOfSpins++;
					if (!(numberOfSpins % 3)) // should be in N spins activated
					{
						credits.AddBet(creditsCollected);
						creditsCollected = 0;

						Free();
						initBonus();

						SDL_Delay(3000);

					}
					Free();
					initSpin();
				}
//				if (cashOut->isClicked(&e))
//				{
//					//					click->Play();
//					Free();
//					initOutro();
//					SDL_Delay(10000);
//					Free();
//					initIntro();
//				}

				if (history->isClicked(&e))
				{
					for (map<int, int>::iterator i =
							credits.betByNumberCell.begin();
							i != credits.betByNumberCell.end(); i++)
						cout << i->first << "	" << i->second << endl;
				}

				break;

			case SPIN:
				{
				int roulletteWinningNumber = spinBall();
				cout << "credits.betByNumberCell[roulletteWinningNumber] = "
						<< credits.betByNumberCell[NumberInCell(
								roulletteWinningNumber)]
						<< endl;
				int winProfit = credits.betByNumberCell[NumberInCell(
						roulletteWinningNumber)]
						* MULTIPLIER_NUMBER;
				if (roulletteWinningNumber != 0)
				{
					if (roulletteWinningNumber % 2)
						winProfit += credits.betByNumberCell[42]
								* MULTIPLIER_PARITY;
					else
						winProfit += credits.betByNumberCell[39]
								* MULTIPLIER_PARITY;
					if (colorToNumberInRoulette[roulletteWinningNumber] == 'b')
						winProfit += credits.betByNumberCell[41]
								* MULTIPLIER_COLOR;
					else
						winProfit += credits.betByNumberCell[40]
								* MULTIPLIER_COLOR;
				}
				credits.ChangeCredits(winProfit);
				for (int i = 0; i < NUMBER_OF_SECTORS + 2 + 4; i++)
					credits.betByNumberCell[i] = 0;

				cout << "Winning number is " << roulletteWinningNumber << endl
						<< "You win: " << winProfit << endl
						<< "And you bet: " << credits.GetBet() << endl;

				if (winProfit > credits.GetBet())
				{
					Free();
					initWin();
				}
				credits.SetBet(0);

				Free();
				initGameBoard();

				cout << "You have " << credits.GetCredit() << " credits left"
						<< endl << endl;

				break;
			}
			default:
				break;
			}

			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_SPACE)
			{
				close = true;
			}

		}

		//separate function that traverse vector with Bets and display polls

	}

}

void Application::Free()
{
	if (MenuState == INTRO_MENU)
	{
		intro->Clear();
		for (int i = 0; i < INTRO_BUTTONS; i++)
			introButtons[i]->free();
	}
	if (MenuState == INFO)
	{
		info->Clear();
		infoBackToIntro->free();
	}
	if (MenuState == GAME_BOARD)
	{
		gameBoard->Clear();
		for (int i = 0; i < POOLS_BUTTON; i++)
		{
//			betPools[i]->free();
			gameBoardPools[i]->free();
		}
		cashOut->free();
		spin->free();
		history->free();
		accounting->free();
		clearBets->free();
	}
	if (MenuState == WIN)
	{
		win->Clear();
		for (int i = 0; i < COIN_COUNT; i++)
		{
			coin[i]->free();
		}
	}
	if (MenuState == SPIN)
	{
		roulette->Clear();
		wheel->free();
		ball->free();
	}
	if (MenuState == BONUS)
	{
		bonus->Clear();
	}
	if (MenuState == OUTRO)
	{
		outro->Clear();
	}
	SDL_RenderClear(Background::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Background::gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

void Application::appendToXML(map<int, int> betByNumberCell)
{
	string XML_FILE_PATH = "roulette_recovery.xml";
	pugi::xml_document doc;
	doc.load_file(XML_FILE_PATH.c_str(),
			pugi::parse_default | pugi::parse_declaration);
	doc.reset(doc);
	map<int, int>::iterator itr;
	for (itr = betByNumberCell.begin(); itr != betByNumberCell.end(); itr++)
	{
//		cout << "Bet: " << itr->first << " : " << itr->second << endl;

		pugi::xml_node doc_attr = doc.append_child("Bet");
		pugi::xml_attribute attr_cell = doc_attr.append_attribute("cell") =
				itr->first;
		pugi::xml_attribute attr_BetAmount =
				doc_attr.append_attribute("amount") = itr->second;
	}

	doc.save_file("roulette_recovery.xml");

}


void Application::appendToXMLHistory(queue<int> lastWinningNumbers)
{
	string XML_FILE_PATH = "roulette_history.xml";
	pugi::xml_document doc;
	doc.load_file(XML_FILE_PATH.c_str(),
			pugi::parse_default | pugi::parse_declaration);
	doc.reset(doc);
	while(lastWinningNumbers.size() != 0)
	{

		cout << " " << lastWinningNumbers.front();

		pugi::xml_node doc_attr = doc.append_child("Number");
		pugi::xml_attribute attr_cell = doc_attr.append_attribute("cell") =
				lastWinningNumbers.front();

		lastWinningNumbers.pop();
	}

	doc.save_file("roulette_history.xml");
}


map<int, int> Application::readXMLWriteMap(string pathXml)
{

	//map populated from XML
	map<int, int> m_XMLOutput;

	pugi::xml_document doc;
	if(!doc.load_file(pathXml.c_str()))
	{
		cerr << "file could not be read" ;
	}

	for(pugi::xml_node bet = doc.child("Bet");bet ; bet= bet.next_sibling("Bet"))
	{
		m_XMLOutput[ bet.attribute("cell").as_int() ] = bet.attribute("amount").as_int();
	}

	return m_XMLOutput;
}
