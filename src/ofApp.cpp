#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //gui
    gui.setup("solar bridge");
    gui.add(speed.set("speed", 1.0, 0.0, 5.0));
    gui.add(wobble.set("wobble", 1.0, 0.0, 5.0));
    gui.add(gravity.set("gravity", 0.0, 0.0, 5.0));
    gui.add(nVines.set("vinticles", 20, 1, 1000));
    
    //background color
    backgroundColor.add(br.set("red", 0, 0, 255));
    backgroundColor.add(bg.set("green", 0, 0, 255));
    backgroundColor.add(bb.set("blue", 0, 0, 255));
    backgroundColor.setName("background");
    
    //background color
    strokeColor.add(sr.set("red", 255, 0, 255));
    strokeColor.add(sg.set("green", 255, 0, 255));
    strokeColor.add(sb.set("blue", 255, 0, 255));
    strokeColor.setName("stroke");
    
    //attractor
    attractorPos.add(x.set("x", 0.5, 0.0, 1.0));
    attractorPos.add(y.set("y", 0.5, 0.0, 1.0));
    attractorPos.setName("attractor position");
    
    gui.add(backgroundColor);
    gui.add(strokeColor);
    gui.add(attractorPos);
    
    drawGUI = true;
    run = 1;
    
    //load shader
    s.load("shaders/shader");
    
    //vines
    attractor = ofVec3f(x*ofGetWidth(), y*ofGetHeight(), 0);
    vine temp;
    for(int i = 0; i < nVines; ++i){
        temp = vine();
        vines.push_back(temp);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    //update attractor
    attractor.x = x*ofGetWidth();
    attractor.y = y*ofGetHeight();
    
    // update my fellas
    for(vine &v : vines) {
        v.update(speed*run, gravity*run, wobble*run, attractor);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //framerate in bar
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    ofEnableAlphaBlending();

    //background
    ofBackground(br, bg, bb, 1.0);
    
    // draw my fellas
    ofSetColor(sr, sg, sb);
    for(vine v : vines) {
        v.draw(ofColor(sr, sg, sb));
    }
    
    s.begin();
    s.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    s.setUniform1f("u_time", ofGetElapsedTimef());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    s.end();

    if(drawGUI) gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'S':
            ofSaveScreen("ss/solar_bridge"+ofGetTimestampString()+".png");
            break;
        case 'g':
            if(drawGUI){
                drawGUI = false;
            } else {
                drawGUI = true;
            }
            break;
        case 'r':
            reset();
            break;
        case ' ':
            if(run){
                run = 0;
            } else {
                run = 1;
            }
        break;
        default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::reset(){
    vines.clear();
    vine temp;
    for(int i = 0; i < nVines; ++i){
        temp = vine();
        vines.push_back(temp);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
