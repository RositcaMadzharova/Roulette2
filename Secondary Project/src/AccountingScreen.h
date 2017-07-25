/*
 * AccountingScreen.h
 *
 *  Created on: Jul 25, 2017
 *      Author: kakev
 */

#ifndef ACCOUNTINGSCREEN_H_
#define ACCOUNTINGSCREEN_H_
#include "LTexture.h"
#include "Screen.h"
#include <map>
#include <string>
#include "pugixml.hpp"

class AccountingScreen : public Screen
{
public:
	AccountingScreen();
	virtual ~AccountingScreen();
	bool Draw();
	bool Clear();
	map<int, int> readXMLWriteMap(string pathXml);
private:
	map <int , int > accountingMap;

};

#endif /* ACCOUNTINGSCREEN_H_ */
