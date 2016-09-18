#include "BounceObject.h"



BounceObject::BounceObject()
{
}

void BounceObject::setup()
{
	radius = ofRandom(20, 5);
	position = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void BounceObject::update(int Yspeed, int Xspeed)
{
	speed = ofVec2f(Xspeed, Yspeed);
	if (position.x <= 0) {
		position.x = 0;
		speed.x = -speed.x;
	}
	else if (position.x >= ofGetWidth()) {
		position.x = ofGetWidth();
		speed.x = -speed.x;
	}

	if (position.y <= 0) {
		position.y = 0;
		speed.y = -speed.y;
	}
	else if (position.y >= ofGetHeight()) {
		position.y = ofGetHeight();
		speed.y = -speed.y;
	}

	position.x += speed.x;
	position.y += speed.y;
}

void BounceObject::draw()
{
	ofSetColor(color);
	ofDrawCircle(position, radius);
}