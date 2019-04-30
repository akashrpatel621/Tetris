#pragma once
#include "ofMain.h"
#include "gameblock.h"

class Shape {
public:
	static vector<ofPoint> GetRandomShape(); // Generates all seven tetromino blocks then randomly selects one to return. 
};