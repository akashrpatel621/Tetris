
#include "gameboard.h"

// 2D vector of game block elemennts to create a game board.
vector< vector<GameBlock> > GameBoard::board;

const int GameBoard::k_height = 920;
const int GameBoard::k_width = 600;

void GameBoard::InitiateBoard(int col, int row)
{
	for (int i = 0; i < col; i++) {
		vector<GameBlock> board_row;
		for (int j = 0; j < row; j++) {
			board_row.push_back(GameBlock(ofPoint(i * GameBlock::k_width, j * GameBlock::k_height), ofColor::black));
		}
		board.push_back(board_row);
	}
}

void GameBoard::draw()
{
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j].draw();
		}
	}
}

void GameBoard::SlideDown(int rowIndex, int cols)
{
	// shift all blocks down
}

void GameBoard::RemoveRow(int cols, int rows)
{
	// replaces a full row with black spaces and also shifts down the other blocks. 
}