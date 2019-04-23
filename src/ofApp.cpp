#include "ofApp.h"



ofImage background;

int ofApp::numCols = 15;
int ofApp::numRows = 23;

//--------------------------------------------------------------
void ofApp::setup(){
	sound.load("no.mp3");
	background.load("images/background.jpg");

	ofSetWindowShape(800, 1000);
	ofSetWindowPosition(10, 10);
	GameBoard::InitiateBoard(numCols, numRows);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	background.draw(0, 0, 2000, 1500);

	GameBoard::draw();
	tetromino.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'p') {
		sound.play();
	} 
	if (key = 's') {
		sound.stop();
	}
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
