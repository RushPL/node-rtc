var assert = require('chai').assert;
var SandboxedModule = require('sandboxed-module');

describe('NodeRTCPeerconnection', function() {
  it('should load', function(done) {
    var rtcModule = require('../build/Release/rtc.node');
    assert.notEqual(rtcModule.NodeRTCPeerconnection, undefined);
    done();
  });
});

