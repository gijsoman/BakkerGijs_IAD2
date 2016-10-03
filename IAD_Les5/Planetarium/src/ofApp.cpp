#include "ofApp.h"

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

}

//--------------------------------------------------------------
void ofApp::update(){
	planet01.update();
	planet02.update();
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
