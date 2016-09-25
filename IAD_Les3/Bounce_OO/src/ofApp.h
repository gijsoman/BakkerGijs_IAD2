#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"

#define MAXBALLS 16

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

		void keyPressed(int key);

        Ball ball[MAXBALLS];

		ofxPanel gui;
		ofParameter<int> radius;
		ofParameter<int> xPos;
		ofParameter<int> yPos;

		int Walker = 0;

		void mousePressed(int x, int y, int button);
};
