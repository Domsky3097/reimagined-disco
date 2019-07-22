#pragma once
#include "ofMain.h"

class Arrows {
public:
	void setup();
	void update();
	void draw();
	float yPos, xPos; //x and y positions for circle
	int speed; // Hold the speed to be changed
	ofImage arrow; // Hold the arrow images
	int index; // Store to index to randomly draw arrows
};