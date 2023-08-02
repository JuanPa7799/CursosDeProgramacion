var articulos =[
    { nombre : "Bici", costo: 3000},
    { nombre : "Television", costo: 2500},
    { nombre : "Libro", costo: 320},
    { nombre : "Celular", costo: 10000},
    { nombre : "Laptop", costo: 20000},
    { nombre : "Teclado", costo: 500},
    { nombre : "Audifonos", costo: 1700}
];
 //FIND, genera un nuevo array
var encuentraArticulo = articulos.find(function(articulo){
    return articulo.nombre=== "Laptop";
});

///FOREACH, no genera nuevo array

articulos.forEach(function(articulo){
    console.log(articulo.nombre);
});

//SOME, genera nuevo array

var articulosBaratos = articulos.some(function(articulo){
    return articulo.costo <=700;
});//true or false



