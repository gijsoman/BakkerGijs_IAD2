#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

        vector<Ball> balls;

		ofxPanel gui;
		ofParameter<int> radius;
		ofParameter<int> speedX;
		ofParameter<int> speedY;
		ofParameter<int> speedZ;
		ofParameter<ofColor> color;

		ofArduino arduino;
		void setupArduino(const int& version);
		void digitalPinChanged(const int& pin);
		void analogPinChanged(const int & pin);

		bool drawGrid;

		ofEasyCam cam;

};
