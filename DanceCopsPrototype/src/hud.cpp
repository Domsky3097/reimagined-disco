#include "hud.h"

void HUD::setup() {
	xPos = 0; //start hero in middle of screen
	yPos = 718; //start hero at bottom of screen
	POWx = 814; // Set up POW bar x pos
	POWy = 50; // Set up POW bar y pos
	// gifNum = 0; attmpet
	// Load music files
	toto.load("TotoAfrica.wav");
	mc.load("MCHammerTime.wav");
	// Play music based on users choice
	if (playToto == true) {
		toto.play();
	}
	else if (playMC == true) {
		mc.play();
	}
	
	//gifloader.load("run.gif");
	//indexCounter = 0;
	//for (int i = 0; i < 8; i++) {
	//	img[i].load("gif/cop" + ofToString(i + 1) + ".png");
	//}
	for (int i = 0; i < 8; i++) {
		gif[i].load("CopDance/CopDance" + ofToString(i + 1) + ".png");
	}
}

void HUD::update() {
	/*
	if (lPressed) {
		vel -= speed; //decrease velocity by speed to move left on x axis
	}
	else if (rPressed) {
		vel += speed; //increase velocity by speed to move right on x axis
	}
	else {
		vel *= friction; //multiple velocity by friction to slow down object when no key pressed
	}
	xPos += vel; //update xPos based on velocity

	//ensure velocity doesn't exceed maxSpeed
	if (vel > maxSpeed) {
		vel = maxSpeed;
	}
	else if (vel < -maxSpeed) {
		vel = -maxSpeed;
	}
	*/
	/*
	if (ofGetFrameNum() % 4 == 0 && gifloader.pages.size() == 8) {
		indexCounter++;
		if (indexCounter > gifloader.pages.size() - 1) indexCounter = 0;
	}
	std::cout << gifloader.pages.size() << std::endl;
	*/
}

void HUD::draw() {	
	ofSetColor(0, 0, 255); //set hud bar colour to blue
	ofDrawRectangle(xPos, yPos, ofGetWidth(), 50); //draw rectalngle based on x and y position and set to 50 pixels high and wide as the screen
	ofSetColor(255, 255, 0); //set hud bar colour to yellow
	ofDrawRectangle(xPos, yPos - 50, ofGetWidth(), 50);
	ofSetColor(255, 0, 0); //set hud bar colour to red
	ofDrawRectangle(xPos, yPos - 100, ofGetWidth(), 50);
	ofSetColor(0);
	ofDrawRectangle(POWx, POWy, POWwidth*2, 25);
	ofSetColor(255, 0, 0);
	ofDrawRectangle(1014, 50, 10, 25);
	//Failed attemps to generate gifs
	/*
	if (ofGetFrameNum() % 4 == 0) {
		gifNum++;
		if (gifNum == 8) {
			gifNum = 0;
		}
		gif[gifNum].draw(ofGetWidth() / 2, ofGetHeight() / 2, 100, 100);
	}
	*/
	/*
	if (gifloader.pages.size() > 0) {
		ofImage img = gifloader.pages[indexCounter];
		ofPixels pix = img.getPixels();
		img.setFromPixels(pix);
		img.draw(400, 300);
	}
	*/
	
}