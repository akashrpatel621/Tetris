#pragma once
#include "gameblock.hpp"

class GameBoard {

public:
	GameBoard() {};

	static const int k_height; // Height of game board.
	static const int k_width; // Width of game board.

	static int game_speed; // Speed the tetromino blocks will fall at. 
	static double sound_speed; //Music playback offset speed.
	static bool play_cleared_sound; // Bool to indicate when to play the "cleared" sound effect.
	static int score; // Score counter.
	static int level; // Level counter. 

	static vector< vector<GameBlock> > board; // 2D vector of Game blocks that make up the game board.

	static void draw(); // Draws graphical representation of the game board. 
	static void InitiateBoard(int num_rows, int num_cols); // Construct the game board with given parameters.
	static void SlideDown(int row, int cols); // Slides down blocks on the game board. 
	static void RemoveRow(int rows, int cols); // Removes a row of filled blocks on the game board.
};