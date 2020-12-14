var protobuf = require("protobufjs");
/*
protobuf.load("../message.proto")
    .then(function(root) {
       console.log(root);
    });
*/

protobuf.load("../message.proto", function(err, root) {
    if (err)
        throw err;
 
    // Obtain a message type
    var myMessage = root.lookup("pb_message_t");
 
    b = Buffer.from('086410031A090801120548656C6C6F1A090801120548656C6C6F1A090801120548656C6C6F220608F60410CE09', 'hex');
    console.log(b);
 
    // Decode an Uint8Array (browser) or Buffer (node) to a message
    var message = myMessage.decode(b);
    // ... do something with message
    //console.log(message);
    console.log(JSON.stringify(message, null, 4));

});