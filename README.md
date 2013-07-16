node-rtc
========

Help this project: https://www.bountysource.com/#fundraisers/377-nodertc

WebRTC stack for node.js.

The main goal of the project is to build a bind of RTCPeerconnection API for node.js in order to write javascript clients working both browser and server side.

* **Travis CI status is** [![Build Status](https://travis-ci.org/helloIAmPau/node-rtc.png?branch=dev)](https://travis-ci.org/helloIAmPau/node-rtc)
* **Latest published version is** [![NPM version](https://badge.fury.io/js/node-rtc.png)](http://badge.fury.io/js/node-rtc)
* **Stories in Ready are** [![Stories in Ready](http://badge.waffle.io/helloIAmPau/node-rtc.png)](http://waffle.io/helloIAmPau/node-rtc)  

## Steps:

- [x] Build on Linux/Mac
- [x] Integrate Travis CI
- [x] Use Mocha for testing
- [ ] Bind default api to Node.js

## [Linux] Deps:

some additional packets are required to enable audio/video features of peerconnection

```bash
  sudo apt-get install -qq libnss3 \
        libnss3-dev \
        libnss3-tools \
        libasound2 \
        libasound2-dev \
        libpulse-dev \
        libpulse0
```



