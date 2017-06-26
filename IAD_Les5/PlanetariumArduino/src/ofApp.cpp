#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 2

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(ofColor::black);
	
	planet01.setup("planet 1");
	planet02.setup("planet 2");
	params.add(planet01.planetParameterGroup);
	params.add(planet02.planetParameterGroup);

	gui.setup(params);

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::white);
	light.enable();

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();

}

//--------------------------------------------------------------
void ofApp::update(){
	planet01.update();
	planet02.update();
	arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();

	ofEnableDepthTest();
	cam.begin();

	if (drawLight) light.draw();
	if (drawGrid) ofDrawGrid(200);

	ofPushMatrix();
	planet02.draw();
	ofPopMatrix();

	ofPushMatrix();
	planet01.draw();
	ofPopMatrix();

	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'g')
	{
		drawGrid = !drawGrid;
	}
	else if (key == 'l')
	{
		drawLight = !drawLight;
	}
	else if (key == 'k')
	{
	}
}

void ofApp::setupArduino(const int& version)
{
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);


	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);


}

void ofApp::analogPinChanged(const int& pin)
{
	ofLog() << "Analog Pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
	rotationSpeed = arduino.getAnalog(pin);
	planet01.rotateSpeed = rotationSpeed / 100;
}