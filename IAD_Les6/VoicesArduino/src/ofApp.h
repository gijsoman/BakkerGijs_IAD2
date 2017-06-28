#pragma once

#include "ofMain.h"

#define VOICES 6

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofSoundPlayer voicePlayer[VOICES];

	//zonder deze bools werkte het op pauze zetten niet.
	bool voice1;
	bool voice2;
	bool voice3;
	bool voice4;
	bool voice5;
	bool voice6;


	ofArduino arduino;
	void setupArduino(const int& version);
	void analogPinChanged(const int & pin);

	float Speed;
};
