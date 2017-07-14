/*
 * RouletteWheel.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: kakev
 */

#include "RouletteWheel.h"

RouletteWheel::RouletteWheel(int _x, int _y, double angleSpeed)
		: LTexture(x, y)
{
	_angleSpeed = angleSpeed;
	isFinish = false;

}

RouletteWheel::~RouletteWheel()
{
}

void RouletteWheel::Spin()
{
//srand (time(0));
	map<int, double>::iterator it = wheelSectors.begin();

	for (int i = 0; i < 37; i++)
	{
		//9.7 angle 360 / sectors
		wheelSectors[i] = i * 9.7;
	}
	for (it = wheelSectors.begin(); it != wheelSectors.end(); ++it)
		std::cout << it->first << " => " << it->second << endl;

}

