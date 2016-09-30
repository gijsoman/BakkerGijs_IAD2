#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1

void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 10, 200));
	gui.add(speedX.set("SpeedX", 5, 5, 30));
	gui.add(speedY.set("SpeedY", 5, 5, 30));
	gui.add(color.set("Color", ofColor::blue));

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();
}

void ofApp::update() {
	arduino.update();
    for (unsigned int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

void ofApp::draw() {
    for (unsigned int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
	gui.draw();
}

void ofApp::keyPressed(int key)
{
	if (key == ' ')
	{
		if (balls.size() != 0)
		{
			balls.pop_back();
		}
	}
}

void ofApp::mousePressed(int x, int y, int button)
{
	if (button == 0)
	{
		Ball newBall;
		newBall.setup(speedX, speedY, radius, color);
		balls.push_back(newBall);
	}
}

void ofApp::setupArduino(const int& version)
{
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

	
}

void ofApp::digitalPinChanged(const int& pin)
{
	ofLog() << "Digitial Pin" << pin << " changed to " << arduino.getDigital(pin) << endl;
}

void ofApp::analogPinChanged(const int& pin)
{
	ofLog() << "Analog Pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
}