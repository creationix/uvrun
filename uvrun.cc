#include <node.h>
#include <v8.h>
#include <uv.h>

using namespace v8;

void Run(const FunctionCallbackInfo<Value>& args) {
  HandleScope scope(Isolate::GetCurrent());
#ifdef OLD_UV_RUN_SIGNATURE
  uv_run(uv_default_loop());
#else
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
#endif
}

void RunOnce(const FunctionCallbackInfo<Value>& args) {
  HandleScope scope(Isolate::GetCurrent());
#ifdef OLD_UV_RUN_SIGNATURE
  int r = uv_run_once(uv_default_loop());
#else
  int r = uv_run(uv_default_loop(), UV_RUN_ONCE);
#endif
  args.GetReturnValue().Set(Number::New(Isolate::GetCurrent(), r));
}

void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "run", Run);
  NODE_SET_METHOD(target, "runOnce", RunOnce);
}

NODE_MODULE(uvrun, init);
