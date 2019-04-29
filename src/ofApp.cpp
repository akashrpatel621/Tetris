#include "ofApp.h"

int ofApp::numCols = 15;
int ofApp::numRows = 23;
//--------------------------------------------------------------
void ofApp::setup(){

	speed = 500;
	frameNumber = 0;
	ofSetFrameRate(60);

	sound.load("theme.mp3");
	sound.setVolume(0.15);
	sound.play();

	soundclear.load("clear.mp3");
	sounddrop.load("dropblock.mp3");
	soundgameover.load("gameover.mp3");
	
	background.load("images/background.jpg");
	game_over.load("images/gameover.png");

	ofSetWindowShape(800, 1000);
	ofSetWindowPosition(10, 10);

	GameBoard::InitiateBoard(numCols, numRows);
}

//--------------------------------------------------------------
void ofApp::update() {
	vector<GameBlock> transformedTiles;

	convertToString(GameBoard::score);
	TimeToString(ofGetElapsedTimef());
	LevelToString(GameBoard::level);

	if (GameBoard::gamespeed > 350) {
		GameBoard::gamespeed = 350;
	}
	if ((!gamePaused) && (!gameOver) && (ofGetElapsedTimeMillis() - frameNumber > speed + GameBoard::gamespeed)) {
		transformedTiles = tetromino.MoveDown();
		if (!tetromino.BottomCollison(transformedTiles, 920)) {
			tetromino.tiles = transformedTiles;
		}
		else {
			if (tetromino.GameOver()) {
				end();
			}
			tetromino.HandleBottomCollision(tetromino);
			if (GameBoard::play_clear_sound == true) {
				soundclear.play();
				GameBoard::play_clear_sound = false;
			}
			else {
				sounddrop.play();
			}
			tetromino.reset();
		}
		frameNumber = ofGetElapsedTimeMillis();
	}
	sound.setPaused(musicpuased);
	sound.setSpeed(1 + GameBoard::soundspeed);	
	std::cout << ofApp::level << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	background.draw(0, 0, 2000, 1500);
	
	GameBoard::draw();
	tetromino.draw();

	ofPushStyle(); {
		ofSetColor(ofColor::black);
		ofDrawRectangle(625, 50, 150, 300);
	}; ofPopStyle();

	font.load("font.ttf", 26, true, true);
	font.drawString("Score", 652, 90);
	
	ofPushStyle(); {
		font.load("font.ttf", 15, true, true);
		ofSetColor(ofColor::white);
		font.drawString("Time Elapsed", 630, 180);
	}; ofPopStyle();

	ofPushStyle(); {
		font.load("font.ttf", 18, true, true);
		ofSetColor(ofColor::white);
		font.drawString("Level", 669, 280);
	}; ofPopStyle();

	ofPushStyle(); {
		font.load("font.ttf", 24, true, true);
		ofSetColor(ofColor::seaGreen);
		font.drawString(ofApp::level, 690, 320);
	}; ofPopStyle();

	ofPushStyle(); {
		font.load("font.ttf", 24, true, true);
		ofSetColor(ofColor::blue);
		font.drawString(ofApp::score, 685, 130);
	};ofPopStyle();

	ofPushStyle(); {
		font.load("font.ttf", 18, true, true);
		ofSetColor(ofColor::red);
		font.drawString(ofApp::time_elapsed, 650, 220);
	}; ofPopStyle();
}

void ofApp::end()
{
	gameOver = true;
	sound.stop();
	game_over.draw(500, 0, 500, 500);
	soundgameover.play();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	vector<GameBlock> transformedTiles;
	
	switch (key) {
	case 'p':
		gamePaused = !gamePaused;
		musicpuased = !musicpuased;
		break;
	case 'm':
		musicpuased = !musicpuased;
		break;
	case OF_KEY_DOWN:
		transformedTiles = tetromino.MoveDown();
		bool bottom = tetromino.BottomCollison(transformedTiles, 920);
		if (!bottom && !gameOver) {
			tetromino.tiles = transformedTiles;
		}
		else {
			if (tetromino.GameOver()) {
				end();
			}
			tetromino.HandleBottomCollision(tetromino);
			
		}
		break;
	}
	switch (key) {
	case OF_KEY_LEFT:
		transformedTiles = tetromino.MoveLeft();
		bool left = tetromino.LeftCollison(transformedTiles, 0);
		if (!left) {
			tetromino.tiles = transformedTiles;
		}
		break;
	}
	switch (key) {
	case OF_KEY_RIGHT:
		transformedTiles = tetromino.MoveRight();
		bool right = tetromino.RightCollison(transformedTiles, 600);
		if (!right) {
			tetromino.tiles = transformedTiles;
		}
		break;
	}
	switch (key) {
	case ' ':
		transformedTiles = tetromino.Rotate();
		bool left_collision = tetromino.LeftCollison(transformedTiles, 0);
		bool right_collision = tetromino.RightCollison(transformedTiles, 600);
		if (!left_collision && !left_collision) {
			tetromino.tiles = transformedTiles;
		}
		break;
	}
}
//--------------------------------------------------------------
void ofApp::convertToString(int score)
{
	int num = score;
	ostringstream str1;
	str1 << num;
	ofApp::score = str1.str();
}
//---------------------------------------------------------------
void ofApp::TimeToString(double time)
{
	double num = time;
	ostringstream str1;
	str1 << num;
	ofApp::time_elapsed = str1.str();
}
void ofApp::LevelToString(int level)
{
	int num = level;
	ostringstream str1;
	str1 << num;
	ofApp::level = str1.str();
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	
} 

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
