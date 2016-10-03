#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Planet.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofxPanel gui;
		ofParameterGroup params;

		ofEasyCam cam;
		ofLight light;

		bool drawGrid;
		bool drawLight;

		Planet planet01;
		Planet planet02;
};
