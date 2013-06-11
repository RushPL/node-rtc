#include "client.h"
#include <stdio.h>
#include <talk/base/thread.h>

void Client::Init(v8::Handle<v8::Object> exports) {
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
  tpl->SetClassName(v8::String::NewSymbol("Client"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  v8::Persistent<v8::Function> constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
  exports->Set(v8::String::NewSymbol("Client"), constructor);
}

v8::Handle<v8::Value> Client::New(const v8::Arguments& args) {
  v8::HandleScope scope;

  talk_base::scoped_refptr<Client> client(new talk_base::RefCountedObject<Client>(args));
  
  return args.This();
}


class onSessionDescriptionSet : public webrtc::SetSessionDescriptionObserver {
  virtual void OnSuccess() {
    puts("Description setted");
  }

  virtual void OnFailure(const std::string& error) {
    puts("Error setting description");
    puts(error.c_str());
  }
};

Client::Client(const v8::Arguments& args) {
  this->Wrap(args.This());

  //talk_base::scoped_refptr<webrtc::PeerConnectionFactoryInterface> peerConnectionFactory = webrtc::CreatePeerConnectionFactory();
  puts("Say hello to my new sparkling PeerConnectionFactory");

  webrtc::PeerConnectionInterface::IceServers servers;
  webrtc::PeerConnectionInterface::IceServer server;
  server.uri = "stun:stun.l.google.com:19302";
  servers.push_back(server);
  //this->peerConnection = peerConnectionFactory->CreatePeerConnection(servers, NULL, this);
  
}

void Client::beInitiator() {
  this->peerConnection->CreateOffer(this, NULL);
}

void Client::onRemoteDescription(const std::string type, const std::string sdp) {
  webrtc::SessionDescriptionInterface* desc(webrtc::CreateSessionDescription(type, sdp));
  this->peerConnection->SetRemoteDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);

  if(type == webrtc::SessionDescriptionInterface::kOffer)
    this->peerConnection->CreateAnswer(this, NULL);
}

void Client::onLocalDescription(const std::string type, const std::string sdp) {
  webrtc::SessionDescriptionInterface* desc(webrtc::CreateSessionDescription(type, sdp));
  this->peerConnection->SetLocalDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);
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
}

/*
 *  Implements CreateSessionDescriptionObserver virtual class
 */
void Client::OnSuccess(webrtc::SessionDescriptionInterface* desc) {
  puts("called CreateSessionDescriptionObserver::OnSuccess");
}

void Client::OnFailure(const std::string& error) {
  puts("called CreateSessionDescriptionObserver::OnFailure");
}
