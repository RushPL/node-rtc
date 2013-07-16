{
  "targets": [
    {
      "target_name": "rtc",
      "link_settings": {
        "libraries": [
          "../3d_party/libjingle/trunk/out/Debug/libjingle_peerconnection.a",
          "../3d_party/libjingle/trunk/out/Debug/libjingle_media.a",
          "../3d_party/libjingle/trunk/out/Debug/libyuv.a",
          "../3d_party/libjingle/trunk/out/Debug/libvideo_engine_core.a",
          "../3d_party/libjingle/trunk/out/Debug/libwebrtc_utility.a",
          "../3d_party/libjingle/trunk/out/Debug/libvoice_engine.a",
          "../3d_party/libjingle/trunk/out/Debug/libcommon_audio.a",
          "../3d_party/libjingle/trunk/out/Debug/libsystem_wrappers.a",
          "../3d_party/libjingle/trunk/out/Debug/libpaced_sender.a",
          "../3d_party/libjingle/trunk/out/Debug/libvideo_render_module.a",
          "../3d_party/libjingle/trunk/out/Debug/libvideo_capture_module.a",
          "../3d_party/libjingle/trunk/out/Debug/libcommon_video.a",
          "../3d_party/libjingle/trunk/out/Debug/libcommon_audio_sse2.a",
          "../3d_party/libjingle/trunk/out/Debug/libaudio_processing.a",
          "../3d_party/libjingle/trunk/out/Debug/libaudio_processing_sse2.a",
          "../3d_party/libjingle/trunk/out/Debug/libprotobuf_lite.a",
          "../3d_party/libjingle/trunk/out/Debug/libremote_bitrate_estimator.a",
          "../3d_party/libjingle/trunk/out/Debug/libaudio_conference_mixer.a",
          "../3d_party/libjingle/trunk/out/Debug/libaudio_coding_module.a",
          "../3d_party/libjingle/trunk/out/Debug/libCNG.a",
          "../3d_party/libjingle/trunk/out/Debug/libG711.a",
          "../3d_party/libjingle/trunk/out/Debug/libiSAC.a",
          "../3d_party/libjingle/trunk/out/Debug/libNetEq.a",
          "../3d_party/libjingle/trunk/out/Debug/libwebrtc_opus.a",
          "../3d_party/libjingle/trunk/out/Debug/libbitrate_controller.a",
          "../3d_party/libjingle/trunk/out/Debug/libwebrtc_video_coding.a",
          "../3d_party/libjingle/trunk/out/Debug/libwebrtc_vp8.a",
          "../3d_party/libjingle/trunk/out/Debug/libwebrtc_i420.a",
          "../3d_party/libjingle/trunk/out/Debug/libvideo_coding_utility.a",
          "../3d_party/libjingle/trunk/out/Debug/libaudio_device.a",
          "../3d_party/libjingle/trunk/out/Debug/libvideo_processing.a",
          "../3d_party/libjingle/trunk/out/Debug/libvideo_processing_sse2.a",
          "../3d_party/libjingle/trunk/out/Debug/librtp_rtcp.a",
          "../3d_party/libjingle/trunk/out/Debug/libmedia_file.a",
          "../3d_party/libjingle/trunk/out/Debug/libaudioproc_debug_proto.a",
          "../3d_party/libjingle/trunk/out/Debug/libjingle.a",
          "../3d_party/openssl/libssl.a",
          "../3d_party/openssl/libcrypto.a",
          "../3d_party/libjingle/trunk/out/Debug/libjingle_p2p.a",
          "../3d_party/libjingle/trunk/out/Debug/libjpeg_turbo.a",
          "../3d_party/libjingle/trunk/out/Debug/libsrtp.a",
          "../3d_party/libjingle/trunk/out/Debug/libopus.a",
          "../3d_party/libjingle/trunk/out/Debug/libvpx.a",
          "../3d_party/libjingle/trunk/out/Debug/libvpx_intrinsics_sse2.a",
          "../3d_party/libjingle/trunk/out/Debug/libvpx_intrinsics_mmx.a",
          "../3d_party/libjingle/trunk/out/Debug/libvpx_intrinsics_ssse3.a"
        ]
      },
      "sources": [
        "src/peerconnection.cc",
        "src/rtc.cc"
      ],
      "include_dirs": [ 
        "3d_party/libjingle/trunk/",
        "3d_party/jsoncpp/trunk/jsoncpp/include"
      ],
      "defines": [
        "POSIX"
      ],
      "conditions": [
        [ "OS == 'mac'", {
            "libraries": [
              "../3d_party/libjingle/trunk/out/Debug/libexpat.a",
              "$(SDKROOT)/System/Library/Frameworks/Cocoa.framework",
              "$(SDKROOT)/System/Library/Frameworks/QTKit.framework",
              "$(SDKROOT)/System/Library/Frameworks/QuartzCore.framework",
              "$(SDKROOT)/System/Library/Frameworks/CoreAudio.framework",
              "$(SDKROOT)/System/Library/Frameworks/AudioToolbox.framework",
              "$(SDKROOT)/System/Library/Frameworks/IOKit.framework",
              "$(SDKROOT)/System/Library/Frameworks/Carbon.framework",
              "$(SDKROOT)/System/Library/Frameworks/OpenGL.framework"
            ]
          }
        ]
      ]
    }
  ]
}
