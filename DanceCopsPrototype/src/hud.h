#pragma once
#include "ofMain.h"

class HUD {
public:
	void setup();
	void update();
	void draw();
	//booleans for key presses
	bool lPressed, rPressed, uPressed, dPressed, POW, playToto, playMC;
	//x and y values
	float xPos, yPos, POWx, POWy, POWwidth;
	int gifNum;
	ofSoundPlayer toto;
	ofSoundPlayer mc;
	ofImage img[8];
	ofImage gif[8];
};