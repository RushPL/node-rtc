var a = require("./build/Release/rtc.node");

var initiator = new a.Client();

var responder = new a.Client();

var onInitiatorIceCandidateCallback = function(desc) {
  console.log("Called onIceCandidateCallback");
  console.log(desc);
}

var onInitiatorSessionDescriptionCallback = function(sdp) {
  console.log("Called onSessionDescriptionReady");
  console.log(sdp);
}

initiator.beInitiator(onInitiatorSessionDescriptionCallback, onInitiatorIceCandidateCallback);
