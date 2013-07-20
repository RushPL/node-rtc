/***
 *             __         _
 *      _   _ / _| ___   (_)___
 *     | | | | |_ / _ \  | / __|
 *     | |_| |  _| (_) | | \__
 *      \__,_|_|  \___(_)/ |___/
 *                     |__/
 *
 *     Proudly developed by:
 *
 *     boemianrapsodi   @gmail.com
 *     b3by.in.th3.sky  @gmail.com
 *
 *
 *     GitHub URL:
 *
 *     https://github.com/organizations/ufojs
 *
 *   This project is completely open source, and can be
 *   found on GitHub. So, if you like it and would like
 *   to collaborate, just let us know. We're totally on
 *   this sh*t, and appreciate comments and suggestions
 *   as much as we do for bacon.
 *   Do you know what else do we like? Bacon.
 *
 */

var assert = require('chai').assert;
var SandboxedModule = require('sandboxed-module');

describe('NodeRTCPeerconnection', function() {
  it('should load', function(done) {
    var rtcModule = require('../build/Release/rtc.node');
    assert.notEqual(rtcModule.NodeRTCPeerconnection, undefined);
    done();
  });

  it('should throw if no args are passed to constructor', function(done) {
    var rtcModule = require('../build/Release/rtc.node');

    try {
      new rtcModule.NodeRTCPeerconnection();
    }
    catch (error) {
      done();
    }
  });

  it('should accept two json into constructor', function(done) {
    var rtcModule = require('../build/Release/rtc.node');
    var peerconnection = new rtcModule.NodeRTCPeerconnection({}, {});
    done();
  });

  it('should except if first json is invalid', function(done) {
    var rtcModule = require('../build/Release/rtc.node');

    try {
      new rtcModule.NodeRTCPeerconnection('an invalid json', {});
    }
    catch (error) {
      done();
    }
  });

  it('should set the ice server passed into json', function(done) {
    var rtcModule = require('../build/Release/rtc.node');

    var STUN_SERVER = { iceServers: [{ url: 'stun:stun.l.google.com:19302' }] };
    var pc = new rtcModule.NodeRTCPeerconnection(STUN_SERVER, {});
    done();
  });

});

