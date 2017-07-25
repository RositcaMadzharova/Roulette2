/*
 * AccountingScreen.cpp
 *
 *  Created on: Jul 25, 2017
 *      Author: kakev
 */

#include "AccountingScreen.h"

AccountingScreen::AccountingScreen() : Screen()
{
	background->loadFromFile("EuropeanRouletteAccounting.png");
	background->setWidth(SCREEN_W);
	background->setHeight(SCREEN_H);
}

AccountingScreen::~AccountingScreen()
{

}

bool AccountingScreen::Draw()
{
	if(background->render(NULL,0,NULL))
	{
		accountingMap = readXMLWriteMap("recovery_accounting.xml");
		//TODO TEXT TEXT TEXT !!!!!
		return true;
	}
return false;
}

bool AccountingScreen::Clear()
{
	SDL_RenderClear(LWindow::gRenderer);
	isActive = false;
	return true;
}

map<int, int> AccountingScreen::readXMLWriteMap(string pathXml)
{
	//map populated from XML
		map<int, int> m_XMLOutput;

		pugi::xml_document doc;
		if (!doc.load_file(pathXml.c_str()))
		{
			cerr << "file could not be read";
		}

		for (pugi::xml_node bet = doc.child("Bet"); bet;
				bet = bet.next_sibling("Bet"))
		{
			m_XMLOutput[bet.attribute("cell").as_int()] =
					bet.attribute("amount").as_int();
		}

		return m_XMLOutput;
}
