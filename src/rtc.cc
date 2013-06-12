#define BUILDING_NODE_EXTENSION
#include <node.h>
//#include <talk/base/thread.h>
#include "client.h"

using namespace v8;

//class Wrapper : public Client, public node::ObjectWrap {

  //public:
    //static void Init(Handle<Object> exports) {
      //Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
      //tpl->SetClassName(String::NewSymbol("Client"));
      //tpl->InstanceTemplate()->SetInternalFieldCount(1);
 
      //tpl->PrototypeTemplate()->Set(String::NewSymbol("beInitiator"), FunctionTemplate::New(beInitiatorCaller)->GetFunction());
    
      //Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
      //exports->Set(String::NewSymbol("Client"), constructor);
    //}
    

  //private:
    //static Handle<Value> New(const Arguments& args) {
    
      //HandleScope scope;
    
      //talk_base::scoped_refptr<Wrapper> client = new talk_base::RefCountedObject<Wrapper>();
      //client->AddRef();
      //client->Wrap(args.This());
  
      //return args.This();
    //}

    //static Handle<Value> beInitiatorCaller(const Arguments& args) {
      //HandleScope scope;

      //Wrapper* client = ObjectWrap::Unwrap<Wrapper>(args.This());
      ////client->beInitiator();
      //printf("%d", client->a);

      //return scope.Close(Boolean::New(true));
    //}

//};

void InitAll(Handle<Object> exports) {
  //Wrapper::Init(exports);
  Client::Init(exports);
}

NODE_MODULE(rtc, InitAll)
