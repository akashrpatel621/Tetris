#pragma once
#include "gameblock.h"

class GameBoard {

public:
	GameBoard() {};

	static const int k_height;
	static const int k_width;

	static int game_speed;
	static double sound_speed;
	static bool play_cleared_sound;
	static int score;
	static int level;

	static vector< vector<GameBlock> > board;

	static void draw();
	static void InitiateBoard(int rows, int cols);
	static void SlideDown(int row, int cols);
	static void RemoveRow(int rows, int cols);
private:
};