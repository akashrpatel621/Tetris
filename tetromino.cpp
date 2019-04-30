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

//code for both rotations derived from 
//https://stackoverflow.com/questions/233850/tetris-piece-rotation-algorithm.
vector<GameBlock> Tetromino::Rotate()
{
	vector<GameBlock> rotated_tiles = tiles;

	int X = rotated_tiles[0].x;
	int Y = rotated_tiles[0].y;

	for (int i = 0; i < rotated_tiles.size(); i++) {
		if (X > rotated_tiles[i].x) {
			X = rotated_tiles[i].x;
		}
		if (Y > rotated_tiles[i].y) {
			Y = rotated_tiles[i].y;
		}
	}

	X += GameBlock::k_width;
	Y += GameBlock::k_height;

	int translatedX;
	int translatedY;
	int rotatedX;
	int rotatedY;

	for (int i = 0; i < rotated_tiles.size(); i++) {

		translatedX = rotated_tiles[i].x - X;
		translatedY = rotated_tiles[i].y - Y;

		rotatedX = translatedY;
		rotatedY = translatedX * -1;

		rotated_tiles[i].x = rotatedX + X;
		rotated_tiles[i].y = rotatedY + Y;
	}
	return rotated_tiles;
}

vector<GameBlock> Tetromino::RotateCCW()
{

	vector<GameBlock> rotated_tiles = tiles;
	int originX = rotated_tiles[0].x;

	int originY = rotated_tiles[0].y;



	for (int i = 0; i < rotated_tiles.size(); i++) {

		if (originX > rotated_tiles[i].x) {

			originX = rotated_tiles[i].x;

		}

		if (originY > rotated_tiles[i].y) {

			originY = rotated_tiles[i].y;

		}

	}



	originX += GameBlock::k_width;

	originY += GameBlock::k_height;



	int translatedX, translatedY;

	int rotatedX, rotatedY;



	for (int i = 0; i < rotated_tiles.size(); i++) {



		// Translate tile coordinates to rotation origin.

		translatedX = rotated_tiles[i].x - originX;

		translatedY = rotated_tiles[i].y - originY;



		// Apply rotation matrix to translated coordinates.

		rotatedX = translatedY * -1;

		rotatedY = translatedX;



		// Revert translation and apply new coordinates to tile.

		rotated_tiles[i].x = rotatedX + originX;

		rotated_tiles[i].y = rotatedY + originY;

	}



	return rotated_tiles;

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
			
			int x = (transformedTiles[i].x / 40);
			int y = (transformedTiles[i].y / 40);
			if (x >= 15) {
				return true;
			}
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
			if (x >= 15) {
				return true;
			}
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


