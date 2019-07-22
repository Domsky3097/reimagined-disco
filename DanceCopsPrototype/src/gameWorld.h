#pragma once
#include "ofMain.h"
#include "hud.h"
#include "arrows.h"
#include "bullets.h"
#include "criminals.h"

class GameWorld {
public:
	void setup(); // setup function used to initalise game world variables and listeners
	void draw(); // draw function used to draw the game world
	void update(); // update function used to update gameworld variables and objects
	void exit(); // exit function used to remove game world listeners

	void keysPressed(ofKeyEventArgs& e); //keypressed function to listen for key presses inside class
	void keysReleased(ofKeyEventArgs& e); //keyreleased function to listen for key releases inside class
	void mousePressed(ofMouseEventArgs& e);

	int score, lives, seconds, POWscore; // game info variables

	bool easyOn, medOn, hardOn;

	float startTime; //start time variable for counter
	
	//instantiate hero
	HUD hud;
	//Circle circle;
	//container for circle objects
	vector<Arrows> arrows;
	vector<Bullets> bullets;
	vector<Criminals> criminals;
	int numArrows, numBullets, numCriminals;
	//circle timer
	float arrowTime, criminalTime, spawnDelay;

	//ofSoundPlayer toto;
};