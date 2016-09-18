#include "Ball.h"



Ball::Ball()
{
}

void Ball::setup()
{
	//set all the variables.
	x = ofRandom(0, ofGetScreenWidth());
	y = ofRandom(0, ofGetScreenHeight());
	xSpeed = ofRandom(-5, 5);
	ySpeed = ofRandom(-5, 5);
	pulsingSpeed = ofRandom(1, 5);
	if (xSpeed == 0)
	{
		xSpeed = ofRandom(1, 5);
	}
	if (ySpeed == 0)
	{
		ySpeed = ofRandom(1, 5);
	}
	radius = ofRandom(0, 5);
	kleur = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	pulsedout = false;
}

void Ball::update()
{
	//this is were we update the positions of all the balls with our speed variables.
	//this is also were we make sure the balls dont leave the screen.
	if (x <= 0) {
		x = 0;
		xSpeed = -xSpeed;
	}
	else if (x >= ofGetWidth()) {
		x = ofGetWidth();
		xSpeed = -xSpeed;
	}

	if (y <= 0) {
		y = 0;
		ySpeed = -ySpeed;
	}
	else if (y >= ofGetHeight()) {
		y = ofGetHeight();
		ySpeed = -ySpeed;
	}

	x += xSpeed;
	y += ySpeed;

	//Code for pulsating a ball
	if (radius < 50 && !pulsedout)
	{
		radius += pulsingSpeed;
	}
	else if (radius >= 50)
	{
		pulsedout = true;
	}

	if (pulsedout)
	{
		radius -= pulsingSpeed;
		if (radius <= 0)
		{
			pulsedout = 0;
		}
	}
}
void Ball::draw()
{
	ofSetColor(kleur);
	ofDrawCircle(x, y, radius);
}