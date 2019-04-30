#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "gameboard.h"
#include "tetromino.h"

//Testing initiation of game board.
TEST_CASE("Error in initiating game board") {
	GameBoard::InitiateBoard(10, 10);

	REQUIRE(GameBoard::board.size() == 10);
	REQUIRE(GameBoard::board[0].size() == 10);

	REQUIRE(GameBoard::board[0][0].fill == ofColor::black);
}

//Unfinished test for slide down. 
TEST_CASE("Error in SlideDown function") {
	GameBoard::InitiateBoard(15, 23);

	// Top row of the board is filled with the color blue. 
	for (int i = 0; i < GameBoard::board.size(); i++) {
		for (int j = 0; j < GameBoard::board[i].size(); j++) {
			GameBoard::board[i][j].fill = ofColor::blue;
		}
	}
	
	// Check if top row it filled with blue and the bottom is filled with black. 
	REQUIRE(GameBoard::board[0][0].fill == ofColor::blue);
	/*GameBoard::RemoveRow(15, 23);
	REQUIRE(GameBoard::board[0][0].fill == ofColor::black);*/
}


TEST_CASE("Error in shifting left") {
	Tetromino tetromino;
	vector <GameBlock> translated_tiles = tetromino.MoveLeft();
	
	REQUIRE(tetromino.tiles[0].x - GameBlock::k_width == translated_tiles[0].x);
	REQUIRE(tetromino.tiles[0].y == translated_tiles[0].y);
}

TEST_CASE("Error in shifting right") {
	Tetromino tetromino;
	vector <GameBlock> translated_tiles = tetromino.MoveRight();

	REQUIRE(tetromino.tiles[0].x  == translated_tiles[0].x - GameBlock::k_width);
	REQUIRE(tetromino.tiles[0].y == translated_tiles[0].y);
}

TEST_CASE("Error in shifting down") {
	Tetromino tetromino;
	vector <GameBlock> translated_tiles = tetromino.MoveDown();

	REQUIRE(tetromino.tiles[0].x == translated_tiles[0].x);
	REQUIRE(tetromino.tiles[0].y == translated_tiles[0].y - GameBlock::k_height);
}

