#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
	private:

		//First we need some variables to set up our arduino
		ofArduino arduino;
		void setupArduino(const int& version);
		void digitalPinChanged(const int& pin);
		void analogPinChanged(const int & pin);

		//variables for pulsating
		int brightness = 0;
		int fadeAmount = 5;

		//we need a timer for pulsating. 
		float startTime;
		bool timerEnd;
		float endTime = 150;

		//we need a timer if the lights are off so we can keep it off for a while
		float startTimeOff;
		bool startTimeOffSet;
		float endOffTime = 3000;
		bool lightsOff;

		//we need a timer if the lights are maxed so we can keep them maxed for a while
		float startTimeMax;
		bool startTimeMaxSet;
		float endMaxTime = 1000;
		bool lightsMax;
		
		//We need music!! which you can start and stop
		ofSoundPlayer tones;

		//Toggle for stop and start
		bool spacePressed;
		
		//Audio speed
		float audioSpeed;
		
};
