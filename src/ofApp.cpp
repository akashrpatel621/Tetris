#include "ofApp.h"

int ofApp::num_cols = 15;
int ofApp::num_rows = 23;

//--------------------------------------------------------------
void ofApp::setup(){
	speed = 500;
	frame_number = 0;
	ofSetFrameRate(60);

	sound.load("theme.mp3");
	sound.setVolume(0.15);
	sound.play();

	row_cleared_sound.load("clear.mp3");
	tetromino_set_sound.load("dropblock.mp3");
	soundgameover.load("gameover.mp3");
	
	background.load("images/background.jpg");

	ofSetWindowShape(800, 1000);
	ofSetWindowPosition(10, 10);

	GameBoard::InitiateBoard(num_cols, num_rows);
}

//--------------------------------------------------------------
void ofApp::update() {
	vector<GameBlock> transformed_tiles;
	
	//Convert integers to strings to print out.
	convertToString(GameBoard::score);
	LevelToString(GameBoard::level);

	// Updating time elapsed.
	if (!gameOver && !gamePaused) {
		TimeToString(ofGetElapsedTimef());
	}

	//Set a max speed for the rate the tetrominoes fall. 
	if (GameBoard::game_speed > max_game_speed) {
		GameBoard::game_speed = max_game_speed;
	}

	//Updates the tetromino as it falls if the game is not over. 
	if ((!gamePaused) && (!gameOver) && (ofGetElapsedTimeMillis() - frame_number > speed + GameBoard::game_speed)) {
		transformed_tiles = tetromino.MoveDown();
		if (!tetromino.BottomCollision(transformed_tiles, GameBoard::k_height)) {
			tetromino.tiles = transformed_tiles;
		}
		else {
			if (tetromino.GameOver()) {
				end();
			}
			tetromino.HandleBottomCollision(tetromino);
			if (GameBoard::play_cleared_sound == true) {
				row_cleared_sound.play();
				GameBoard::play_cleared_sound = false;
			}
			else {
				tetromino_set_sound.play();
			}
			tetromino.reset();
		}
		frame_number = ofGetElapsedTimeMillis();
	}

	sound.setPaused(music_paused);
	sound.setSpeed(1 + GameBoard::sound_speed);
}

//--------------------------------------------------------------
void ofApp::draw(){
	background.draw(0, 0, 2000, 1500);
	GameBoard::draw();
	tetromino.draw();

	// For loading and updating score panel.
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
		font.drawString(ofApp::score, 682, 130);
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
	soundgameover.play();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	vector<GameBlock> transformed_tiles;
	
	switch (key) {
	case 'p':
		gamePaused = !gamePaused;
		music_paused = !music_paused;
		break;
	case 'm':
		music_paused = !music_paused;
		break;
	case OF_KEY_DOWN:
		transformed_tiles = tetromino.MoveDown();
		bool bottom_collision = tetromino.BottomCollision(transformed_tiles, GameBoard::k_height);
		if (!bottom_collision && !gameOver) {
			tetromino.tiles = transformed_tiles;
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
		transformed_tiles = tetromino.MoveLeft();

		bool left_collision = tetromino.LeftCollision(transformed_tiles, 0);

		if (!left_collision) {
			tetromino.tiles = transformed_tiles;
		}
		break;
	}
	switch (key) {
	case OF_KEY_RIGHT:
		transformed_tiles = tetromino.MoveRight();

		bool right_collision = tetromino.RightCollision(transformed_tiles, GameBoard::k_width);

		if (!right_collision) {
			tetromino.tiles = transformed_tiles;
		}
		break;
	}
	switch (key) {
	case OF_KEY_ALT:
		transformed_tiles = tetromino.Rotate();

		bool left_collision = tetromino.LeftCollision(transformed_tiles, 0);
		bool right_collision = tetromino.RightCollision(transformed_tiles, GameBoard::k_width);
		bool bottom_collision = tetromino.BottomCollision(transformed_tiles, GameBoard::k_height);

		if (!left_collision && !left_collision && !bottom_collision) {
			tetromino.tiles = transformed_tiles;
		}
		break;
	}
	switch (key) {
	case OF_KEY_CONTROL:
		transformed_tiles = tetromino.RotateCCW();

		bool left_collision = tetromino.LeftCollision(transformed_tiles, 0);
		bool right_collision = tetromino.RightCollision(transformed_tiles, GameBoard::k_width);
		bool bottom_collision = tetromino.BottomCollision(transformed_tiles, GameBoard::k_height);

		if (!left_collision && !left_collision && !bottom_collision) {
			tetromino.tiles = transformed_tiles;
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
