var teclas = {
  UP: 38,
  DOWN: 40,
  LEFT: 37,
  RIGHT: 39
};

console.log(teclas);
document.addEventListener("keydown", dibujarTeclado);
var cuadrito = document.getElementById("area_de_dibujo");
var papel = cuadrito.getContext("2d");
var x = 150;
var y = 150;

dibujarLineas("red", x-1, y-1, x+1, y+1, papel);

function dibujarLineas(color, xinicial, yinicial, xfinal, yfinal, lienzo)
{
  lienzo.beginPath(); //arrancar dibujo no tine eparametros
  lienzo.strokeStyle = color;//es un atributo una propiedad del objeto lienzo.
  lienzo.lineWidth = 3; //ancho d epixeles de la linea
  lienzo.moveTo(xinicial, yinicial); //funcion con multiples parametros
  lienzo.lineTo(xfinal, yfinal); // x,y
  lienzo.stroke(); //funcion /Hecho de trazar la ralla
  lienzo.closePath(); //parar dibujo
}

function dibujarTeclado(evento)
{
  var   colorcito = "blue";
  var  movimeinto = 1;
  switch (evento.keyCode) {
    case teclas.UP:
            dibujarLineas(colorcito, x, y, x, y - movimeinto, papel);
            y = y - movimeinto;
      break;
    case teclas.DOWN:
        dibujarLineas(colorcito, x, y, x, y + movimeinto, papel);
        y = y + movimeinto;
      break;
      case teclas.LEFT:
          dibujarLineas(colorcito, x, y, x - movimeinto, y , papel);
          x = x - movimeinto;
        break;
      case teclas.RIGHT:
          dibujarLineas(colorcito, x, y, x + movimeinto, y , papel);
          x = x + movimeinto;
        break;
    default:
      console.log("oTRA teclas");
    break;

  }

}
