var jf = require ("johnny-five");
var circuito  = new jf.Board();

circuito.on("ready", prender);

function prender()
{
  var led = new jf.Led(9);
  led.blink(50);
  console.log("Hola mama se hacer hadware");
}
