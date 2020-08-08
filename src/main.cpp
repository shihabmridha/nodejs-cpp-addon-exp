#include "napi.h"
#include "utils.h"

using Dijkstra::test;
using Napi::CallbackInfo;
using Napi::Env;
using Napi::Function;
using Napi::Number;
using Napi::Object;
using Napi::String;

Object Init(Env env, Object exports) {
  // Exporting function to JS land.
  exports.Set("test", Function::New(env, test));

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)