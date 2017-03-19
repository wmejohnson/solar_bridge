//
//  vineFella.cpp
//  solar_bridge
//
//  Created by Will Johnson on 3/16/17.
//
//

#include "vineFella.hpp"

vine::vine(){
    //init a random start position along one of the edges of the screen
    // && init a direction vector based on the edge chosen
    float temp;
    energy = ofRandom(20.0, 100.0);
    if(ofRandom(1.0) > 0.5){
        // top / bottom
        temp = (int)ofRandom(2.1);
        if(temp == 0){
            temp = -20;
        } else {
            temp = ofGetHeight() + 20;
        }
        startLocation = ofVec3f(ofRandom(ofGetWidth()), temp, 0.0);
        points.push_back(startLocation + (ofVec3f(1.0, 0.0, 0.0) * (energy*0.15)));
        points.push_back(startLocation - (ofVec3f(1.0, 0.0, 0.0) * (energy*0.15)));
    } else {
        // left /right
        temp = (int)ofRandom(2.1);
        if(temp == 0){
            temp = -20;
        } else {
            temp = ofGetWidth() + 20;
        }
        startLocation = ofVec3f(temp ,ofRandom(ofGetHeight()), 0.0);
        points.push_back(startLocation + (ofVec3f(0.0, 1.0, 0.0) * (energy*0.15)));
        points.push_back(startLocation - (ofVec3f(0.0, 1.0, 0.0) * (energy*0.15)));
    }

    localSpeed = ofRandom(0.3, 2.0);
    seed = (int)ofRandom(1000);
    wobbleVec = ofVec3f(0.0);
    currentLocation = startLocation;
    
}

void vine::setup(){
}

void vine::update(float speed, float gravity, float wobble, ofVec3f a){
    //with this they stop at the center
    destination = a;
    ofVec3f distance = destination - currentLocation;
    direction = distance.normalize();
    
    //wobble
    float t = ofGetElapsedTimef();
    ofVec3f perpDirection = ofVec3f(direction.y, -direction.x, 0);
    wobbleVec = perpDirection * (ofNoise(t, seed)*2.0-1.0);
    
    //main update loop
    if(energy > 0){
        //update location
        currentLocation += (direction * speed * localSpeed) + (wobbleVec * wobble) + (ofVec3f(0.0, 1.0, 0.0)*gravity);
    
        //update width
        //buldge effect
        
        //come to points
        //only kinda working ...
        
        //insert new points
        if(ofGetFrameNum() % 5 == 0){
            points.insert(points.begin() + points.size()/2, currentLocation + (perpDirection * (energy*0.15) + (ofNoise(t, seed*2))*3));
            points.insert(points.begin() + points.size()/2, currentLocation - (perpDirection * (energy*0.15)+ (ofNoise(t, seed*2))*3));
        }
        //energy
        energy-=1/(0.7+localSpeed);
    } else {
        //round off the end?
        
    }
}

void vine::draw(ofColor fill){
    //polyline implementation - i can't easily fill this
//    ofPolyline lineInner = ofPolyline(points);
//    lineInner.close();
//    lineInner.draw();
    
    //ofPath implementation - i can fill this
    ofPath path;
    path.moveTo(points[0]);
    for(int i = 1; i < points.size(); ++i){
        path.lineTo(points[i]);
    }
    path.setColor(fill);
    path.close();
    path.draw();

    ofSetLineWidth(3.0);
    ofSetColor(0, 0, 0);
    ofPolyline lineOuter = ofPolyline(points);
    lineOuter.draw();
//    
    //SetLineWidth dropped from openGL standard starting with 3
    //ofSetLineWidth(ofNoise(ofGetElapsedTimef() * 0.5, seed) * 10.0);
}
