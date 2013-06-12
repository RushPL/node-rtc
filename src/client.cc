#define BUILDING_NODE_EXTENSION

#include "client.h"
#include <stdio.h>
#include <talk/base/thread.h>

Client::Client() {
  talk_base::scoped_refptr<webrtc::PeerConnectionFactoryInterface> peerConnectionFactory = webrtc::CreatePeerConnectionFactory();
  puts("Say hello to my new sparkling PeerConnectionFactory");

  webrtc::PeerConnectionInterface::IceServers servers;
  webrtc::PeerConnectionInterface::IceServer server;
  server.uri = "stun:stun.l.google.com:19302";
  servers.push_back(server);
  this->peerConnection = peerConnectionFactory->CreatePeerConnection(servers, NULL, this);
  puts("And here we have PeerConnection!");
  
}

void Client::beInitiator() {
  //this->peerConnection->CreateOffer(this, NULL);

}

void Client::onRemoteDescription(const std::string type, const std::string sdp) {
  webrtc::SessionDescriptionInterface* desc(webrtc::CreateSessionDescription(type, sdp));
  this->peerConnection->SetRemoteDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);

  //if(type == webrtc::SessionDescriptionInterface::kOffer)
  //  this->peerConnection->CreateAnswer(new talk_base::RefCountedObject<onSessionDescriptionCreated>(), NULL);
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
//void Client::OnSuccess(webrtc::SessionDescriptionInterface* desc) {
  //puts("called CreateSessionDescriptionObserver::OnSuccess");
//}

//void Client::OnFailure(const std::string& error) {
  //puts("called CreateSessionDescriptionObserver::OnFailure");
//}
