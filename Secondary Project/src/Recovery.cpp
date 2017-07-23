/*
 * Recovery.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#include "Recovery.h"

Recovery::Recovery()
{
	lastWiningNumbers.push(-1);
	creditsBet = 0;
	creditsWon = 0;
}

Recovery::~Recovery()
{

}

void Recovery::appendToXML(map<int, int> betByNumberCell, int credits,
								int bet)
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
		pugi::xml_attribute attr_cell;
		attr_cell = doc_attr.append_attribute("cell") =
				itr->first;
		pugi::xml_attribute attr_BetAmount;
		attr_BetAmount = doc_attr.append_attribute("amount") = itr->second;
	}

	pugi::xml_node doc_attr = doc.append_child("Credits");
	pugi::xml_attribute attr_c_cell;
	attr_c_cell = doc_attr.append_attribute("currentCredit") = credits;
	pugi::xml_attribute attr_b_cell;
	attr_b_cell = doc_attr.append_attribute("betCredit") = bet;

	doc.save_file("roulette_recovery.xml");

}

void Recovery::appendToXMLHistory(queue<int> lastWinningNumbers)
{
	string XML_FILE_PATH = "roulette_history.xml";
	pugi::xml_document doc;
	doc.load_file(XML_FILE_PATH.c_str(),
			pugi::parse_default | pugi::parse_declaration);
	doc.reset(doc);
	while (lastWinningNumbers.size() != 0)
	{

		cout << " " << lastWinningNumbers.front();

		pugi::xml_node doc_attr;
		doc_attr = doc.append_child("Number");
		pugi::xml_attribute attr_cell;
		attr_cell = doc_attr.append_attribute("cell") =
				lastWinningNumbers.front();

		lastWinningNumbers.pop();
	}

	doc.save_file("roulette_history.xml");
}

map<int, int> Recovery::readXMLWriteMap(string pathXml)
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

int Recovery::readXMLWriteCurrentCredit(string pathXml)
{
	int currentCredits = 0;

	pugi::xml_document doc;
	if (!doc.load_file(pathXml.c_str()))
	{
		cerr << "file could not be read";
	}
	pugi::xml_node bet = doc.child("Credits");
	currentCredits = bet.attribute("currentCredits").as_int();

	return currentCredits;
}

int Recovery::readXMLWriteBetCredits(string pathXml)
{
	int betCredits = 0;

	pugi::xml_document doc;
	if (!doc.load_file(pathXml.c_str()))
	{
		cerr << "file could not be read";
	}
	pugi::xml_node bet = doc.child("Credits");
	betCredits = bet.attribute("currentCredits").as_int();

	return betCredits;
}

queue<int> Recovery::readXMLWriteQueue(string pathXml)
{
	queue<int> q_XMLOutput;
	pugi::xml_document doc;
	if (!doc.load_file(pathXml.c_str()))
	{
		cerr << "File could not be read";
	}

	for (pugi::xml_node bet = doc.child("Bet"); bet;
			bet = bet.next_sibling("Bet"))
	{
		q_XMLOutput.push(bet.attribute("cell").as_int());
	}
	return q_XMLOutput;
}
