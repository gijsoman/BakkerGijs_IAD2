#pragma once

#include "ofMain.h"

class Ball {

    public:

        Ball();

        void setup(int xSpeed, int ySpeed, int zSpeed, int myRadius, ofColor myColor);

        void update();

        void draw();

        // variables
        float x;
        float y;
		float z;
        float speedY;
        float speedX;
		float speedZ;
        int radius;
        ofColor color;



    private:

};