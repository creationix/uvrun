#include <nan.h>
#include <uv.h>

using namespace v8;

NAN_METHOD(Run) {
#ifdef OLD_UV_RUN_SIGNATURE
  int r = uv_run(uv_default_loop());
#else
  int r = uv_run(uv_default_loop(), UV_RUN_DEFAULT);
#endif
  info.GetReturnValue().Set(r);
}

NAN_METHOD(RunOnce) {
#ifdef OLD_UV_RUN_SIGNATURE
  int r = uv_run_once(uv_default_loop());
#else
  int r = uv_run(uv_default_loop(), UV_RUN_ONCE);
#endif
  info.GetReturnValue().Set(r);
}

NAN_METHOD(RunNoWait) {
#ifdef OLD_UV_RUN_SIGNATURE
  int r = uv_run_nowait(uv_default_loop());
#else
  int r = uv_run(uv_default_loop(), UV_RUN_NOWAIT);
#endif
  info.GetReturnValue().Set(r);
}

NAN_MODULE_INIT(init) {
    using Nan::New;
    Nan::Set(target, New<String>("run").ToLocalChecked(),
        Nan::GetFunction(New<FunctionTemplate>(Run)).ToLocalChecked());
    Nan::Set(target, New<String>("runOnce").ToLocalChecked(),
        Nan::GetFunction(New<FunctionTemplate>(RunOnce)).ToLocalChecked());
    Nan::Set(target, New<String>("runNoWait").ToLocalChecked(),
        Nan::GetFunction(New<FunctionTemplate>(RunNoWait)).ToLocalChecked());
}

NODE_MODULE(uvrun, init);
