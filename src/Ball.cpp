/*
 * Ball.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: kakev
 */

#include "Ball.h"

Ball::Ball(int _x ,int _y , int _speed) :LTexture(x,y)
{
	this->speed=_speed;
	isStoped=false;

}

Ball::~Ball()
{

}

bool Ball::spin()
{
		double angleBall = 0;
		double maxR = 330;
		double minR=200;
		double currentR=maxR;
		double maxAngle = 10;

		double step = M_PI / 36; //128 steps per full circle, so lines are short.
		do
		{
			SDL_Delay(3);
			if(speed!=0){

			}if (isStoped) {
				angleBall -= speed / (360.0 / M_PI);
			} else {
				angleBall -= (maxR-currentR) / (12 * 200.0 / M_PI);
				if (angleBall < maxAngle) {
					currentR -= (maxR - minR) / ( 10* 200.0 / M_PI);
				}
				if (currentR < minR) {
					isStoped = true;
				}
			}
				angleBall -= step;

			LTexture::setX(SCREEN_ROULETTE_W / 2 - BALL_W / 2 + cos(angleBall) * maxR);
			LTexture::setY(SCREEN_ROULETTE_H / 2 - BALL_H / 2 + sin(angleBall) * maxR);
			cout<<"ltexture x"<<LTexture::getX()<<endl;
			cout<<"ltexture y"<<LTexture::getY()<<endl;


			LTexture::render(Background::gRenderer, NULL, 0);

			speed--;

			maxR -= 0.1;

		}
		while (angleBall < maxAngle);
return isStoped;
}

int Ball::getSpeed() const {
	return speed;
}

void Ball::setSpeed(int speed) {
	this->speed = speed;
}
