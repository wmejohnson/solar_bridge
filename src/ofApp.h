#pragma once

#include "ofMain.h"
#include "ofxGUI.h"
#include "vineFella.hpp"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void reset();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
    //gui stuff
    bool drawGUI;
    ofxPanel gui;
    ofParameter<int> nVines;
    ofParameter<float> speed;
    ofParameter<float> wobble;
    ofParameter<float> gravity;
    
    ofParameterGroup backgroundColor;
    ofParameter<int> br;
    ofParameter<int> bg;
    ofParameter<int> bb;
    
    ofParameterGroup strokeColor;
    ofParameter<int> sr;
    ofParameter<int> sg;
    ofParameter<int> sb;
    
    ofParameterGroup attractorPos;
    ofParameter<float> x;
    ofParameter<float> y;
    
    //"vines"
    vector<vine> vines;
    ofVec3f attractor;
    
    //
    int run;
    
    //post-process
    ofFbo fbo;
    ofShader s;
};
