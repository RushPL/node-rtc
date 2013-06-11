all: prepare deps build

prepare:
	git submodule update --init
	mkdir -p ./3d_party/libjingle; cd ./3d_party/libjingle; ../depot_tools/gclient config http://libjingle.googlecode.com/svn/trunk; GYP_GENERATORS=make ../depot_tools/gclient sync --force;
	npm install

deps:
	cd 3d_party/openssl; ./config; make;
	cd 3d_party/libjingle/trunk; make;

build:
	./node_modules/.bin/node-gyp configure
	./node_modules/.bin/node-gyp build

test:
	./build/Release/client.test.run

clean:
	./node_modules/.bin/node-gyp clean

.PHONY: build clean prepare deps test
