#pragma once

#include "ofMain.h"

#define VOICES 6

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofSoundPlayer voicePlayer[VOICES];
};
