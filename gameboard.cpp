
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

void GameBoard::SlideDown(int row, int cols)
{
	for (int i = row; i >= 0; i--) {
		for (int j = 0; j < cols; j++) {
			if (i - 1 >= 0) {
				board[j][i].fill = board[j][i - 1].fill;
			}
			else {
				board[j][0].fill = ofColor::black;
			}
		}
	}
}

void GameBoard::RemoveRow(int cols, int rows)
{
	for (int i = rows - 1; i >= 0; i--) {
		bool isComplete = true;
		for (int j = 0; j < cols; j++) {
			if (board[j][i].fill == ofColor::black) {
				isComplete = false;
			}
		}
		if (isComplete) {
			GameBoard::SlideDown(i, cols);
			i++;
		}
	}
}