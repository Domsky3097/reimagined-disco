#include "bullets.h"

void Bullets::setup() {

	xPos = ofGetWidth() / 2; // Get the centre of the screen
	yPos = ofGetHeight() / 2;
	startTime = ofGetElapsedTimef(); // Start time is set
}

void Bullets::update() {
	float lerpAmount = ofGetElapsedTimef() - startTime; // Lerp amount based on time tick
	resultX = ofLerp(xPos, targetX, lerpAmount); // result position changes every frame
	resultY = ofLerp(yPos, targetY, lerpAmount);
}

void Bullets::draw() {
	ofSetColor(100, 10, 100); // Set to a purple colour for the doughnut bullet
	ofDrawCircle(resultX, resultY, 5); //Draw the new position every frame
}