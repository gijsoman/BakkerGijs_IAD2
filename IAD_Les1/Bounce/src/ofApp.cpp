#include "ofApp.h"

void ofApp::setup() {
	//this is were we fill all our arrays with values.
	//most of them random
	for (int i = 0; i < AANTALBALLEN; i++)
	{
		x[i] = ofRandom(0, ofGetWidth());
		y[i] = ofRandom(0, ofGetWidth());
		speedX[i] = ofRandom(-5, 5);
		//this is a bug fix so no balls have a speed of 0
		if (speedX[i] == 0)
		{
			speedX[i] = 1;
		}
		speedY[i] = ofRandom(-5, 5);
		if (speedY[i] == 0)
		{
			speedY[i] = 1;
		}
		radius[i] = ofRandom(1, 150);
		colors[i] = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	}
}

void ofApp::update() {
	//this is were we update the positions of all the balls with our speed variables.
	//this is also were we make sure the balls dont leave the screen.
	for (int i = 0; i < AANTALBALLEN; i++)
	{
		if (x[i] <= 0) {
			x[i] = 0;
			speedX[i] = -speedX[i];
		}
		else if (x[i] >= ofGetWidth()) {
			x[i] = ofGetWidth();
			speedX[i] = -speedX[i];
		}

		if (y[i] <= 0) {
			y[i] = 0;
			speedY[i] = -speedY[i];
		}
		else if (y[i] >= ofGetHeight()) {
			y[i] = ofGetHeight();
			speedY[i] = -speedY[i];
		}

		x[i] += speedX[i];
		y[i] += speedY[i];
	}
}

void ofApp::draw() {
	//this is were we actually draw the balls and give them their color.
	for (int i = 0; i < AANTALBALLEN; i++)
	{
		ofSetColor(colors[i]);
		ofDrawCircle(x[i], y[i], radius[i]);
	}
}

//so the position is changed in the update function
//when the update function is done updating the positions we can draw them.

