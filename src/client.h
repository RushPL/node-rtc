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
  public node::ObjectWrap,
  public webrtc::PeerConnectionObserver,
  public webrtc::CreateSessionDescriptionObserver {

  public:
    Client();
    ~Client();

    static void Init(v8::Handle<v8::Object> exports);

  private:
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> BeInitiator(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetRemoteIceCandidate(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetRemoteDescription(const v8::Arguments& args);

    static void fireCallbacks(uv_async_t *handle, int status);

    // Implements PeerConnectionObserver virtual class
    virtual void OnError();
    virtual void OnAddStream(webrtc::MediaStreamInterface* stream);
    virtual void OnRemoveStream(webrtc::MediaStreamInterface* stream);
    virtual void OnIceCandidate(const webrtc::IceCandidateInterface* candidate);

    // Implements CreateSessionDescriptionObserver virtual class
    virtual void OnSuccess(webrtc::SessionDescriptionInterface* desc);
    virtual void OnFailure(const std::string& error);

    talk_base::scoped_refptr<webrtc::PeerConnectionInterface> peerConnection;

    uv_loop_t* loop;
    uv_async_t async;

};



#endif
