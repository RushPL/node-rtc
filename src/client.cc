#define BUILDING_NODE_EXTENSION

#include "client.h"

using namespace v8;

Client::Client() {}
Client::~Client() {}

void Client::Init(Handle<Object> exports) {
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Client"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("Client"), constructor);
}

Handle<Value> Client::New(const Arguments& args) {
  HandleScope scope;

  talk_base::scoped_refptr<Client> client = new talk_base::RefCountedObject<Client>();
  client->AddRef();
  client->Wrap(args.This());

  return args.This();
}

/*
 *  Implements PeerConnectionObserver virtual class
 */
void Client::OnError() {}

void Client::OnAddStream(webrtc::MediaStreamInterface* stream) {}

void Client::OnRemoveStream(webrtc::MediaStreamInterface* stream) {}

void Client::OnIceCandidate(const webrtc::IceCandidateInterface* candidate) {}

/*
 *  Implements CreateSessionDescriptionObserver virtual class
 */
void Client::OnSuccess(webrtc::SessionDescriptionInterface* desc) {}

void Client::OnFailure(const std::string& error) {}
