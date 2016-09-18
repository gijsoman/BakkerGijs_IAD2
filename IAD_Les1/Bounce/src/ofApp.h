#pragma once

#include "ofMain.h"

//we first define the number of balls 
//this can be easily changed to add more balls.
#define AANTALBALLEN 100

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();


private:
	//we add some variables for the first position of the balls.
	//also we have some variables for the speed, radius and color.
	//the array size gets defined by the amount of balls.
	int x[AANTALBALLEN];
	int y[AANTALBALLEN];
	int speedX[AANTALBALLEN];
	int speedY[AANTALBALLEN];
	int radius[AANTALBALLEN];
	ofColor colors[AANTALBALLEN];
};
