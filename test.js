var a = require("./build/Release/rtc.node");

var c = new a.Client();

//c.setOnDescriptionReadyCallback(function(desc) { console.log("Called setOnDescriptionReadyCallback"); console.log(desc); })

c.beInitiator();
