# UVRun

Bindings to the uvrun functions in libuv to node.js.

Normally these functions are implicitly called by node itself.

By using runOnce, you can have finer grained control of the event loop and know when it's idle.

```js
var runOnce = require('uvrun').runOnce;
 
// Do something here, like make a server to keep the event loop busy
var TCP = process.binding('tcp_wrap').TCP;
var server = new TCP();
server.onconnection = function () {
  console.log("connection!");
};
server.bind("0.0.0.0", 3000);
server.listen(511);
 
// Visualize each event loop tick using a custom event loop.
console.log("Waiting for events...");
do {
  var ret = runOnce();
  console.log("tick", Date.now());
} while(ret);
// If the code gets here, there are no events left and node's built-in uv_run won't block.
```
