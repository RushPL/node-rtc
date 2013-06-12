#ifndef NODE_RTC_CLIENT_H
#define NODE_RTC_CLIENT_H

#include <talk/app/webrtc/peerconnectioninterface.h>
#include <node.h>

class onSessionDescriptionSet : public webrtc::SetSessionDescriptionObserver {
  virtual void OnSuccess() {
    puts("Description setted");
  }

  virtual void OnFailure(const std::string& error) {
    puts("Error setting description");
  }
};

class Client : 
  public webrtc::PeerConnectionObserver {
  //public webrtc::CreateSessionDescriptionObserver {
  
  public:
    Client();
    void beInitiator();
    void onLocalDescription(const std::string type, const std::string sdp);
    void onRemoteDescription(const std::string type, const std::string sdp);

    // Implements PeerConnectionObserver virtual class
    virtual void OnError();
    virtual void OnAddStream(webrtc::MediaStreamInterface* stream);
    virtual void OnRemoveStream(webrtc::MediaStreamInterface* stream);
    virtual void OnIceCandidate(const webrtc::IceCandidateInterface* candidate);

    // Implements CreateSessionDescriptionObserver virtual class
    //virtual void OnSuccess(webrtc::SessionDescriptionInterface* desc);
    //virtual void OnFailure(const std::string& error);

  private:
    talk_base::scoped_refptr<webrtc::PeerConnectionInterface> peerConnection;
    
};

#endif
