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

  webrtc::PeerConnectionInterface::IceServers iceServers;
  try {
    Handle<Object> firstParamObject = Handle<Object>::Cast(args[0]);
    Handle<Value> iceServerArrayValue = firstParamObject->Get(String::New("iceServers"));
    if(!iceServerArrayValue->IsArray()) throw -1;
    Handle<Array> iceServerArray = Handle<Array>::Cast(iceServerArrayValue);
    for(uint32_t i=0; i<iceServerArray->Length(); i++) {
      Handle<Value> currentServerValue = iceServerArray->Get(i);
      if(!currentServerValue->IsObject()) throw i;
      Handle<Object> currentServerObject = Handle<Object>::Cast(currentServerValue);
      Handle<Value> serverUrlValue = currentServerObject->Get(String::New("url"));
      if(!serverUrlValue->IsString()) throw i;
      String::AsciiValue serverUrlAsciiValue(serverUrlValue->ToString());
      webrtc::PeerConnectionInterface::IceServer iceServer;
      iceServer.uri = *serverUrlAsciiValue;
      iceServers.push_back(iceServer);
    }
    puts("Ice servers parsed successful");
  }
  catch(int element) {
    if(element > 0)
      puts("Fail parsing some ice configurations");
    else {
      puts("No valid ice server provided. Using default one!");
      webrtc::PeerConnectionInterface::IceServer iceServer;
      iceServer.uri = "stun:stun.l.google.com:19302";
      iceServers.push_back(iceServer);
    }
  }

  return scope.Close(args.This());
}
