#pragma once

#include "ofMain.h"
#include "gameWorld.h"
#include <string>
#include <sstream>
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);

		//char variable to control our game state
		char gameState;

		int splashYPos;
		//image object for play button
		ofImage playBtnImg, optionsBtnImg, lvlBtnImg, quitBtnImg, totoBtnImg, mcBtnImg, easyBtnImg, medBtnImg, hardBtnImg;
		ofImage splashMain;
		//rectange object for button clicks
		ofRectangle playBtn, optionsBtn, lvlBtn, quitBtn, totoBtn, mcBtn, easyBtn, medBtn, hardBtn;

		
		ofSoundPlayer toto;
		//instantiate game world object
		GameWorld gw;
		//string stream to hold game info (e.g. score)
		stringstream gameInfo;
		//ofxGIF::fiGifLoader gifloader;
		//int indexCounter;
};
