#pragma once
#include "ofMain.h"

class Criminals {
public:
	void setup();
	void update();
	void draw();
	float yPos, xPos; //x and y positions for circle
	int speed;
private:
	int radius;
};