#include "peerconnection.h"

using namespace v8;

void NodeRTCPeerconnection::Init(Handle<Object> exports) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("NodeRTCPeerconnection"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  //Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("NodeRTCPeerconnection"), tpl->GetFunction());

}

Handle<Value> NodeRTCPeerconnection::New(const Arguments& args) {
  HandleScope scope;
  return scope.Close(args.This());
}
