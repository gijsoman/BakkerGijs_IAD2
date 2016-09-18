#pragma once

#include "ofMain.h"

class Ball
{
public:
	Ball();
	
	void Setup();
	void Update();
	void Draw();
	
	static const int AANTALBALLEN = 100;

	int pulsedout[AANTALBALLEN];

	int x[AANTALBALLEN];
	int y[AANTALBALLEN];
	int speedX[AANTALBALLEN];
	int speedY[AANTALBALLEN];
	int radius[AANTALBALLEN];
	ofColor colors[AANTALBALLEN];

	
 
};

