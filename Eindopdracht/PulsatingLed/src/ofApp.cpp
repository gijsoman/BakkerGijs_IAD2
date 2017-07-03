#include "ofApp.h"

#define LED_PIN 9
#define LED_PIN2 10
#define POT_PIN 1

//--------------------------------------------------------------
void ofApp::setup(){
	//Here we setup the connection to our arduino
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();

	timerEnd = false;
	startTime = ofGetElapsedTimeMillis();

	// load audio track
	tones.loadSound("slaap.mp3");
	
}

//--------------------------------------------------------------
void ofApp::update(){
	//We want to update our arduino every tick
	arduino.update();
	

	//Set the audio speed and map it otherwise it becomes to fast.
	tones.setSpeed(ofMap(audioSpeed, 0, 1023, 0, 2));

	//so we can toggle the whole program
	if (spacePressed)
	{


		float timer = ofGetElapsedTimeMillis() - startTime;
		//cout << timer << endl;


		//if the lights are off we want to wait for a little while before we increase brightness again
		if (lightsOff)
		{
			if (!startTimeOffSet)
			{
				startTimeOffSet = true;
				startTimeOff = ofGetElapsedTimeMillis();
			}
			float offTimer = ofGetElapsedTimeMillis() - startTimeOff;
			//cout << offTimer << endl;
			if (offTimer >= endOffTime)
			{
				cout << "JAHOOR!" << endl;
				startTimeOff = ofGetElapsedTimeMillis();
				lightsOff = false;
				startTimeOffSet = false;
			}
		}

		//if the lights are on our MAX brightness we wait for a little while to decrease brightness again
		if (lightsMax)
		{
			if (!startTimeMaxSet)
			{
				startTimeMaxSet = true;
				startTimeMax = ofGetElapsedTimeMillis();
			}
			float maxTimer = ofGetElapsedTimeMillis() - startTimeMax;
			//cout << maxTimer << endl;
			if (maxTimer >= endMaxTime)
			{
				cout << "JAHOOR!" << endl;
				startTimeMax = ofGetElapsedTimeMillis();
				lightsMax = false;
				startTimeMaxSet = false;
			}
		}

		//we reset the timer if it exceeds our limit.
		if (timer >= endTime)
		{
			startTime = ofGetElapsedTimeMillis();
			timerEnd = true;
		}




		if (timerEnd && !lightsOff && !lightsMax)
		{
			//We have this very nice function to send pwm to a pwm port.
			arduino.sendPwm(LED_PIN, brightness);
			arduino.sendPwm(LED_PIN2, brightness);

			//Increase or decrease brightness every tick
			brightness = brightness + fadeAmount;


			//if the fadeAmount is highger than 255 we set the fadeAmount to negative so the brightness will be decreased
			if (brightness <= 0 || brightness >= 100)
			{
				if (brightness <= 0)
				{
					arduino.sendPwm(LED_PIN, brightness);
					arduino.sendPwm(LED_PIN2, brightness);
					lightsOff = true;
					cout << "Kom maar door" << endl;
				}
				if (brightness >= 100)
				{
					arduino.sendPwm(LED_PIN, brightness);
					arduino.sendPwm(LED_PIN2, brightness);
					lightsMax = true;
					cout << "YES" << endl;
				}

				fadeAmount = -fadeAmount;

			}


			timerEnd = false;
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ')
	{
		spacePressed = !spacePressed;
		if (tones.isPlaying())
		{
			tones.stop();
		}
		else
		{
			tones.play();
		}
	}
}

//this function sets up the arduino. you also set pins here.
void ofApp::setupArduino(const int& version)
{
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
	
	//we want to set the arduino pin to output
	arduino.sendDigitalPinMode(LED_PIN, ARD_PWM);
	arduino.sendDigitalPinMode(LED_PIN2, ARD_PWM);
	arduino.sendAnalogPinReporting(POT_PIN, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);


}

//this function is called if there is a change in value from the digital pin
void ofApp::digitalPinChanged(const int& pin)
{
	ofLog() << "Digitial Pin" << pin << " changed to " << arduino.getDigital(pin) << endl;
}

//this function is called if there is a change in value from the analog pin
void ofApp::analogPinChanged(const int& pin)
{
	cout << "Analog Pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
	audioSpeed = arduino.getAnalog(POT_PIN);
}
