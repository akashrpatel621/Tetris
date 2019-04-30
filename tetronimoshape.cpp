#include "tetronimoshape.h"

static vector<vector<ofPoint>> tetromino_shape_points;

vector<ofPoint> Shape::GetRandomShape()
{
	if (tetromino_shape_points.empty()) {

		vector<ofPoint> I;
		I.push_back(ofPoint(0, 0));
		I.push_back(ofPoint(0, GameBlock::k_height));
		I.push_back(ofPoint(0, GameBlock::k_height * 2));
		I.push_back(ofPoint(0, GameBlock::k_height * 3));
		tetromino_shape_points.push_back(I);

		vector<ofPoint> O;
		O.push_back(ofPoint(0, 0));
		O.push_back(ofPoint(0, GameBlock::k_height));
		O.push_back(ofPoint(GameBlock::k_width, 0));
		O.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height));
		tetromino_shape_points.push_back(O);

		vector<ofPoint> T;
		T.push_back(ofPoint(0, GameBlock::k_height));
		T.push_back(ofPoint(GameBlock::k_width, 0));
		T.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height));
		T.push_back(ofPoint(GameBlock::k_width * 2, GameBlock::k_height));
		tetromino_shape_points.push_back(T);
			   
		vector<ofPoint> J;
		J.push_back(ofPoint(GameBlock::k_width, 0));
		J.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height));
		J.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height * 2));
		J.push_back(ofPoint(0, GameBlock::k_height * 2));
		tetromino_shape_points.push_back(J);

		vector<ofPoint> L;
		L.push_back(ofPoint(0, 0));
		L.push_back(ofPoint(0, GameBlock::k_height));
		L.push_back(ofPoint(0, GameBlock::k_height * 2));
		L.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height * 2));
		tetromino_shape_points.push_back(L);

		vector<ofPoint> S;
		S.push_back(ofPoint(0, GameBlock::k_height));
		S.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height));
		S.push_back(ofPoint(GameBlock::k_width, 0));
		S.push_back(ofPoint(GameBlock::k_width * 2, 0));
		tetromino_shape_points.push_back(S);

		vector<ofPoint> Z;
		Z.push_back(ofPoint(0, 0));
		Z.push_back(ofPoint(GameBlock::k_width, 0));
		Z.push_back(ofPoint(GameBlock::k_width, GameBlock::k_height));
		Z.push_back(ofPoint(GameBlock::k_width * 2, GameBlock::k_height));
		tetromino_shape_points.push_back(Z);
	}
	int random_shap_index = ofRandom(0, tetromino_shape_points.size());
	return tetromino_shape_points[random_shap_index];
}

