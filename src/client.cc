#define BUILDING_NODE_EXTENSION

#include "client.h"
//#include <talk/base/thread.h>

using namespace v8;

Client::Client() {}
Client::~Client() {}

void Client::Init(Handle<Object> exports) {
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Client"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  tpl->PrototypeTemplate()->Set(String::NewSymbol("beInitiator"), FunctionTemplate::New(BeInitiator)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setOnIceCandidateCallback"), FunctionTemplate::New(SetOnIceCandidateCallback)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setOnDescriptionReadyCallback"), FunctionTemplate::New(SetOnDescriptionReadyCallback)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("Client"), constructor);
}

Handle<Value> Client::New(const Arguments& args) {
  HandleScope scope;

  talk_base::scoped_refptr<Client> client = new talk_base::RefCountedObject<Client>();
  client->AddRef();
  client->Wrap(args.This());

  talk_base::scoped_refptr<webrtc::PeerConnectionFactoryInterface> peerConnectionFactory = webrtc::CreatePeerConnectionFactory();
  puts("Say hello to my new sparkling PeerConnectionFactory");

  webrtc::PeerConnectionInterface::IceServers servers;
  webrtc::PeerConnectionInterface::IceServer server;
  server.uri = "stun:stun.l.google.com:19302";
  servers.push_back(server);
  client->peerConnection = peerConnectionFactory->CreatePeerConnection(servers, NULL, client);
  puts("And here we have PeerConnection!");

  return args.This();
}

Handle<Value> Client::BeInitiator(const Arguments& args) {
  HandleScope scope;

  talk_base::scoped_refptr<Client> client = ObjectWrap::Unwrap<Client>(args.This());

  client->peerConnection->CreateOffer(client, NULL);

  return scope.Close(Boolean::New(true));
}

Handle<Value> Client::SetOnIceCandidateCallback(const Arguments& args) {
  HandleScope scope;

  talk_base::scoped_refptr<Client> client = ObjectWrap::Unwrap<Client>(args.This());
  client->onIceCandidateCallback = Persistent<Function>::New(Handle<Function>::Cast(args[0]));

  return scope.Close(Boolean::New(true));

}

void Client::runCallback(v8::Persistent<v8::Function> callback) {
  Handle<Value> argv[] = { Local<Value>::New(String::New("cacca")) };
  //talk_base::scoped_refptr<Client> client = static_cast<Client>(client);

  callback->Call(Context::GetCurrent()->Global(), 1, argv);

}

Handle<Value> Client::SetOnDescriptionReadyCallback(const Arguments& args) {
  HandleScope scope;

  talk_base::scoped_refptr<Client> client = ObjectWrap::Unwrap<Client>(args.This());
  client->onDescriptionReadyCallback = Persistent<Function>::New(Local<Function>::Cast(args[0]));

  return scope.Close(Boolean::New(true));
}

Handle<Value> Client::SetRemoteIceCandidate(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Undefined());
}

Handle<Value> Client::SetRemoteDescription(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Undefined());
}

/*
 *  Implements PeerConnectionObserver virtual class
 */
void Client::OnError() {
  puts("called PeerConnectionObserver::OnError");
}

void Client::OnAddStream(webrtc::MediaStreamInterface* stream) {
  puts("called PeerConnectionObserver::OnAddStream");
}

void Client::OnRemoveStream(webrtc::MediaStreamInterface* stream) {
  puts("called PeerConnectionObserver::OnRemoveStream");
}

void Client::OnIceCandidate(const webrtc::IceCandidateInterface* candidate) {
  puts("called PeerConnectionObserver::OnIceCandidate");

  std::string* candAsString = new std::string();
  candidate->ToString(candAsString);

  puts(candAsString->c_str());
}

/*
 *  Implements CreateSessionDescriptionObserver virtual class
 */
void Client::OnSuccess(webrtc::SessionDescriptionInterface* desc) {
  puts("called CreateSessionDescriptionObserver::OnSuccess");

  this->peerConnection->SetLocalDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);

  puts("Calling onDescriptionReadyCallback");

  std::string* descAsString = new std::string();
  desc->ToString(descAsString);

  puts(descAsString->c_str());

}

void Client::OnFailure(const std::string& error) {
  puts("called CreateSessionDescriptionObserver::OnFailure");
}





//void Client::onRemoteDescription(const std::string type, const std::string sdp) {
  //webrtc::SessionDescriptionInterface* desc(webrtc::CreateSessionDescription(type, sdp));
  //this->peerConnection->SetRemoteDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);

  //if(type == webrtc::SessionDescriptionInterface::kOffer)
    //this->peerConnection->CreateAnswer(this, NULL);
//}

//void Client::onLocalDescription(const std::string type, const std::string sdp) {
  //webrtc::SessionDescriptionInterface* desc(webrtc::CreateSessionDescription(type, sdp));
  //this->peerConnection->SetLocalDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);
//}


