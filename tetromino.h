#pragma once
#include "ofMain.h"
#include "gameblock.h"
#include "tetronimo_shape.h"



class Tetromino {
public:
	Tetromino();
	~Tetromino();
	void draw();
	void reset();

	vector<GameBlock> calculateRotationCW();
	vector<GameBlock> calculateRotationCCW();
	vector<GameBlock> calculateTranslationL();
	vector<GameBlock> calculateTranslationR();
	vector<GameBlock> calculateTranslationD();

	void transform(vector<GameBlock> transformedTiles);
	void drop(vector<GameBlock> transformedTiles);
	vector<GameBlock> tiles;

	int totalDrops = 0;
	void CreateTetronimo(vector<ofPoint> randomshape);
private:
};