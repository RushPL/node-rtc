#define BUILDING_NODE_EXTENSION

#include "client.h"

using namespace v8;

struct Container {
  Client* client;
  Persistent<Function> onOfferReadyCallback;
  Persistent<Function> onIceCandidateCallback;
  std::string sdpString;
  std::string iceCandidate;
};

Client::Client() {}
Client::~Client() {}

void Client::Init(Handle<Object> exports) {
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Client"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  tpl->PrototypeTemplate()->Set(String::NewSymbol("beInitiator"), FunctionTemplate::New(BeInitiator)->GetFunction());

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

  client->loop = uv_default_loop();
  uv_async_init(client->loop, &client->async, Client::fireCallbacks);

  return args.This();
}

Handle<Value> Client::BeInitiator(const Arguments& args) {
  HandleScope scope;

  talk_base::scoped_refptr<Client> client = ObjectWrap::Unwrap<Client>(args.This());

  if(args.Length() != 2 || !args[0]->IsFunction() || !args[1]->IsFunction())
    return ThrowException(Exception::Error(String::New("Please set onOfferReadyCallback and onIceCandidateCallback")));

  Local<Function> onOfferReadyCallback = Local<Function>::Cast(args[0]);
  Local<Function> onIceCandidateCallback = Local<Function>::Cast(args[1]);

  Container* c = new Container();
  c->client = client;
  c->onOfferReadyCallback = Persistent<Function>::New(onOfferReadyCallback);
  c->onIceCandidateCallback = Persistent<Function>::New(onIceCandidateCallback);
  c->sdpString = "";
  c->iceCandidate = "";

  client->async.data = (void*) c;

  client->peerConnection->CreateOffer(client, NULL);

  return scope.Close(Boolean::New(true));
}

void Client::fireCallbacks(uv_async_t *handle, int status) {
  Container* c = (Container*) handle->data;

  if(c->sdpString != "") {
    Local<Value> argv[1] = { String::New(c->sdpString.c_str()) };
    c->onOfferReadyCallback->Call(Context::GetCurrent()->Global(), 1, argv);
    c->sdpString = "";
  }
  if(c->iceCandidate != "") {
    Local<Value> argv[1] = { String::New(c->iceCandidate.c_str()) };
    c->onIceCandidateCallback->Call(Context::GetCurrent()->Global(), 1, argv);
    c->iceCandidate = "";
  }

}

Handle<Value> Client::SetRemoteIceCandidate(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Undefined());
}

Handle<Value> Client::SetRemoteDescription(const Arguments& args) {
  HandleScope scope;

   //webrtc::SessionDescriptionInterface* desc(webrtc::CreateSessionDescription(type, sdp));
  //this->peerConnection->SetRemoteDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);

  //if(type == webrtc::SessionDescriptionInterface::kOffer)
    //this->peerConnection->CreateAnswer(this, NULL);

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
  std::string* candAsString = new std::string();
  candidate->ToString(candAsString);

  Container* c = (Container*) this->async.data;
  c->iceCandidate = *candAsString;

  uv_async_send(&this->async);
}

/*
 *  Implements CreateSessionDescriptionObserver virtual class
 */
void Client::OnSuccess(webrtc::SessionDescriptionInterface* desc) {
  std::string* descAsString = new std::string();
  desc->ToString(descAsString);

  Container* c = (Container*) this->async.data;
  c->sdpString = *descAsString;

  uv_async_send(&this->async);

  this->peerConnection->SetLocalDescription(new talk_base::RefCountedObject<onSessionDescriptionSet>(), desc);

}

void Client::OnFailure(const std::string& error) {
  puts("called CreateSessionDescriptionObserver::OnFailure");
}
