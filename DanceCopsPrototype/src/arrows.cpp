#include "arrows.h"

void Arrows::setup() {
	yPos = -50; //set circle to start off screen
	xPos = 0; //start at a random position across screen width
	// Generate a random number
	index = ofRandom(0, 4);
	// load an arrow based on index
	arrow.load("Arrows/Arrow" + ofToString(index + 1) + ".png");
	// Based on the arrow direction, the x pos is changed
	for (int i = 0; i < 4; i++) {
		if (index == 0) {
			xPos = 200;
		}
		else if (index == 1) {
			xPos = 400;
		}
		else if (index == 2) {
			xPos = 600;
		}
		else if (index == 3) {
			xPos = 800;
		}
	}
}

void Arrows::update() {
	yPos += speed; //update yPos based on speed
}

void Arrows::draw() {
	ofSetColor(255); // Set it so the arrows are seen
	arrow.draw(xPos, yPos, 100, 100); // Draw the arrows
}