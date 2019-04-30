#pragma once

#include "ofMain.h"

class GameBlock {

public:
	// Height and width of a game block. 
	static const int k_width = 40;
	static const int k_height = 40;

	// Block constructor.
	GameBlock(ofPoint point, ofColor fill_color, ofColor outline_color = ofColor::darkTurquoise);

	// X and Y coordinates for the game block location.
	int x; 
	int y; 

	ofColor fill; // Fill color for the game block.
	ofColor outline; // Outline color for the game block.

	void draw(); // Draws a game block.

};