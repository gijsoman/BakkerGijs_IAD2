#include "Planet.h"



Planet::Planet()
{
	rotation = 0.0;
}


void Planet::setup(string name)
{
	planetParameterGroup.setName(name);
	planetParameterGroup.add(rotateSpeed.set("speed", 0.0, 0.0, 1024));
	planetParameterGroup.add(distance.set("distance", 0, 0, 600));
	planetParameterGroup.add(color.set("color", ofColor::green));

	
}

void Planet::update()
{
	rotation++;
}

void Planet::draw()
{
	ofSetColor(color);
	ofRotate(rotation*rotateSpeed);
	ofDrawSphere(distance, 0, 0, 30);
}
