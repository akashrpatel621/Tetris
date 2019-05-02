
#include "gameboard.hpp"

vector< vector<GameBlock> > GameBoard::board;

const int GameBoard::k_height = 920;
const int GameBoard::k_width = 600;

int GameBoard::game_speed = 0;
double GameBoard::sound_speed = 0;
bool GameBoard::play_cleared_sound = false;
int GameBoard::score = 0;
int GameBoard::level = 0;

void GameBoard::InitiateBoard(int num_col, int num_row)
{
	for (int i = 0; i < num_col; i++) {
		vector<GameBlock> board_row;
		for (int j = 0; j < num_row; j++) {
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
	int row_number;
	for (int i = rows - 1; i >= 0; i--) {
		bool row_filled = true;
		for (int j = 0; j < cols; j++) {
			if (board[j][i].fill == ofColor::black) {
				row_filled = false;
			}
		}
		if (row_filled) {
			GameBoard::SlideDown(i, cols);
			i++;
			GameBoard::game_speed -= 50;
			GameBoard::sound_speed += 0.10;
			GameBoard::play_cleared_sound = true;
			row_number = 23 - i;
			score += (40 * (row_number + 1)) * (level + 1);
			level++;

		}
	}
}