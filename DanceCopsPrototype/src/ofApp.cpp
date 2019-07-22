#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//set intial gamestate to m (menu)
	gameState = 'm';
	//load in play button image
	playBtnImg.load("RandomSquare.png");
	optionsBtnImg.load("RandomSquare.png");
	lvlBtnImg.load("RandomSquare.png");
	quitBtnImg.load("RandomSquare.png");
	totoBtnImg.load("RandomSquare.png");
	mcBtnImg.load("RandomSquare.png");
	easyBtnImg.load("RandomSquare.png");
	medBtnImg.load("RandomSquare.png");
	hardBtnImg.load("RandomSquare.png");
	splashMain.load("SplashMain.png");
	splashYPos = 0;
	//set up button rectangle position and size
	//playBtn.set(ofGetWidth() / 2 - 75, ofGetHeight() - 200, 150, 100);
	playBtn.set(0, 225, ofGetWidth(), 115);
	lvlBtn.set(0, 338, ofGetWidth(), 115);
	optionsBtn.set(0, 451, ofGetWidth(), 115);
	quitBtn.set(0, 565, ofGetWidth(), 115);
	totoBtn.set(0, 338, ofGetWidth(), 115);
	mcBtn.set(0, 451, ofGetWidth(), 115);
	easyBtn.set(0, 338, ofGetWidth(), 115);
	medBtn.set(0, 451, ofGetWidth(), 115);
	hardBtn.set(0, 565, ofGetWidth(), 115);
	ofSetFrameRate(60);
	//musicPlaying = false;
	//toto.load("TotoAfrica.wav");
	//gw.hero.playToto = true;
	//toto.play();
	//gifloader.load("run.gif");
	//indexCounter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	//cout << gw.hero.playMC << endl;
	// switch statement to only upate when game is in certain state
	switch (gameState) {
	//////////MENU STATE /////////////
	case 'm':
		break;
	//////////OPTIONS MENU STATE /////////////
	case 'o':
		//gw.hero.playToto = true;
		break;
	//////////LEVEL MENU STATE /////////////
	case 'l':
		break;
	//////////QUIT STATE /////////////
	case 'q':
		break;
	//////////PLAY STATE /////////////
	case 'p':
		//if (musicPlaying == false) {
			//toto.play();
			//musicPlaying == true;
		//}
		//update string stream while game is running
		gameInfo.str("");
		//get game info from game world object (gw)
		gameInfo << "Score: " << gw.score << "\t Lives: " << gw.lives << "\t Seconds: " << gw.seconds;
		//check seconds
		if (gw.seconds < 1 || gw.lives < 1) {
			gw.exit();
			gameState = 'e';
		}
		//update the game world
		gw.update();

		break;
	//////////GAME OVER STATE /////////////
	case 'e':
		//toto.stop();
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// switch statement to control what is drawn when
	switch (gameState){
	//////////MAIN MENU DRAWING/////////////
	case 'm': {
		ofSetColor(255);
		//set background to red
		ofBackground(255, 0, 0);

		splashMain.draw(0, splashYPos, 1024, 1536);
		if (splashYPos > -778) {
			splashYPos -= 4;
		}

		if (splashYPos < -770) {
			ofDrawBitmapString("To see how to play the game, go to the options menu!", 20, 700);
			if (playBtn.inside(ofGetMouseX(), ofGetMouseY())) {
				ofSetColor(0, 0, 255, 150);
			}
			else {
				ofSetColor(0, 0, 0, 0);
			}
			playBtnImg.draw(playBtn);

			//create hover effect on button by checking if mouse is inside rectangle
			if (optionsBtn.inside(ofGetMouseX(), ofGetMouseY())) {
				ofSetColor(255, 255, 0, 150);
			}
			else {
				ofSetColor(0, 0, 0, 0);
			}
			optionsBtnImg.draw(optionsBtn);

			if (lvlBtn.inside(ofGetMouseX(), ofGetMouseY())) {
				ofSetColor(0, 255, 0, 150);
			}
			else {
				ofSetColor(0, 0, 0, 0);
			}
			lvlBtnImg.draw(lvlBtn);

			if (quitBtn.inside(ofGetMouseX(), ofGetMouseY())) {
				ofSetColor(255, 127, 0, 150);
			}
			else {
				ofSetColor(0, 0, 0, 0);
			}
			quitBtnImg.draw(quitBtn);
		}
		

		//ofImage img = gifloader.pages[indexCounter];
		//ofPixels pix = img.getPixels();
		//img.setFromPixels(pix);
		//img.draw(400, 300);
	}
		break;
	case 'o':
		ofBackground(0);
		ofSetColor(255);
		ofDrawBitmapString("To play the game, use the arrow keys when the appropriate arrow hits one of the colours at the bottom of the screen.", 20, 20);
		ofDrawBitmapString("This will increase your score and your POW bar, when your POW bar is full, you can shoot the criminals!", 20, 40);
		ofDrawBitmapString("In order to shoot, click on the screen! The speed of the bullet is based on how far you click from the centre.", 20, 60);
		ofDrawBitmapString("Be sure to never miss a beat, and defeat all the criminals while surviving the duration of the song.", 20, 80);
		ofDrawBitmapString("EASY", (ofGetWidth() / 2) - 100, 400);
		ofDrawBitmapString("MEDIUM", (ofGetWidth() / 2) - 100, 510);
		ofDrawBitmapString("HARD", (ofGetWidth() / 2) - 100, 620);
		if (easyBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(0, 255, 0, 150);
		}
		else {
			ofSetColor(0, 0, 0, 0);
		}
		easyBtnImg.draw(easyBtn);

		if (medBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(255, 255, 0, 150);
		}
		else {
			ofSetColor(0, 0, 0, 0);
		}
		medBtnImg.draw(medBtn);
		if (hardBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(255, 127, 0, 150);
		}
		else {
			ofSetColor(0, 0, 0, 0);
		}
		hardBtnImg.draw(hardBtn);
		break;
	case 'l':
		ofBackground(0);
		ofSetColor(255);
		ofDrawBitmapString("TOTO - AFRICA", (ofGetWidth() / 2) - 100, 400);
		ofDrawBitmapString("MC HAMMER - HAMMER TIME", (ofGetWidth() / 2) - 100, 500);
		if (mcBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(255, 255, 0, 150);
		}
		else {
			ofSetColor(0, 0, 0, 0);
		}
		mcBtnImg.draw(mcBtn);

		if (totoBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(0, 255, 0, 150);
		}
		else {
			ofSetColor(0, 0, 0, 0);
		}
		totoBtnImg.draw(totoBtn);
		break;
	case 'q':
		std::exit(1);
		break;
	//////////PLAY SCREEN DRAWING /////////////
	case 'p':
		//set background to red
		ofBackground(225);
		ofSetColor(0);
		ofDrawBitmapString(gameInfo.str(), 20, 20);
		//draw gameWorld
		gw.draw();
		break;
	//////////GAME OVER DRAWING /////////////
	case 'e':
		//set background to blue
		ofBackground(255);
		ofSetColor(0);
		ofDrawBitmapString("YOUR FINAL SCORE", (ofGetWidth() / 2) - 100, 50);
		ofDrawBitmapString(gw.score, (ofGetWidth() / 2) - 25, 75);
		//create hover effect on button by checking if mouse is inside rectangle
		if (playBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(0, 0, 255, 200);
		}
		else {
			ofSetColor(0, 0, 255, 150);
		}
		//draw button
		playBtnImg.draw(playBtn);

		if (optionsBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(255, 255, 0, 200);
		}
		else {
			ofSetColor(255, 255, 0, 150);
		}
		optionsBtnImg.draw(optionsBtn);

		if (lvlBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(0, 255, 0, 200);
		}
		else {
			ofSetColor(0, 255, 0, 150);
		}
		lvlBtnImg.draw(lvlBtn);

		if (quitBtn.inside(ofGetMouseX(), ofGetMouseY())) {
			ofSetColor(255, 127, 0, 200);
		}
		else {
			ofSetColor(255, 127, 0, 150);
		}
		quitBtnImg.draw(quitBtn);
		ofSetColor(0);
		ofDrawBitmapString("REPLAY", (ofGetWidth() / 2) - 100, 290);
		ofDrawBitmapString("CHANGE SONG", (ofGetWidth() / 2) - 100, 400);
		ofDrawBitmapString("CHANGE DIFFICULTY", (ofGetWidth() / 2) - 100, 510);
		ofDrawBitmapString("QUIT", (ofGetWidth() / 2) - 100, 620);
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//for testing remember to remove
	switch (key) {
	case 'm':
		gameState = 'm'; // change game state to menu
		break;
	case 'o':
		gameState = 'o'; // change game state to menu
		break;
	case 'l':
		gameState = 'l'; // change game state to menu
		break;
	case 'q':
		gameState = 'q'; // change game state to menu
		break;
	case 'p':
		gameState = 'p'; // change game state to play
		gw.setup(); //setup the game to initialise variables and start event listeners (key presses)
		break;
	case 'e':
		gameState = 'e'; // change game state to end (game over)
		gw.exit(); //exit the game world to remove event listeners (key presses)
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

void ofApp::mousePressed(int x, int y, int button) {
	if (gameState == 'l') {
		if (totoBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			gw.hud.playToto = true; //set game state to playing if play button is clicked
			gw.hud.playMC = false;
			gameState = 'm';
		}
		if (mcBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			gw.hud.playToto = false; //set game state to playing if play button is clicked
			gw.hud.playMC = true;
			gameState = 'm';
		}

	} else if (gameState == 'o') {
		if (easyBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			cout << "easy picked" << endl;
			gw.easyOn = true;
			gw.medOn = false;
			gw.hardOn = false;

			gameState = 'm';
		}
		if (medBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			cout << "medium picked" << endl;
			gw.easyOn = false;
			gw.medOn = true;
			gw.hardOn = false;

			gameState = 'm';
		}
		if (hardBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			cout << "hard picked" << endl;
			gw.easyOn = false;
			gw.medOn = false;
			gw.hardOn = true;

			gameState = 'm';
		}

	} else if ((gameState == 'm' || gameState == 'e') && splashYPos < -770) {
		if (playBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			gameState = 'p'; //set game state to playing if play button is clicked
			gw.setup(); // setup the game world to intialise variables and start event listeners
		}
		if (optionsBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			gameState = 'o'; //set game state to playing if play button is clicked
		}
		if (lvlBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			gameState = 'l'; //set game state to playing if play button is clicked
		}
		if (quitBtn.inside(x, y)) { //check if mouse x and y is inside the button when clicked
			gameState = 'q'; //set game state to playing if play button is clicked
		}
	}
	/*
	
	*/
}