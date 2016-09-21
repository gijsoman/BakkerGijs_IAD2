#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofArduino arduino;

		void setupArduino(const int& version);
		void digitalPinChanged(const int& pinNum);
		void analogPinChanged(const int& pinNum);

		void keyPressed(int key);
		void keyReleased(int key);
		
};
