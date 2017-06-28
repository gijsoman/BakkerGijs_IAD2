#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1

void ofApp::setup() {

    for (int i = 0; i < VOICES; i++) {
        cout << "Loading voice " << i + 1 << endl;
        voicePlayer[i].load("voice" + ofToString(i + 1) + ".wav");
        voicePlayer[i].setLoop(true);

        voicePlayer[i].play();
        //voicePlayer[i].setPaused(true);
    }

    ofSoundSetVolume(0.2f);

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();
}

void ofApp::update() {
	arduino.update();
    float time = ofGetElapsedTimef();

    float x = time * 0.1f + 30;
    for (int i = 0; i < VOICES; i++) {
        float y = i * 0.02f;
        float volume = ofNoise(x, y);
        voicePlayer[i].setVolume(volume);
    }



    ofSoundUpdate();
}

void ofApp::draw() {
    ofBackground(30, 30, 30);
    for (int i = 0; i < VOICES; i++) {
        if (voicePlayer[i].isPlaying()) {
            // bereken een kleur
            ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);

            // teken voor iedere stem een balkje, met als lengte het volume, en 5 px hoog
            ofDrawRectangle(100, i * 30 + 200, voicePlayer[i].getVolume() * 300, 5);
        }
    }
}

void ofApp::keyPressed(int key) {
    ofLogVerbose() << "Key:" << key << endl;
	cout << "isPlaying? " << voicePlayer[0].isPlaying() << endl;
     //afhankelijk van de toets, zet een stem aan of uit. Op pauze zetten werkte op de oude manier niet
	// ik heb bools toegevoegd.
    if (key == '1') {
		voice1 = !voice1;
        voicePlayer[0].setPaused(voice1);
    } else if (key == '2') {
		voice2 = !voice2;
        voicePlayer[1].setPaused(voice2);
    } else if (key == '3') {
		voice3 = !voice3;
        voicePlayer[2].setPaused(voice3);
    } else if (key == '4') {
		voice4 = !voice4;
        voicePlayer[3].setPaused(voice4);
    } else if (key == '5') {
		voice5 = !voice5;
        voicePlayer[4].setPaused(voice5);
    } else if (key == '6') {
		voice6 = !voice6;
        voicePlayer[5].setPaused(voice6);
    } /*else if (key == 'q') {
        voicePlayer[0].setSpeed(voicePlayer[0].getSpeed() + 0.1f);
    } else if (key == 'a') {
        voicePlayer[0].setSpeed(voicePlayer[0].getSpeed() - 0.1f);
    }*/
}

void ofApp::setupArduino(const int& version)
{
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);

	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);


}

void ofApp::analogPinChanged(const int& pin)
{
	ofLog() << "Analog Pin" << pin << " changed to " << arduino.getAnalog(pin) << endl;
	Speed = arduino.getAnalog(pin);

	for (int i = 0; i < VOICES; i++)
	{
		voicePlayer[i].setSpeed(ofMap(Speed, 0, 1024, 0.0f, 1));
	}
	
}