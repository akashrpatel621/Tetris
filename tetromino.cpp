#include "tetromino.h"

Tetromino::Tetromino()
{
	reset();
}

Tetromino::~Tetromino()
{
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
	totalDrops = 0;
}

vector<GameBlock> Tetromino::calculateRotationCW()
{
	return vector<GameBlock>();
}

vector<GameBlock> Tetromino::calculateRotationCCW()
{
	return vector<GameBlock>();
}

vector<GameBlock> Tetromino::calculateTranslationL()
{
	return vector<GameBlock>();
}

vector<GameBlock> Tetromino::calculateTranslationR()
{
	return vector<GameBlock>();
}

vector<GameBlock> Tetromino::calculateTranslationD()
{
	return vector<GameBlock>();
}

void Tetromino::transform(vector<GameBlock> transformedTiles)
{
}

void Tetromino::drop(vector<GameBlock> transformedTiles)
{
}

void Tetromino::CreateTetronimo(vector<ofPoint> randomshape)
{

	ofColor colors[5] = {
		ofColor::blue,
		ofColor::red,
		ofColor::orange,
		ofColor::green,
		ofColor::yellow
	};

	int color_index = ofRandom(0, randomshape.size());

	for (int i = 0; i < randomshape.size(); i++) {
		tiles.push_back(GameBlock(randomshape[i], colors[color_index], ofColor::white));
	}
}
