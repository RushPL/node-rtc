#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "Client.h"

using namespace v8;

Client::Client() {};
Client::~Client() {};

void Client::Init(Handle<Object> exports) {
  Local<FunctionTemplate> newFunctionTemplate = FunctionTemplate::New(New);
  
  newFunctionTemplate->SetClassName(String::NewSymbol("Client"));
  newFunctionTemplate->InstanceTemplate()->SetInternalFieldCount(1);

  // adding the fake method to prototype
  //newFunctionTemplate->PrototypeTemplate()->Set(String::NewSymbol("plusOne"), FunctionTemplate::New(PlusOne)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(newFunctionTemplate->GetFunction());
  exports->Set(String::NewSymbol("Client"), constructor);
}

Handle<Value> Client::New(const Arguments& args) {
  HandleScope scope;

  Client* pc = new Client();

  pc->Wrap(args.This());

  return args.This();
}

//Handle<Value> Client::PlusOne(const Arguments& args) {
  //HandleScope scope;

  //Client* pc = ObjectWrap::Unwrap<Client>(args.This());
  
  //return scope.Close(Number::New(42));
//}
