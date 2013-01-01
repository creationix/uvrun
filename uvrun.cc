#include <node.h>
#include <v8.h>
#include <uv.h>

using namespace v8;

Handle<Value> Run(const Arguments& args) {
  HandleScope scope;
  uv_run(uv_default_loop());
  return scope.Close(Null());
}

Handle<Value> RunOnce(const Arguments& args) {
  HandleScope scope;
  int r = uv_run_once(uv_default_loop());
  return scope.Close(Number::New(r));
}

void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "run", Run);
  NODE_SET_METHOD(target, "runOnce", RunOnce);
}

NODE_MODULE(uvrun, init);