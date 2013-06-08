#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "PeerConnection.h"

using namespace v8;

void init(Handle<Object> exports) {
  PeerConnection::Init(exports);
}

NODE_MODULE(rtc, init)
