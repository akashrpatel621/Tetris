#pragma once
#include "C:\Users\akashpatel\Desktop\of_v0.10.1_vs2017_release\apps\myApps\Tetris final project\gameboard.h"
#include "ofMain.h"
#include "C:\Users\akashpatel\Desktop\of_v0.10.1_vs2017_release\apps\myApps\Tetris final project\tetromino.h"

class ofApp : public ofBaseApp{

	public:
		static int numCols;
		static int numRows;
		int speed;
        //double time;

		std::string score;
		std::string time_elapsed;
		std::string level;

		void setup();
		void update();
		void draw();
		void end();

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
		void convertToString(int score);
		void TimeToString(double time);
		void LevelToString(int level);

		Tetromino tetromino;

		ofSoundPlayer sound;
		ofSoundPlayer soundclear;
		ofSoundPlayer sounddrop;
		ofSoundPlayer soundgameover;
		
		ofTrueTypeFont font;

		ofImage background;
		ofImage game_over;

		

		bool gamePaused;
		bool gameOver;
		bool musicpuased;

		

		unsigned long long frameNumber;
};

