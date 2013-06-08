{
  "targets": [
    {
      "target_name": "rtc",
      "sources": [ "src/Client.cpp" , "src/rtc.cpp" ],
      "include_dirs": [ "3d_party/libjingle/trunk/" ],
      "cflags_cc": [ "-std=gnu++11" ],
      "defines": [ "POSIX" ]
    },
    {
      "target_name": "client.test.run",
      "type": "executable",
      "sources": [ "test/Client.test.cpp", "src/Client.cpp" ],
      "include_dirs": [ "3d_party/libjingle/trunk/", "3d_party/igloo" ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "cflags_cc": [ "-std=gnu++11" ],
      "conditions": [
        [ "OS == 'mac'", {
          "xcode_settings": {
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
          }
        }]
      ],
      "defines": [ "POSIX" ]
    }
  ]
}
