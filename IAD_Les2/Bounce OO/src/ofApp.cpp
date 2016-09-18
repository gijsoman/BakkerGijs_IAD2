#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0;  i < AANTALBALLEN; i++)
	{
		ballen[i].setup();
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < AANTALBALLEN; i++)
	{
		ballen[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < AANTALBALLEN; i++)
	{
		ballen[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


