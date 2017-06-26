#include "Ball.h"

Ball::Ball() {
}

void Ball::setup(int xSpeed, int ySpeed, int myRadius, ofColor myColor) {
    x = ofRandom(0, ofGetWindowWidth());        // give some random position
    y = ofRandom(0, ofGetWindowHeight());

	speedX = xSpeed;          // and random speed and direction
    speedY = ySpeed;

    radius = myRadius;

    // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
    color.set(myColor);
}


void Ball::update() {
    if (x < 0) {
        x = 0;
        speedX *= -1;
    } else if (x > ofGetWidth()) {
		x = ofGetWidth();
        speedX *= -1;
    }

    if (y < 0) {
        y = 0;
        speedY *= -1;
    } else if (y > ofGetHeight()) {
        y = ofGetHeight();
        speedY *= -1;
    }

    x += speedX;
    y += speedY;
}

void Ball::draw() {
	ofSetCircleResolution(100);
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}