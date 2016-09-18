#pragma once

#include "ofMain.h"

#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		//list of balls
		Ball* ballen = new Ball[AANTALBALLEN];		
};
