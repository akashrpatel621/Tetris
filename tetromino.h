#pragma once
#include "ofMain.h"
#include "gameblock.h"
#include "gameboard.h"
#include "tetronimoshape.h"



class Tetromino {
public:
	Tetromino();
	void draw();
	void reset();

	vector<GameBlock> Rotate();
	vector<GameBlock> RotateCCW();
	vector<GameBlock> MoveLeft();
	vector<GameBlock> MoveRight();
	vector<GameBlock> MoveDown();

	bool RightCollison(vector<GameBlock> transformedTiles, int width);
	bool LeftCollison(vector<GameBlock> transformedTiles, int width);
	bool BottomCollison(vector<GameBlock> transformedTiles, int width);

	bool GameOver();
	
	void HandleBottomCollision(Tetromino tetronimo);
	void CreateTetronimo(vector<ofPoint> randomshape);

	ofColor TetrominoColor();

	vector<GameBlock> tiles;
};