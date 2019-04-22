#pragma once
#include "C:\Users\akashpatel\Desktop\of_v0.10.1_vs2017_release\apps\myApps\Tetris final project\gameboard.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		static int numCols;
		static int numRows;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


};

