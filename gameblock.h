#pragma once

#include "ofMain.h"

class GameBlock {

public:
	GameBlock(ofPoint point, ofColor fill_color, ofColor outline_color = ofColor::darkTurquoise);

	int x;
	int y;

	ofColor fill;
	ofColor outline;

	void draw();

	static const int k_width = 40;
	static const int k_height = 40;
};