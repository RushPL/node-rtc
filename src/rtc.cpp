#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "Client.h"

using namespace v8;

void init(Handle<Object> exports) {
  Client::Init(exports);
}

NODE_MODULE(rtc, init)
