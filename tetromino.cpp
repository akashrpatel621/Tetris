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

	int initial_x = rotated_tiles[0].x;
	int initial_y = rotated_tiles[0].y;

	for (int i = 0; i < rotated_tiles.size(); i++) {
		if (initial_x > rotated_tiles[i].x) {
			initial_x = rotated_tiles[i].x;
		}
		if (initial_y > rotated_tiles[i].y) {
			initial_y = rotated_tiles[i].y;
		}
	}

	initial_x += GameBlock::k_width;
	initial_y += GameBlock::k_height;

	int translated_x;
	int translated_y;
	int rotated_x;
	int rotated_y;

	for (int i = 0; i < rotated_tiles.size(); i++) {

		translated_x = rotated_tiles[i].x - initial_x;
		translated_y = rotated_tiles[i].y - initial_y;

		rotated_x = translated_y;
		rotated_y = translated_x * -1;

		rotated_tiles[i].x = rotated_x + initial_x;
		rotated_tiles[i].y = rotated_y + initial_y;
	}
	return rotated_tiles;
}

vector<GameBlock> Tetromino::RotateCCW()
{
	vector<GameBlock> rotated_tiles = tiles;

	int initial_x = rotated_tiles[0].x;
	int initial_y = rotated_tiles[0].y;

	for (int i = 0; i < rotated_tiles.size(); i++) {
		if (initial_x > rotated_tiles[i].x) {
			initial_x = rotated_tiles[i].x;
		}
		if (initial_y > rotated_tiles[i].y) {
			initial_y = rotated_tiles[i].y;
		}
	}

	initial_x += GameBlock::k_width;
	initial_y += GameBlock::k_height;

	int translated_x;
	int translated_y;

	int rotated_x;
	int rotated_y;

	for (int i = 0; i < rotated_tiles.size(); i++) {
		translated_x = rotated_tiles[i].x - initial_x;
		translated_y = rotated_tiles[i].y - initial_y;

		rotated_x = translated_y * -1;
		rotated_y = translated_x;

		rotated_tiles[i].x = rotated_x + initial_x;
		rotated_tiles[i].y = rotated_y + initial_y;
	}
	return rotated_tiles;
}

vector<GameBlock> Tetromino::MoveLeft()
{
	vector<GameBlock> translated_tiles = tiles;

	for (int i = 0; i < translated_tiles.size(); i++) {
		translated_tiles[i].x = translated_tiles[i].x - GameBlock::k_width;
	}
	return translated_tiles;
}

vector<GameBlock> Tetromino::MoveRight()
{
	vector<GameBlock> translated_tiles = tiles;

	for (int i = 0; i < translated_tiles.size(); i++) {
		translated_tiles[i].x += GameBlock::k_width;
	}
	return translated_tiles;
}

vector<GameBlock> Tetromino::MoveDown()
{
	vector<GameBlock> translated_tiles = tiles;

	for (int i = 0; i < translated_tiles.size(); i++) {
		translated_tiles[i].y += GameBlock::k_height;
	}
	return translated_tiles;
}

bool Tetromino::RightCollision(vector<GameBlock> translated_tiles, int width)
{
	for (int i = 0; i < translated_tiles.size(); i++) {
		if (translated_tiles[i].x >= width) {
			return true;
		}
		else {
			int x = translated_tiles[i].x / 40;
			int y = translated_tiles[i].y / 40;
			GameBlock temp = GameBoard::board[x][y];
			if (temp.fill != ofColor::black) {
				return true;
			}
		}
	}
	return false;
}

bool Tetromino::LeftCollision(vector<GameBlock> translated_tiles, int width)
{
	for (int i = 0; i < translated_tiles.size(); i++) {
		if (translated_tiles[i].x < 0) {
			return true;;
		}
		else {
			int x = (translated_tiles[i].x / 40);
			int y = (translated_tiles[i].y / 40);

			if (x >= 15) {
				return true;
			}
			GameBlock temp = GameBoard::board[x][y];
			if (temp.fill != ofColor::black) {
				return true;
			}
		}
	}
	return false;
}

bool Tetromino::BottomCollision(vector<GameBlock> translated_tiles, int width)
{
	for (int i = 0; i < translated_tiles.size(); i++) {
		if (translated_tiles[i].y >= width) {
			return true; // there is a collision on the bottom.
		}
		else
		{
			int x = translated_tiles[i].x / 40;
			int y = translated_tiles[i].y / 40;

			if (x >= 15) {
				return true;
			}
			GameBlock temp = GameBoard::board[x][y];
			if (temp.fill != ofColor::black) {
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
	GameBoard::RemoveRow(15 , 23);
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
		tiles.push_back(GameBlock(ofPoint(randomshape[i].x + k_middle_x_coordinate, randomshape[i].y), random_color, ofColor::white));
	}
}


