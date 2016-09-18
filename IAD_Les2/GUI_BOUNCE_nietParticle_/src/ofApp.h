#pragma once

#include "ofMain.h"
#include "BounceObject.h"
#include "ofxGui.h"

#define AANTALBALLEN 100

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);

	void keyPressed(int key);
	BounceObject Balls[AANTALBALLEN];

		ofxPanel gui;
		ofParameter<int> count;
		ofParameter<float> speedX;
		ofParameter<float> speedY;

		int Walker = 0;
};
