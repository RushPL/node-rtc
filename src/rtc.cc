#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "peerconnection.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  NodeRTCPeerconnection::Init(exports);
}

NODE_MODULE(rtc, InitAll)
