#include "utils.h"

#include <string>

#include "napi.h"
#include "simdjson.h"

namespace Dijkstra {

void test(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::String jsString;

  // Retrive the key from 1st parameter
  std::string key = info[0].As<Napi::String>().ToString();

  try {
    // Should reuse parser
    simdjson::dom::parser parser;

    // load and parse a file
    simdjson::dom::element json = parser.load("file.txt");

    // Casting JSON element to string
    std::string value = std::string(json[key]);
    // Creating JS String out of std string
    jsString = Napi::String::New(env, value);

  } catch (const std::exception& e) {
    Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
  }

  // Retrive the callback function from 2nd parameter
  Napi::Function cb = info[1].As<Napi::Function>();
  // Call the callback and pass jsString as parameter
  cb.Call(env.Global(), {jsString});
}

}  // namespace Dijkstra