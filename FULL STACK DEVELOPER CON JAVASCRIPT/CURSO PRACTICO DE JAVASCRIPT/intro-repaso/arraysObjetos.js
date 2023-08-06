//Un array es unba lista de elementos.

const array = [1,"jsjs", true, false];

//Un objeto es unalista de elemetnos pero cad aelemento tiene un nombre clave. como un dccionario.

const obj = {
    nombre: "Fulanito",
    edad: 3,
    comidasFavoritas: ["Pollo frito", "vegeetales"],
};

//Arrays cuando lo que hgaremos en un elemento es lo mismo ent ddos losdemas.Mientras un objeto cuando los nombres d ecad elemetno son iportantes para alñforirno,


function imprimirPrimerElemetoArray(arr){
    console.log(arr[0]);
}


imprimirPrimerElemetoArray("Juanita", "Rigoberto", "NAtilla");




function imprimirPrimerElemetoArray2(arra){
    for (let i =0; i < arra.lenght; i++){
        console.log(arra[i]);
    }
}

Object.values(obj);

const arr =Object.values(obj);


function imprimirElementoPorElementoUnObjeto(obj){
    const arr   = Object.values(obj);
    for (let i = 0; i < arr.length; i++) {
        console.log (arr[i]);
        
    }
}