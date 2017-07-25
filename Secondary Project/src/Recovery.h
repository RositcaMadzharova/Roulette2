/*
 * Recovery.h
 *
 *  Created on: Jul 23, 2017
 *      Author: kakev
 */

#ifndef RECOVERY_H_
#define RECOVERY_H_
#include "pugixml.hpp"
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Recovery
{
public:
	Recovery();
	virtual ~Recovery();

	void appendToXML(map<int, int>, int, int); //bets
	void appendToXMLHistory(queue<int>); //history

	map<int, int> readXMLWriteMap(string pathXml);
	int readXMLWriteCurrentCredit(string pathXml);
	int readXMLWriteBetCredits(string pathXml);
	queue<int> readXMLWriteQueue(string pathXml);

	queue<int> lastWiningNumbers;

	//TODO: accounting
	map<int, int> winCreditsByNumber;
	int creditsBet;
	int creditsWon;
};

#endif /* RECOVERY_H_ */
