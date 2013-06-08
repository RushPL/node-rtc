#ifndef PEERCONNECTION_CLIENT_H
#define PEERCONNECTION_CLIENT_H

#include <node.h>

class PeerConnection : public node::ObjectWrap {
  public:
    static void Init(v8::Handle<v8::Object> exports);
  private:
    PeerConnection();
    ~PeerConnection();
    
    // New Object
    static v8::Handle<v8::Value> New(const v8::Arguments& args);

    // fake method
    static v8::Handle<v8::Value> PlusOne(const v8::Arguments& args);
};

#endif
