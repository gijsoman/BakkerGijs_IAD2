#pragma once

#include "ofMain.h"

class BounceObject
{
public:
	BounceObject();


	void setup();
	void draw();
	void update(int Xspeed, int Yspeed);

	int radius;
	ofPoint position;
	ofVec2f speed;
	ofColor color;

};

