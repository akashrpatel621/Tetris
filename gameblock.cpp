#include "gameblock.h"

GameBlock::GameBlock(ofPoint point, ofColor fill_color, ofColor outline_color)
{
	x = point.x;
	y = point.y;
	fill = fill_color;
	outline = outline_color;
};


void GameBlock::draw()
{
	ofPushStyle(); {
		ofFill();
		ofSetColor(fill); // fill color  
		ofDrawRectangle(x, y, k_width, k_height);
		ofNoFill();
		ofSetColor(outline); // contour (stroke) color  
		ofDrawRectangle(x, y, k_width, k_height);
	}; ofPopStyle();
};