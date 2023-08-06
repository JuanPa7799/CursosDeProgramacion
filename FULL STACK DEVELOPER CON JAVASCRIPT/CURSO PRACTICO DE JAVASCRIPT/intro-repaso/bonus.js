function cosneguirTipoSuscripcion(tipoDeSuscripcion){
    if (tipoDeSuscripcion =="Free"){
        return console.log("Solo puedes tomar los cursos gratis");
        
    }
    if (tipoDeSuscripcion =="Basic"){
        return console.log("Ouedes tomar casi todos los cursos durante un mes");
    }
    if (tipoDeSuscripcion =="Expert"){
        return console.log("PUedes toamr todos lso cursos durante un año");
    }
    if (tipoDeSuscripcion =="ExpertDou"){
        return console.log("tu y alguien ams pueden tomar casi todos los cursos durante un mes");
    }
}


const tiposDeSuscripciones = {
    free: "Solo puedes tomar los cursos gratis",
    basic: "Puedes tomar casi todos los cursos durante un mes",
    expert: "PUedes toamr todos lso cursos durante un año",
    expertDuo: "Tu y alguien ams pueden tomar casi todos los cursos durante un mes",
}

function conseguirTipoSuscripcion(suscripcion){
    if(tiposDeSuscripciones[suscripcion]){
        console.log(tiposDeSuscripciones[suscripcion])
    }
    console.warn("Este tipo de suscripción no existe.")
}