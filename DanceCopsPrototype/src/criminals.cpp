#include "criminals.h"

void Criminals::setup() {
	xPos = ofGetWidth() + 50; //set circle to start off screen
	yPos = ofRandom(20, 500); // Spawn position is random
	speed = 1; // Always slow moving
	radius = 30; // Always a reasonable size target
}

void Criminals::update() {
	xPos -= speed; // Move the criminals to the left of the screen
}

void Criminals::draw() {
	ofSetColor(255, 0, 0); // Red for evil
	ofDrawCircle(xPos, yPos, radius); // Draw the criminals
}