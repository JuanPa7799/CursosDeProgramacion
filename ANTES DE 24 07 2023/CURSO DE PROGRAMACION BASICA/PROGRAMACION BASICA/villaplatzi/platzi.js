var vp = document.getElementById("villaplatzi");
var papel = vp.getContext("2d");
var mapa = "tile.png";
var fondo = {
  url:"tile.png",
  cargaOK: false
};
var vaca = {
  url:"vaca.png",
  cargaOK: false
};
var cerdo = {
  url:"cerdo.png",
  cargaOK: false
};
var pollo = {
  url:"pollo.png",
  cargaOK: false
};

var cantidad = aleatorio(1, 10);
var cantidadc = aleatorio(1, 10);
var cantidadp = aleatorio(1, 10);

fondo.imagen = new Image();
fondo.imagen.src = fondo.url;
fondo.imagen.addEventListener("load", cargarFondo);

vaca.imagen = new Image();
vaca.imagen.src = vaca.url;
vaca.imagen.addEventListener("load", cargarVacas);

cerdo.imagen = new Image();
cerdo.imagen.src = cerdo.url;
cerdo.imagen.addEventListener("load", cargarCerdos);

pollo.imagen = new Image();
pollo.imagen.src = pollo.url;
pollo.imagen.addEventListener("load", cargarPollos);

function cargarFondo()
{
  fondo.cargarOK = true;
  dibujar();
}

function cargarVacas()
{
  vaca.cargarOK = true;
  dibujar();
}
function cargarCerdos()
{
  cerdo.cargarOK = true;
  dibujar();
}
function cargarPollos()
{
  pollo.cargarOK = true;
  dibujar();
}

function dibujar()
{
  if (fondo.cargarOK)
  {
    papel.drawImage(fondo.imagen, 0, 0);
  }
  if (vaca.cargarOK)
  {

    console.log(cantidad);
    for (var v = 0; v < cantidad; v++) {
      var x= aleatorio(0, 7) * 60;
      var y= aleatorio(0, 7) * 60;
      papel.drawImage(vaca.imagen, x, y);
    }

  }
  if (cerdo.cargarOK)
  {

    console.log(cantidadc);
    for (var v = 0; v < cantidadc; v++) {
      var x= aleatorio(0, 7) * 60;
      var y= aleatorio(0, 7) * 60;
      papel.drawImage(cerdo.imagen, x, y);
    }

  }
  if (pollo.cargarOK)
  {

    console.log(cantidadp);
    for (var v = 0; v < cantidadp; v++) {
      var x= aleatorio(0, 7) * 60;
      var y= aleatorio(0, 7) * 60;
      papel.drawImage(pollo.imagen, x, y);
    }

  }
}

function aleatorio(min, maxi)
{
  var resultado;
  resultado = Math.floor(Math.random() * (maxi -min + 1)) + min;
  return resultado;
}
