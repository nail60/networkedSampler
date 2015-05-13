#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT0 12344
#define NUM_MSG_STRINGS 20

#define HOST ""
#define PORT 12345
#define PORT1 12346
#define PORT2 12347
#define PORT3 12348
#define PORT4 12349
#define HOST1 "192.168.1.51"
#define HOST2 "192.168.1.52"
#define HOST3 "192.168.1.53"
#define HOST4 "192.168.1.54"
#define HOST5 "192.168.1.55"



//--------------------------------------------------------
class ofApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void blast(ofxOscMessage m);
    
        int current_msg_string;
        string msg_strings[NUM_MSG_STRINGS];
        float timers[NUM_MSG_STRINGS];
    
        ofxOscReceiver receiver;

		ofTrueTypeFont font;
		ofxOscSender sender;
        ofxOscSender sender1;
        ofxOscSender sender2;
        ofxOscSender sender3;
        ofxOscSender sender4;
        ofxOscSender senderR;
        ofxOscSender sender1R;
        ofxOscSender sender2R;
        ofxOscSender sender3R;
        ofxOscSender sender4R;
        ofBuffer imgAsBuffer;
        ofImage img;
        bool touching;
        bool touchingPreviously;
        bool externalTrigger;
        bool externalTriggerPreviously;
    
    
};

