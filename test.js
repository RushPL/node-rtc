var a = require("./build/Release/rtc.node");

var onInitiatorIceCandidateCallback = function(candidate) {
  console.log("Called onInitiatorIceCandidateCallback");
  //console.log(candidate);
  responder.setRemoteIceCandidate(candidate);
}

var onInitiatorSessionDescriptionCallback = function(sdp) {
  console.log("Called onInitiatorSessionDescriptionCallback");
  responder.setRemoteDescription("offer", sdp);
}

var onResponderSessionDescriptionCallback = function(sdp) {
  console.log("Called onResponderSessionDescriptionCallback");
  initiator.setRemoteDescription("answer", sdp);
}

var onResponderIceCandidateCallback = function(candidate) {
  console.log("Called onResponderIceCandidateCallback");
  initiator.setRemoteIceCandidate(candidate);
  //console.log(candidate);
}

var initiator = new a.Client(onInitiatorSessionDescriptionCallback, onInitiatorIceCandidateCallback);

var responder = new a.Client(onResponderSessionDescriptionCallback, onResponderIceCandidateCallback);

initiator.beInitiator();
