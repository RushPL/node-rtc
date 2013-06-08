#ifndef PEERCONNECTION_CLIENT_H
#define PEERCONNECTION_CLIENT_H

#include <node.h>
#include "../3d_party/libjingle/trunk/talk/app/webrtc/peerconnection.h"

class Client : public node::ObjectWrap {
  public:
    static void Init(v8::Handle<v8::Object> exports);
  private:
    Client();
    ~Client();
    
    // New Object
    static v8::Handle<v8::Value> New(const v8::Arguments& args);

    // fake method
    //static v8::Handle<v8::Value> PlusOne(const v8::Arguments& args);

    webrtc::PeerConnection* pc;
};

#endif
