#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "client.h"

using namespace v8;

class Wrapper : public Client, public node::ObjectWrap {

  public:
    static void Init(Handle<Object> exports) {
      Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
      tpl->SetClassName(String::NewSymbol("Client"));
      tpl->InstanceTemplate()->SetInternalFieldCount(1);
 
      //tpl->PrototypeTemplate()->Set(String::NewSymbol("beInitiator"), FunctionTemplate::New(beInitiator)->GetFunction());
    
      Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
     exports->Set(String::NewSymbol("Client"), constructor);
    }

  private:
    static Handle<Value> New(const Arguments& args) {
    
      v8::HandleScope scope;
    
      //talk_base::scoped_refptr<Client> client(new talk_base::RefCountedObject<Client>());
      Wrapper* client = new Wrapper();
      client->Wrap(args.This());
  
      return args.This();
    }

};

void InitAll(Handle<Object> exports) {
  Wrapper::Init(exports);
}

NODE_MODULE(rtc, InitAll)
