#include "ofApp.h"

//this code is in a state of temporary disrepair.

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(40, 100, 40);
    //Reciever STUFF
    current_msg_string = 0;
    // listen on the given port
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT0);

	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
    cout << "1" << endl;
    sender1.setup(HOST, PORT1);
     cout << "2" << endl;
    sender2.setup(HOST, PORT2);
     cout << "3" << endl;
    sender3.setup(HOST, PORT3);
     cout << "4" << endl;
    sender4.setup(HOST, PORT4);
     cout << "5" << endl;
    senderR.setup(HOST1, PORT1);
     cout << "6" << endl;
    sender1R.setup(HOST2, PORT1);
     cout << "7" << endl;
    sender2R.setup(HOST3, PORT1);
     cout << "8" << endl;
    sender3R.setup(HOST4, PORT1);
     cout << "9" << endl;
    sender4R.setup(HOST5, PORT1);
     cout << "10" << endl;
    
    touching = false;
    touchingPreviously = false;
    externalTrigger = false;
    externalTriggerPreviously = false;
    
    
    cout << "printout" << endl;

}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        
        //Check is tree is being touched
        if (m.getAddress() == "/self") {
            cout << m.getAddress() << m.getArgAsInt32(0) << endl;
            int value = m.getArgAsInt32(0);
            if (value==1) touching = true;
            if (value==0) touching = false;
        }
        //Check if other tree is being touched
        else if (m.getAddress() == "/external") {
            cout << m.getAddress() << m.getArgAsInt32(0) << endl;
            int value = m.getArgAsInt32(0);
            if (value==1) externalTrigger = true;
            if (value==0) externalTrigger = false;
        }
        
    }

}

void ofApp::blast(ofxOscMessage m){
    sender.sendMessage(m);
    sender1.sendMessage(m);
    sender2.sendMessage(m);
    sender3.sendMessage(m);
    sender4.sendMessage(m);
    senderR.sendMessage(m);
    sender1R.sendMessage(m);
    sender2R.sendMessage(m);
    sender3R.sendMessage(m);
    sender4R.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //This code is currently in a state of disrepair.
    
//    if (touching) {
//        ofxOscMessage m;
//        m.setAddress("/self");
//        m.addIntArg(1);
//        blast(m);
//    } else {
//        ofxOscMessage m;
//        m.setAddress("/self");
//        m.addIntArg(0);
//        blast(m);
//    }
//    
//    if (externalTrigger) {
//        ofxOscMessage m;
//        m.setAddress("/external");
//        m.addIntArg(1);
//        blast(m);
//    } else {
//        ofxOscMessage m;
//        m.setAddress("/external");
//        m.addIntArg(0);
//        blast(m);
//    }
    
    

    
	// display instructions
	string buf;
	buf = "sending osc messages to" + string(HOST) + ofToString(PORT);
	ofDrawBitmapString(buf, 10, 20);
	ofDrawBitmapString("move the mouse to send osc message [/mouse/position <x> <y>]", 10, 50);
	ofDrawBitmapString("click to send osc message [/mouse/button <button> <\"up\"|\"down\">]", 10, 65);
	ofDrawBitmapString("press A to send osc message [/test 1 3.5 hello <time>]", 10, 80);
	ofDrawBitmapString("press I to send a (small) image as a osc blob to [/image]", 10, 95);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "pressed" << endl;
	if(key == '1'){
        ofxOscMessage m;
        m.setAddress("/self");
        m.addIntArg(1);
        sender.sendMessage(m);
        senderR.sendMessage(m);
        touching = true;
	}
    if(key == 'q'){
        ofxOscMessage m;
        m.setAddress("/external");
        m.addIntArg(1);
        sender.sendMessage(m);
        senderR.sendMessage(m);
        externalTrigger = true;
    }
    if(key == '2'){
        ofxOscMessage m;
        m.setAddress("/self");
        m.addIntArg(1);
        sender1.sendMessage(m);
        sender1R.sendMessage(m);
        //touching = true;
    }
    if(key == 'w'){
        ofxOscMessage m;
        m.setAddress("/external");
        m.addIntArg(1);
        sender1.sendMessage(m);
        sender1R.sendMessage(m);
        //externalTrigger = true;
    }
    if(key == '3'){
        ofxOscMessage m;
        m.setAddress("/self");
        m.addIntArg(1);
        sender2.sendMessage(m);
        sender2R.sendMessage(m);
        //touching = true;
    }
    if(key == 'e'){
        ofxOscMessage m;
        m.setAddress("/external");
        m.addIntArg(1);
        sender2.sendMessage(m);
        sender2R.sendMessage(m);
        //externalTrigger = true;
    }
    if(key == '4'){
        ofxOscMessage m;
        m.setAddress("/self");
        m.addIntArg(1);
        sender3.sendMessage(m);
        sender3R.sendMessage(m);
        //touching = true;
    }
    if(key == 'r'){
        ofxOscMessage m;
        m.setAddress("/external");
        m.addIntArg(1);
        sender3.sendMessage(m);
        sender3R.sendMessage(m);
        //externalTrigger = true;
    }
    if(key == '5'){
        ofxOscMessage m;
        m.setAddress("/self");
        m.addIntArg(1);
        sender4.sendMessage(m);
        sender4R.sendMessage(m);
        //touching = true;
    }
    if(key == 't'){
        ofxOscMessage m;
        m.setAddress("/external");
        m.addIntArg(1);
        sender4.sendMessage(m);
        sender4R.sendMessage(m);
        //externalTrigger = true;
    }

//    //send an image. (Note: the size of the image depends greatly on your network buffer sizes - if an image is too big the message won't come through )
//
//    if( key == 'i' || key == 'I'){
//        img.loadImage(imgAsBuffer);
//
//        ofxOscMessage m;
//        m.setAddress("/image");
//        m.addBlobArg(imgAsBuffer);
//        sender.sendMessage(m);
//        cout << "ofApp:: sending image with size: " << imgAsBuffer.size() << endl;
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    cout << "released" << endl;
    
    if (key=='1' || key=='2' || key=='3' || key=='4' || key=='5') {
        ofxOscMessage m;
        m.setAddress("/self");
        m.addIntArg(0);
        blast(m);
        touching=false;
    }
    if (key=='q' || key=='w' || key=='e' || key=='r' || key=='t'){
        ofxOscMessage m;
        m.setAddress("/external");
        m.addIntArg(0);
        blast(m);
        externalTrigger=false;
    }
    

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
//	ofxOscMessage m;
//	m.setAddress("/mouse/position");
//	m.addIntArg(x);
//	m.addIntArg(y);
//	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//	ofxOscMessage m;
//	m.setAddress("/mouse/button");
//	m.addStringArg("down");
//	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//	ofxOscMessage m;
//	m.setAddress("/mouse/button");
//	m.addStringArg("up");
//	sender.sendMessage(m);

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

