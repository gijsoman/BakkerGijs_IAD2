#include "ofApp.h"
#include "Ball.h"
#include "ofMain.h"

void ofApp::setup() {
	gui.setup("instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200));
	gui.add(xPos.set("x", 50, 0, ofGetWindowWidth()));
	gui.add(yPos.set("y", 50, 0, ofGetWindowHeight()));
}

void ofApp::update() {
	for (int i = 0; i <= Walker; i++)
	{
		ball[i].update();
	}
	if (ball[Walker-1].radius != radius)
	{
		ball[Walker-1].radius = radius;
	}
}

void ofApp::draw() {
	for (int i = 0; i <= Walker; i++)
	{
		ball[i].draw();
	}
	gui.draw();
}

void ofApp::keyPressed(int key)
{
	if (key == ' ' && Walker != 0)
	{
		Walker--;
	}
}

void ofApp::mousePressed(int x, int y, int button)
{

	if (button == 0 && Walker != 15)
	{
		ball[Walker].setup(xPos, yPos, radius);
		Walker++;
	}
}