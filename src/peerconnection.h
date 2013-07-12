#ifndef NODE_RTC_PEERCONNECTION_H
#define NODE_RTC_PEERCONNECTION_H

#include <node.h>

class NodeRTCPeerconnection :
  public node::ObjectWrap {
    public:
      static void Init(v8::Handle<v8::Object> exports);
    private:
      static v8::Handle<v8::Value> New(const v8::Arguments& args);
};

#endif
