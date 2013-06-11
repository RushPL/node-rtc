#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "client.h"

using namespace v8;

void Init(Handle<Object> exports) {
  Client::Init(exports);
}

NODE_MODULE(rtc, Init)
