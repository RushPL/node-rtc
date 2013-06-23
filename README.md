node-rtc
========

WebRTC stack for node.js.

The main goal of the project is to build a bind of RTCPeerconnection API for node.js in order to write javascript clients that work both browser and server side.

**Travis CI status is** [![Build Status](https://travis-ci.org/helloIAmPau/node-rtc.png?branch=dev)](https://travis-ci.org/helloIAmPau/node-rtc)

## Steps:

- [x] Build on Linux/Mac
- [x] Integrate Travis CI
- [ ] Use Google Mockup/Test for unit test
- [ ] Use Mocha for integration test
- [ ] Bind default api to Node.js

## Deps:

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



