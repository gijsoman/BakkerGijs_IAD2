#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(rotateSpeedX.set("X", 0, 0, 20.0));
	gui.add(rotateSpeedY.set("Y", 0, 0, 20.0));
	gui.add(rotateSpeedZ.set("Z", 0, 0, 20.0));
}

//--------------------------------------------------------------
void ofApp::update(){
	rotationX += rotateSpeedX;
	rotationY += rotateSpeedY;
	rotationZ += rotateSpeedZ;
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	ofSetCircleResolution(100);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	ofPushMatrix();
	ofRotateX(rotationX);
	ofSetColor(ofColor::red);
	ofDrawCircle(-300, 0, 130);
	ofPopMatrix();

	ofPushMatrix();
	ofRotateY(rotationY);
	ofSetColor(ofColor::green);
	ofDrawCircle(0, 0, 130);
	ofPopMatrix();

	ofPushMatrix();
	ofRotateZ(rotationZ);
	ofSetColor(ofColor::blue);
	ofDrawCircle(300, 0, 130);
	ofPopMatrix();

	ofDrawGrid(200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

