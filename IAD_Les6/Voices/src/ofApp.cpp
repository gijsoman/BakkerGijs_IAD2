#include "ofApp.h"

void ofApp::setup() {
//    ofSetLogLevel(OF_LOG_VERBOSE);
//    ofSetLogLevel(OF_LOG_NOTICE);
    ofSetLogLevel(OF_LOG_SILENT);

    for (int i = 0; i < VOICES; i++) {
        ofLogNotice() << "Loading voice " << i << endl;
        voicePlayer[i].load("voice" + ofToString(i + 1) + ".wav");
        voicePlayer[i].setLoop(true);

        voicePlayer[i].play();
        voicePlayer[i].setPaused(true);
    }

    ofSoundSetVolume(0.2);
}

void ofApp::update() {
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

    // afhankelijk van de toets, zet een stem aan of uit
    if (key == '1') {
        cout << "isPlaying? " << voicePlayer[0].isPlaying() << endl;
        voicePlayer[0].setPaused(voicePlayer[0].isPlaying());
    } else if (key == '2') {
        voicePlayer[1].setPaused(voicePlayer[1].isPlaying());
    } else if (key == '3') {
        voicePlayer[2].setPaused(voicePlayer[2].isPlaying());
    } else if (key == '4') {
        voicePlayer[3].setPaused(voicePlayer[3].isPlaying());
    } else if (key == '5') {
        voicePlayer[4].setPaused(voicePlayer[4].isPlaying());
    } else if (key == '6') {
        voicePlayer[5].setPaused(voicePlayer[5].isPlaying());
    } else if (key == 'q') {
        voicePlayer[0].setSpeed(voicePlayer[0].getSpeed() + 0.1f);
    } else if (key == 'a') {
        voicePlayer[0].setSpeed(voicePlayer[0].getSpeed() - 0.1f);
    }
}
