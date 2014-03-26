#include <node.h>
#include <v8.h>
#include <uv.h>

using namespace v8;

void Run(const FunctionCallbackInfo<Value>& args) {
	HandleScope scope(Isolate::GetCurrent());
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}

void RunOnce(const FunctionCallbackInfo<Value>& args) {
	HandleScope scope(Isolate::GetCurrent());
	int r = uv_run(uv_default_loop(), UV_RUN_ONCE);
	args.GetReturnValue().Set(Number::New(Isolate::GetCurrent(), r));
}

void RunNoWait(const FunctionCallbackInfo<Value>& args) {
	HandleScope scope(Isolate::GetCurrent());
	int r = uv_run(uv_default_loop(), UV_RUN_NOWAIT);
	args.GetReturnValue().Set(Number::New(Isolate::GetCurrent(), r));
}

void init(Handle<Object> target) {
	NODE_SET_METHOD(target, "run", Run);
	NODE_SET_METHOD(target, "runOnce", RunOnce);
	NODE_SET_METHOD(target, "runNoWait", RunNoWait);
}

NODE_MODULE(uvrun, init);
