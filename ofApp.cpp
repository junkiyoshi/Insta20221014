#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int i = 0; i < 23; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		int span = 1;
		int len = ofRandom(1, span);

		for (int k = 0; k < 18; k += span) {

			ofSetColor(255, ofMap(abs(9 - k), 0, 9, 0, 255));

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.008), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.008), 0, 1, -350, 350));

			auto next = glm::vec2(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k + len) * 0.008), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k + len) * 0.008), 0, 1, -350, 350));

			ofDrawLine(location, next);

			ofSetColor(255);
			if (k == 9) {

				ofDrawCircle(location, 2);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}