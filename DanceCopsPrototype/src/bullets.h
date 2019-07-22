#pragma once
#include "ofMain.h"

class Bullets {
public:
	void setup();
	void update();
	void draw();
	// Set up start point, target point, and a resulting position from the lerp
	float xPos, yPos, targetX, targetY, resultX, resultY;
	float startTime; //Set up a tick
};