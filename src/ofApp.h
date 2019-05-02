#pragma once
#include "C:\Users\akashpatel\Desktop\of_v0.10.1_vs2017_release\apps\myApps\Tetris final project\gameboard.hpp"
#include "ofMain.h"
#include "C:\Users\akashpatel\Desktop\of_v0.10.1_vs2017_release\apps\myApps\Tetris final project\tetromino.hpp"


class ofApp : public ofBaseApp{

	public:
		static int num_cols; // Number of columns on the game board.
		static int num_rows; // Number of rows on the game board.
		int speed; // Speed that is initially set for the start of the game.
	
		const int max_game_speed = 350; // Max speed the tetrominoes can fall at. 

		std::string score; // represents the current score during the game.
		std::string time_elapsed; // Represents the time elapsed during the game.
		std::string level; // Represents the current level during the game. 

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

		Tetromino tetromino;

		ofSoundPlayer sound; // Sound for background/
		ofSoundPlayer row_cleared_sound; // Sound object for cleared row sound effect.
		ofSoundPlayer tetromino_set_sound; // Sound object for tetromino set sound effect.
		ofSoundPlayer soundgameover; // Sound object for gameover sound effect.
		
		ofTrueTypeFont font;

		ofImage background;

		bool gamePaused; // True if game is paused. 
		bool gameOver; // True if game is over. 
		bool music_paused; // True if music is paused. 

		unsigned long long frame_number;
};

