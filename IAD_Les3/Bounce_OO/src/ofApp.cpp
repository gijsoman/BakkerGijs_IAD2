#include "ofApp.h"
#include "Ball.h"
#include "ofMain.h"

Ball ball;

void ofApp::setup() {
	gui.setup("instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200));
	gui.add(x.set("x", 50, 0, ofGetWindowWidth()));
	gui.add(y.set("y", 50, 0, ofGetWindowHeight()));
}

void ofApp::update() {
    ball.update();
	if (ball.radius != radius)
	{
		ball.radius = radius;
	}
}

void ofApp::draw() {
    ball.draw();
	gui.draw();
}

void ofApp::keyPressed(int key)
{
	if (key == ' ')
	{
		ball.setup(x, y, radius);
	}
}