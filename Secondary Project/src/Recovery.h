/*
 * Recovery.h
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#ifndef RECOVERY_H_
#define RECOVERY_H_
#include "GLOBALS.h"
#include "pugixml.hpp"
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#include "Credits.h"

class Recovery
{
public:
	Recovery();
	virtual ~Recovery();

	void appendToXML(map<int, int>); //bets
	void appendToXMLCredits(int credits, int bet, int colected);
	void appendToXMLHistory(queue<int>); //history

	map<int, int> readXMLWriteMap(string pathXml);
	Credits readXMLWriteCredit(string pathXml);

	queue<int> readXMLWriteQueue(string pathXml);

public:
	queue<int> lastWiningNumbers;

	map<int, int> winCreditsByNumber;

	int currentCedits;
	int creditsBet;
	int creditsCollected;
};

#endif /* RECOVERY_H_ */
