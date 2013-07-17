#include "peerconnection.h"

using namespace v8;

void NodeRTCPeerconnection::Init(Handle<Object> exports) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("NodeRTCPeerconnection"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  exports->Set(String::NewSymbol("NodeRTCPeerconnection"), tpl->GetFunction());

}

Handle<Value> NodeRTCPeerconnection::New(const Arguments& args) {
  HandleScope scope;

  if(args.Length() != 2 || !args[0]->IsObject() || !args[1]->IsObject())
    return ThrowException(Exception::Error(String::New("Please check your arguments")));

  Handle<Object> serverConfigurations = Handle<Object>::Cast(args[0]);
  //Handle<Array> iceServersFromParam = serverConfigurations->Get(String::New("iceServers"));

  return scope.Close(args.This());
}
