var texto = document.getElementById("texto_lineas");
var boton = document.getElementById("botoncito");
boton.addEventListener("click", dibujoPorClick);

var d = document.getElementById("dibujito"); //getElementsById es un metodo del documento
var ancho = d.width;

var lienzo = d.getContext("2d"); //getContext metodo de canva contxto 2d
//lienzo es el contexto 2d que se trajo de canvas, y tiene varios atributos


function dibujarLineas(color, xinicial, yinicial, xfinal, yfinal)
{
  lienzo.beginPath(); //arrancar dibujo no tine eparametros
  lienzo.strokeStyle = color;//es un atributo una propiedad del objeto lienzo.
  lienzo.moveTo(xinicial, yinicial); //funcion con multiples parametros
  lienzo.lineTo(xfinal, yfinal); // x,y
  lienzo.stroke(); //funcion /Hecho de trazar la ralla
  lienzo.closePath(); //parar dibujo
}

function dibujoPorClick()
{
  var lineas = parseInt(texto.value);
  var l = 0;
  var yi, xf;
  var colorcito= "#FAA";
  var espacio = ancho / lineas;

  for (l=0; l < lineas; l++)
  {
    xi = espacio * l;
    yf = espacio * l + 1;
    dibujarLineas("#AAF", xi, 0, 300, yf);
    console.log ("Linea " + l);
  }

  for (l=0; l < lineas; l++)
  {
    yi = espacio * l;
    xf = espacio * l + 1;
    dibujarLineas("#FAA", xf, 300, 0, yi);
    console.log ("Linea " + l);
  }

  for (l=0; l < lineas; l++)
  {
    yf = 300 - (espacio * l);
    xi =espacio * l + 1;
    dibujarLineas("#AFF", xi, 0, 0, yf);
    console.log (yf);
  }

  for (l=0; l < lineas; l++)
  {
    yi = espacio * l;
    xf =300 - (espacio * l + 1);
    dibujarLineas("#FAF", 300, yi, xf, 300);
    console.log (yf);
  }

  dibujarLineas(colorcito, 1, 1, 1, ancho-1);
  dibujarLineas(colorcito, 1, ancho-1, ancho-1, ancho-1);
  dibujarLineas(colorcito, 1, 1, ancho-1, 1);
  dibujarLineas(colorcito, ancho-1, 1, ancho-1, ancho-1);
}
