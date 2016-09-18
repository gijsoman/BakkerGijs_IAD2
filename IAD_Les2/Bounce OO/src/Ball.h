#pragma once
#define AANTALBALLEN 100
#include "ofMain.h"
class Ball
{
public:
	Ball();
	void setup();
	void update();
	void draw();

	int x;
	int y;
	int xSpeed;
	int ySpeed;
	float radius;
	float pulsingSpeed;
	ofColor kleur;

	bool pulsedout;

	

};

