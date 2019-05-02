#pragma once
//#include "ofMain.h"
#include "gameblock.hpp"
#include "gameboard.hpp"
#include "tetrominoshape.hpp"

class Tetromino {
public:
	Tetromino();

	void draw();
	void reset();
	
	const int k_middle_x_coordinate = 240; // X coordinate for the middle of the game board. 
	bool GameOver(); // Checks to see if the game is over. 

	vector<GameBlock> tiles; // Vector of Gameblocks for one tetromino. 

	vector<GameBlock> Rotate(); // Return a vector of rotated game blocks. 
	vector<GameBlock> RotateCCW(); // Retrun a vector of counterclockwise rotated game blocks.
	vector<GameBlock> MoveLeft(); // Return a vector of left translated game blocks. 
	vector<GameBlock> MoveRight(); // Return a vector of right translated game blocks. 
	vector<GameBlock> MoveDown(); // Return a vector of down tranlsated game blocks. 

	bool RightCollision(vector<GameBlock> transformedTiles, int width); // Checks for collisions to the right.
	bool LeftCollision(vector<GameBlock> transformedTiles, int width); // Checks for collisions to the leftt.
	bool BottomCollision(vector<GameBlock> transformedTiles, int width); // Checks for collisions below. 

	// Handles bottom collision by setting the tetromino to the game board.
	void HandleBottomCollision(Tetromino tetronimo); 
	
	// Sets the tiles to a random tetromino with a random color. 
	void CreateTetronimo(vector<ofPoint> randomshape);

	ofColor TetrominoColor(); // Color of the tetromino. 

};