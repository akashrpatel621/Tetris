#include "tetromino.h"
#include "ofApp.h"

Tetromino::Tetromino()
{
	reset();
}

void Tetromino::draw()
{
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i].draw();
	}
}

void Tetromino::reset()
{
	tiles.clear();
	vector<ofPoint> random = Shape::GetRandomShape();
	CreateTetronimo(random);
}

//code derived from 
//https://stackoverflow.com/questions/233850/tetris-piece-rotation-algorithm.
vector<GameBlock> Tetromino::Rotate()
{
	vector<GameBlock> rotatedTiles = tiles;

	int X = rotatedTiles[0].x;
	int Y = rotatedTiles[0].y;

	for (int i = 0; i < rotatedTiles.size(); i++) {
		if (X > rotatedTiles[i].x) {
			X = rotatedTiles[i].x;
		}
		if (Y > rotatedTiles[i].y) {
			Y = rotatedTiles[i].y;
		}
	}

	X += GameBlock::k_width;
	Y += GameBlock::k_height;

	int translatedX;
	int translatedY;
	int rotatedX;
	int rotatedY;

	for (int i = 0; i < rotatedTiles.size(); i++) {

		translatedX = rotatedTiles[i].x - X;
		translatedY = rotatedTiles[i].y - Y;

		rotatedX = translatedY;
		rotatedY = translatedX * -1;

		rotatedTiles[i].x = rotatedX + X;
		rotatedTiles[i].y = rotatedY + Y;
	}
	return rotatedTiles;
}


vector<GameBlock> Tetromino::MoveLeft()
{
	vector<GameBlock> translatedTiles = tiles;

	for (int i = 0; i < translatedTiles.size(); i++) {
		translatedTiles[i].x = translatedTiles[i].x - GameBlock::k_width;
	}
	return translatedTiles;
}

vector<GameBlock> Tetromino::MoveRight()
{
	vector<GameBlock> translatedTiles = tiles;

	for (int i = 0; i < translatedTiles.size(); i++) {
		translatedTiles[i].x += GameBlock::k_width;
	}
	return translatedTiles;
}

vector<GameBlock> Tetromino::MoveDown()
{
	vector<GameBlock> translatedTiles = tiles;

	for (int i = 0; i < translatedTiles.size(); i++) {
		translatedTiles[i].y += GameBlock::k_height;
	}
	return translatedTiles;
}

bool Tetromino::RightCollison(vector<GameBlock> transformedTiles, int width)
{
	for (int i = 0; i < transformedTiles.size(); i++) {
		if (transformedTiles[i].x >= width) {
			return true;
		}
		else {
			int x = transformedTiles[i].x / 40;
			int y = transformedTiles[i].y / 40;
			GameBlock t = GameBoard::board[x][y];
			if (t.fill != ofColor::black) {
				return true;
			}
		}
	}
	return false;
}

bool Tetromino::LeftCollison(vector<GameBlock> transformedTiles, int width)
{
	for (int i = 0; i < transformedTiles.size(); i++) {
		if (transformedTiles[i].x < 0) {
			return true;;
		}
		else {
			
			int x = transformedTiles[i].x / 40;
			int y = transformedTiles[i].y / 40;
			GameBlock t = GameBoard::board[x][y];
			if (t.fill != ofColor::black) {
				return true;
			}
		}
	}
	return false;
}

bool Tetromino::BottomCollison(vector<GameBlock> transformedTiles, int width)
{
	
	for (int i = 0; i < transformedTiles.size(); i++) {
		if (transformedTiles[i].y >= width) {
			return true; // there is a collision on the bottom.
		}
		else
		{
			
			int x = transformedTiles[i].x / 40;
			int y = transformedTiles[i].y / 40;
			GameBlock t = GameBoard::board[x][y];
			if (t.fill != ofColor::black) {
				return true;
			}
		}
	}
	return false;
}

bool Tetromino::GameOver()
{
	for (int i = 0; i <tiles.size(); i++) {
		if (tiles[i].y == 0) {
			return true;
		}
	}
	return false;
}

void Tetromino::HandleBottomCollision(Tetromino tetromino)
{
	for (int i = 0; i < tetromino.tiles.size(); i++) {
		GameBoard::board[tetromino.tiles[i].x / GameBlock::k_width][tetromino.tiles[i].y / GameBlock::k_height].fill = tetromino.tiles[i].fill;
	}
	GameBoard::RemoveRow(ofApp::numCols , ofApp::numRows);
}

ofColor Tetromino::TetrominoColor()
{
	vector <ofColor> colors = {
		ofColor::blue,
		ofColor::red,
		ofColor::orange,
		ofColor::green,
		ofColor::yellow
	};

	int color_index = ofRandom(0, colors.size());
	return colors[color_index];
	
}

void Tetromino::CreateTetronimo(vector<ofPoint> randomshape)
{
	ofColor random_color = TetrominoColor();
	for (int i = 0; i < randomshape.size(); i++) {
		tiles.push_back(GameBlock(ofPoint(randomshape[i].x + 240, randomshape[i].y), random_color, ofColor::white));
	}
}


