//
//  vineFella.hpp
//  solar_bridge
//
//  Created by Will Johnson on 3/16/17.
//
//

#ifndef vineFella_hpp
#define vineFella_hpp

#include "ofMain.h"
#include "ofxGUI.h"

#endif /* vineFella_hpp */

class vine{
public:
    vine();
    
    void setup();
    void update(float speed, float gravity, float wobble, ofVec3f a);
    void draw(ofColor fill);
    
    ofVec3f direction;
    ofVec3f startLocation;
    ofVec3f currentLocation;
    ofVec3f wobbleVec;
    ofVec3f destination;
    
    vector<ofPoint> points;
    int seed;
    
    float localSpeed;
    
    float energy;
};
