var estudiantes = ["Maria", "Sergio", "Rosa", "Daniel"];

function saludarEstudiantes(estudiante){
    console.log( `Hola, ${estudiante} `) ;
}

while (estudiantes.length > 0){
    var estudiante= estudiantes.shift();
    console.log(estudiante);
    saludarEstudiantes(estudiante);
}