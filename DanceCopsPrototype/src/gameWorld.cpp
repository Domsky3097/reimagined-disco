#include "gameWorld.h"

void GameWorld::setup() {
	//listners so we can recieve core openFrameworks events in custom classes
	ofAddListener(ofEvents().keyPressed, this, &GameWorld::keysPressed);
	ofAddListener(ofEvents().keyReleased, this, &GameWorld::keysReleased);
	ofAddListener(ofEvents().mousePressed, this, &GameWorld::mousePressed);
	//initialise game variables
	score = 0; lives = 10; POWscore = 0;
	if (hud.playToto == true) {
		seconds = 90;
	}
	else if (hud.playMC == true) {
		seconds = 50;
	}
	//set start time (used for countdown timer
	startTime = ofGetElapsedTimef();
	
	spawnDelay = 6;
	//toto.load("TotoAfrica.wav");
	//initiate number of circles;
	numArrows = 0;
	numBullets = 0;
	//set circle start time (used for generating circle objects)
	arrowTime = ofGetElapsedTimef();
	criminalTime = ofGetElapsedTimef();
	//output message to check gameworld is setup 
	std::cout << "game world initialised" << std::endl;

	//setup hero
	hud.setup();
}

void GameWorld::update() {
	//update timer
	float tick = ofGetElapsedTimef() - startTime; //update tick on every frame
	if (tick > 1) { //check if tick is more than 1
		startTime = ofGetElapsedTimef(); //reset start time to new elapsed value
		seconds--; //decrement seconds to create countdown timer
	}
	/*
	if ((hero.dPressed == true || hero.uPressed == true || hero.lPressed == true || hero.rPressed == true) && (tick > 0.5f)) {
		hero.dPressed = false;
		hero.uPressed = false;
		hero.lPressed = false;
		hero.rPressed = false;
	}
	*/
	//generate circle if 2 seconds passed
	float arrowTick = ofGetElapsedTimef() - arrowTime;
	if (arrowTick > 2) {
		arrowTime = ofGetElapsedTimef();
		//add object
		numArrows++; //increase circle counter
		arrows.resize(numArrows); //resize vector to create new object
		if (easyOn) {
			arrows[numArrows - 1].speed = 5;
		}
		else if (medOn) {
			arrows[numArrows - 1].speed = 10;
		}
		else if (hardOn) {
			arrows[numArrows - 1].speed = 15;
		}
		else {
			arrows[numArrows - 1].speed = 5;
		}
		
		arrows[numArrows - 1].setup(); //setup circle to give random size, colour and speed
	}

	float criminalTick = ofGetElapsedTimef() - criminalTime;
	if (criminalTick > spawnDelay) {
		criminalTime = ofGetElapsedTimef();
		numCriminals++; //increase circle counter
		criminals.resize(numCriminals); //resize vector to create new object
		criminals[numCriminals - 1].setup();
	}

	for (int i = 0; i < criminals.size(); i++) {
		criminals[i].update();
		criminals.resize(numCriminals); //resize vector to create new object
		if (criminals[i].xPos < -20) {
			//erase cricles if off the screen
			criminals.erase(criminals.begin() + i);
			lives--;
			numCriminals--;
			criminals.resize(numCriminals);
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
		criminals.resize(numCriminals); //resize vector to create new object
		for (int j = 0; j < criminals.size(); j++) {
			if (bullets[i].resultX > (criminals[j].xPos - 30) && bullets[i].resultX < (criminals[j].xPos + 30) && bullets[i].resultY >(criminals[j].yPos - 30) && bullets[i].resultY < (criminals[j].yPos + 30)) {
				score += 50;
				criminals.erase(criminals.begin() + j);
				numCriminals--;
				criminals.resize(numCriminals); //resize vector to create new object
			}
		}
		if (bullets[i].resultY > ofGetHeight() + 20 || bullets[i].resultY < -20 || bullets[i].resultX > ofGetWidth() + 20 || bullets[i].resultX < -20) {
			//erase cricles if off the screen
			bullets.erase(bullets.begin() + i);
			numBullets--;
			bullets.resize(numBullets);
		}
	}
	/*
	for (int i = 0; i < criminals.size(); i++) {
		criminals[i].update();
	}
	*/
	//update all circles on screen
	for (int i = 0; i < arrows.size(); i++) {
		//update each circle
		arrows[i].update();
		//check collisions on circles

		if (arrows[i].xPos > hud.xPos && arrows[i].xPos < (hud.xPos + ofGetWidth()) && arrows[i].yPos > (hud.yPos - 150) && arrows[i].yPos < (hud.yPos + 50)) {
			//if circles overlap hero increase the score and remove circles
			//cout << circles[i].index << endl;
			if ((hud.lPressed && arrows[i].index == 0) || (hud.rPressed && arrows[i].index == 3) || (hud.uPressed && arrows[i].index == 1) || (hud.dPressed && arrows[i].index == 2)) {
				score += 10;
				POWscore += 10;
				if (arrows[i].yPos > hud.yPos - 90) {
					score += 10;
					POWscore += 10;
				}
				if (arrows[i].yPos > hud.yPos - 40) {
					score += 10;
					POWscore += 10;
				}
				arrows.erase(arrows.begin() + i);
				numArrows--;
				if (hud.POWwidth < 100) {
					hud.POWwidth = POWscore;
				}
				else {
					hud.POWwidth = 100;
				}
				
			}
			
		}else if (arrows[i].yPos > ofGetHeight() + 20) {
			//erase cricles if off the screen
			arrows.erase(arrows.begin() + i);
			numArrows--;
			lives--;
		}
		hud.dPressed = false;
		hud.uPressed = false;
		hud.lPressed = false;
		hud.rPressed = false;
	}

	//update hero object
	hud.update();
}

void GameWorld::draw() {
	//draw hero object
	hud.draw();
	//toto.play();
	//iterate through the circles vector and draw each one
	for (int i = 0; i < arrows.size(); i++) {
		arrows[i].draw();
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].draw();
	}
	for (int i = 0; i < criminals.size(); i++) {
		criminals[i].draw();
	}
}

void GameWorld::keysPressed(ofKeyEventArgs& e) {
	switch (e.key) {
	case OF_KEY_LEFT:
		hud.lPressed = false; //set left pressed on hero to true
		break;
	case OF_KEY_RIGHT:
		hud.rPressed = false; //set right pressed on hero to true
		break;
	case OF_KEY_UP:
		hud.uPressed = false; //set left pressed on hero to true
		break;
	case OF_KEY_DOWN:
		hud.dPressed = false; //set right pressed on hero to true
		break;
	}
}
void GameWorld::keysReleased(ofKeyEventArgs& e) {
	switch (e.key) {
	case OF_KEY_LEFT:
		hud.lPressed = true; //set left pressed on hero to false
		break;
	case OF_KEY_RIGHT:
		hud.rPressed = true; //set right pressed on hero to false
		break;
	case OF_KEY_UP:
		hud.uPressed = true; //set left pressed on hero to true
		break;
	case OF_KEY_DOWN:
		hud.dPressed = true; //set right pressed on hero to true
		break;
	}
}

void GameWorld::mousePressed(ofMouseEventArgs& e) {
	if (hud.POWwidth >= 100) {
		numBullets++; //increase circle counter
		bullets.resize(numBullets); //resize vector to create new object
		bullets[numBullets - 1].setup();
		bullets[numBullets - 1].targetX = e.x;
		bullets[numBullets - 1].targetY = e.y;
		cout << bullets[numBullets - 1].targetX << endl;
		cout << bullets[numBullets - 1].targetY << endl;
		POWscore = 0;
		hud.POWwidth = 0;
	}
	
}

void GameWorld::exit() {
	//remove key listeners, useful so we only listen for these when game is in playing state
	ofRemoveListener(ofEvents().keyPressed, this, &GameWorld::keysPressed);
	ofRemoveListener(ofEvents().keyReleased, this, &GameWorld::keysReleased);
	
	//remove any remaining circles
	for (int i = 0; i < arrows.size(); i++) {
		arrows.erase(arrows.begin() + i);
		numArrows--;
	}

	for (int i = 0; i < criminals.size(); i++) {
		criminals.erase(criminals.begin() + i);
		numCriminals--;
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets.erase(bullets.begin() + i);
		numBullets--;
	}

	//output message so we can check game world is exited when we leave playing state
	std::cout << "Game World Exited" << std::endl;
}