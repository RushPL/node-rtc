#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "PeerConnection.h"

using namespace v8;

PeerConnection::PeerConnection() {};
PeerConnection::~PeerConnection() {};

void PeerConnection::Init(Handle<Object> exports) {
  Local<FunctionTemplate> newFunctionTemplate = FunctionTemplate::New(New);
  
  newFunctionTemplate->SetClassName(String::NewSymbol("PeerConnection"));
  newFunctionTemplate->InstanceTemplate()->SetInternalFieldCount(1);

  // adding the fake method to prototype
  newFunctionTemplate->PrototypeTemplate()->Set(String::NewSymbol("plusOne"), FunctionTemplate::New(PlusOne)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(newFunctionTemplate->GetFunction());
  exports->Set(String::NewSymbol("PeerConnection"), constructor);
}

Handle<Value> PeerConnection::New(const Arguments& args) {
  HandleScope scope;

  PeerConnection* pc = new PeerConnection();

  pc->Wrap(args.This());

  return args.This();
}

Handle<Value> PeerConnection::PlusOne(const Arguments& args) {
  HandleScope scope;

  PeerConnection* pc = ObjectWrap::Unwrap<PeerConnection>(args.This());
  
  return scope.Close(Number::New(42));
}
