{
  "targets": [
    {
      "target_name": "rtc",
      "sources": [ "src/Client.cpp" , "src/rtc.cpp" ],
      "include_dirs": [ "3d_party/libjingle/trunk/" ],
      "defines": [ "POSIX" ]
    }
  ]
}
