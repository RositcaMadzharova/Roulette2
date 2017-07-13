/*
 * Ball.h
 *
 *  Created on: Jul 13, 2017
 *      Author: kakev
 */

#ifndef BALL_H_
#define BALL_H_
#include "LTexture.h"

class Ball : public LTexture {
public:
	Ball(int _x,int _y ,int _speed);
	virtual ~Ball();
	bool spin();
	bool isBallStoped(){return isStoped;}

	int getSpeed() const;
	void setSpeed(int speed);

private :
	int speed;
	bool isStoped;
};

#endif /* BALL_H_ */

