#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(34, 55, 20);
	for (int i = 0; i < AANTALBALLEN; i++)
	{
		Balls[i].setup();
	}
	Balls[Walker].setup();
	gui.setup("Instellingen", "settings.xml");
	gui.add(speedX.set("SpeedX", -50, 0, 50));
	gui.add(speedY.set("SpeedY", -50, 0, 50));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i <= Walker; i++)
	{
		Balls[i].update(speedX, speedY);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i <= Walker; i++)
	{
		Balls[i].draw();
	}
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ')
	{
		Walker--;

	}
}

void ofApp::mousePressed(int x, int y, int button)
{
	if (button == 0)
	{
		Walker++;
	}
}