{
  "targets": [
    {
      "target_name": "app",
      "cflags": ["-Wall", "-std=c++11"],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "src/main.cpp",
        "src/utils.cpp",
        "src/simdjson.cpp",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'conditions': [
        ['OS=="mac"', {
          'cflags+': ['-fvisibility=hidden'],
          'xcode_settings': {
            'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES',
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
          }
        }]
      ]
    }
  ]
}