/*
 * RouletteWheel.h
 *
 *  Created on: Jul 13, 2017
 *      Author: kakev
 */

#ifndef ROULETTEWHEEL_H_
#define ROULETTEWHEEL_H_
#include "LTexture.h"
#include "Background.h"
#include <map>
class RouletteWheel :public LTexture{
public:
	RouletteWheel(int _x,int _y,double angleSpeed);
	virtual ~RouletteWheel();
	void Spin();
private:
	double _angleSpeed;
	bool isFinish;
	map<int,double> wheelSectors;

};

#endif /* ROULETTEWHEEL_H_ */
