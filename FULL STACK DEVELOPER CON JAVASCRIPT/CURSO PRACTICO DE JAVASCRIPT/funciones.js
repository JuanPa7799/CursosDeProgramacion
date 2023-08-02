//las funciones son la forma en como encapsulamos bloques de codigo, para reutilizarlo en el futuro.

function nombreCompleto(name, LastName){
    return name + " " + LastName; 
}


nombreCompleto("Juan", "Garcia");


function saludo(name, LastName,nickName){
    const completeName = nombreCompleto(name, LastName);
    
    console.log("Mi nombre es " + completeName + ", pero prefiero que me digas "+ nickName+".")
}

saludo("Juan", "Garcia", "JuanPa")



