var articulos =[
    { nombre : "Bici", costo: 3000},
    { nombre : "Television", costo: 2500},
    { nombre : "Libro", costo: 320},
    { nombre : "Celular", costo: 10000},
    { nombre : "Laptop", costo: 20000},
    { nombre : "Teclado", costo: 500},
    { nombre : "Audifonos", costo: 1700}
];

var articulosFiltrados = articulos.filter(function(articulo){
    return articulo.costo <= 500;
});

articulosFiltrados;

var nombreArticulos = articulos.map(function(articulo){
    return articulo.nombre;
})

nombreArticulos;

