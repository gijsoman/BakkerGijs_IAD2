#include "Ball.h"

Ball::Ball() {
}

void Ball::setup(int xSpeed, int ySpeed, int zSpeed, int myRadius, ofColor myColor) {
    x = ofRandom(0, ofGetWindowWidth());        // give some random position
    y = ofRandom(0, ofGetWindowHeight());
	z = ofRandom(0, ofGetWindowHeight());

	speedX = xSpeed;          // and random speed and direction
    speedY = ySpeed;
	speedZ = zSpeed;

    radius = myRadius;

    // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
    color.set(myColor);
}


void Ball::update() {
    if (x < -ofGetWindowWidth()/2) {
        x = -ofGetWindowWidth() / 2;
        speedX *= -1;
    } else if (x > ofGetWindowWidth() / 2) {
        x = ofGetWindowWidth() / 2;
        speedX *= -1;
    }

    if (y < -ofGetWindowHeight()/2) {
        y = -ofGetWindowHeight() / 2;
        speedY *= -1;
    } else if (y > ofGetWindowHeight() / 2) {
        y = ofGetWindowHeight() / 2;
        speedY *= -1;
    }

	if (z < -ofGetWindowHeight() / 2) {
		z = -ofGetWindowHeight() / 2;
		speedZ *= -1;
	}
	else if (z > ofGetWindowHeight() / 2) {
		z = ofGetWindowHeight() / 2;
		speedZ *= -1;
	}

    x += speedX;
    y += speedY;
	z += speedZ;
}

void Ball::draw() {
	ofSetSphereResolution(100);
    ofSetColor(color);
    ofDrawSphere(x, y, z, radius);
}