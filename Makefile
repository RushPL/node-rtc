all: prepare deps build test

prepare:
	git submodule update --init
	mkdir -p ./3d_party/libjingle; cd ./3d_party/libjingle; ../depot_tools/gclient config http://libjingle.googlecode.com/svn/trunk; GYP_GENERATORS=make ../depot_tools/gclient sync --force;
	#mkdir -p ./3d_party/googletest; cd ./3d_party/googletest; ../depot_tools/gclient config http://googletest.googlecode.com/svn/trunk/; GYP_GENERATORS=make ../depot_tools/gclient sync --force;
	#mkdir -p ./3d_party/googlemock; cd ./3d_party/googlemock; ../depot_tools/gclient config http://googlemock.googlecode.com/svn/trunk/; GYP_GENERATORS=make ../depot_tools/gclient sync --force;

deps:
	cd 3d_party/openssl; ./config; make;
	#cd 3d_party/googletest/trunk/make; make;
	#cd 3d_party/googlemock/trunk/; ln -s ../../googletest/trunk/ gtest; cd make; make
	cd 3d_party/libjingle/trunk; make libjingle_peerconnection libjingle_media libyuv video_engine_core webrtc_utility voice_engine common_audio system_wrappers paced_sender video_render_module video_capture_module common_video common_audio_sse2 audio_processing audio_processing_sse2 protobuf_lite remote_bitrate_estimator audio_conference_mixer audio_coding_module CNG G711 iSAC NetEq webrtc_opus bitrate_controller webrtc_video_coding webrtc_vp8 webrtc_i420 video_coding_utility audio_device video_processing video_processing_sse2 rtp_rtcp media_file audioproc_debug_proto libjingle libjingle_p2p expat libjpeg libsrtp opus libvpx libvpx_intrinsics_sse2 libvpx_intrinsics_mmx libvpx_intrinsics_ssse3
ifeq ($(shell uname -s),Linux)
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/talk/libjingle_peerconnection.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/talk/libjingle_media.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/video_engine/libvideo_engine_core.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libwebrtc_utility.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/voice_engine/libvoice_engine.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/common_audio/libcommon_audio.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/system_wrappers/source/libsystem_wrappers.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libpaced_sender.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libvideo_render_module.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libvideo_capture_module.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/common_video/libcommon_video.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/common_audio/libcommon_audio_sse2.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libaudio_processing.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libaudio_processing_sse2.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/protobuf/libprotobuf_lite.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libremote_bitrate_estimator.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libaudio_conference_mixer.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libaudio_coding_module.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libCNG.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libG711.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libiSAC.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libNetEq.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libwebrtc_opus.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libbitrate_controller.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libwebrtc_video_coding.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/video_coding/codecs/vp8/libwebrtc_vp8.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libwebrtc_i420.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/video_coding/utility/libvideo_coding_utility.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libaudio_device.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libvideo_processing.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libvideo_processing_sse2.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/librtp_rtcp.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libmedia_file.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/webrtc/modules/libaudioproc_debug_proto.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/talk/libjingle.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/talk/libjingle_p2p.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/libjpeg_turbo/libjpeg_turbo.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/libsrtp/libsrtp.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/opus/libopus.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/libvpx/libvpx.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/libvpx/libvpx_intrinsics_sse2.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/libvpx/libvpx_intrinsics_mmx.a ./3d_party/libjingle/trunk/out/Debug/
	cp ./3d_party/libjingle/trunk/out/Debug/obj.target/third_party/libvpx/libvpx_intrinsics_ssse3.a ./3d_party/libjingle/trunk/out/Debug/
endif
	npm install node-gyp

build:
	./node_modules/.bin/node-gyp --arch=i386 configure
	./node_modules/.bin/node-gyp build

test: build
ifeq ($(shell uname -s),Darwin)
	arch --i386 node ./node_modules/mocha/bin/_mocha
else
	./node_modules/.bin/mocha
endif
	#cd build; export NODE_HEADERS="`make -pn  | grep 'INCS_Release' | sed 's/INCS_Release :=//'`"; cd ../test; g++ $$NODE_HEADERS -I ../3d_party/googlemock/trunk/include/ -I ../3d_party/googletest/trunk/include/ main.unittest.cc  ../3d_party/googletest/trunk/make/gtest-all.o ../src/peerconnection.cc -o testall && ./testall

clean:
	rm -rf ./3d_party/libjingle/trunk/out/
	#cd 3d_party/googletest/trunk/make; make clean;
	#cd 3d_party/googlemock/trunk/make; make clean; rm -f ../gtest
	rm -rf ./test/testall
	cd ./3d_party/openssl; make clean
	./node_modules/.bin/node-gyp clean

.PHONY: build clean prepare deps test
