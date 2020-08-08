## NodeJS C++ Addon with N-API (Experiment)
### Target: 
- Parse a JSON file using [simdjson](https://github.com/simdjson/simdjson/).
- Pass key of JSON field to retrive the value and a callback.
- Pass the retrived value from C++ to JavaScript as an argument of given callback.

### Test:
```
addon.test('key', (value) => {
  console.log(value); // should print the value retrived from json file
});
```