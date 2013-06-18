all: prepare deps build

prepare:
	git submodule update --init
	mkdir -p ./3d_party/libjingle; cd ./3d_party/libjingle; ../depot_tools/gclient config http://libjingle.googlecode.com/svn/trunk; GYP_GENERATORS=make ../depot_tools/gclient sync --force;
	mkdir -p ./3d_party/googletest; cd ./3d_party/googletest; ../depot_tools/gclient config http://googletest.googlecode.com/svn/trunk/; GYP_GENERATORS=make ../depot_tools/gclient sync --force;
	mkdir -p ./3d_party/googlemock; cd ./3d_party/googlemock; ../depot_tools/gclient config http://googlemock.googlecode.com/svn/trunk/; GYP_GENERATORS=make ../depot_tools/gclient sync --force;

deps:
	cd 3d_party/openssl; ./config; make;
	cd 3d_party/libjingle/trunk; make libjingle_peerconnection libjingle_media libyuv video_engine_core webrtc_utility voice_engine common_audio system_wrappers paced_sender video_render_module video_capture_module common_video common_audio_sse2 audio_processing audio_processing_sse2 protobuf_lite remote_bitrate_estimator audio_conference_mixer audio_coding_module CNG G711 iSAC NetEq webrtc_opus bitrate_controller webrtc_video_coding webrtc_vp8 webrtc_i420 video_coding_utility audio_device video_processing video_processing_sse2 rtp_rtcp media_file audioproc_debug_proto libjingle libjingle_p2p expat libjpeg libsrtp opus libvpx libvpx_intrinsics_sse2 libvpx_intrinsics_mmx libvpx_intrinsics_ssse3
	npm install node-gyp

build:
	./node_modules/.bin/node-gyp --arch=i386 configure
	./node_modules/.bin/node-gyp build

clean:
	rm -rf ./3d_party/libjingle/trunk/out/
	cd ./3d_party/openssl; make clean
	./node_modules/.bin/node-gyp clean

.PHONY: build clean prepare deps test
