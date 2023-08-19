// const XMLHttpRequest =require('xmlhttprequest');
var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
const API = 'https://api.escuelajs.co/api/v1';

function fetchData(urlAPI, callback) {
    let xhttp = new XMLHttpRequest();

    xhttp.open('GET', urlAPI, true);
    xhttp.onreadystatechange = function (event) {
        if (xhttp.readyState === 4) {
            if (xhttp.status === 200) {
                callback(null, JSON.parse(xhttp.responseText));
            }else{
                const error = new Error('Error '+ urlAPI + xhttp.status);
                return callback(error, null);
            };
        };
    };
    xhttp.send();
};

fetchData(`${API}/products`, function (error1, data1) {
    if (error1) return console.error(error1);
    fetchData(`${API}/products/${data1[0].id}`, function (error2, data2) {
        if(error2) return console.error(error2);
        fetchData(`${API}/categories/${data2?.category?.id}`, function (error3, data3) {
            if (error3) return console.error(error3);
            console.log(data1[0]);
            console.log(data2.title);
            console.log(data3.name);
        })
    })
});




// const XMLHttpRequest = require('xmlhttprequest').XMLHttpRequest; // instanciamos xmlhttprequest.
// const API = 'https://api.escuelajs.co/api/v1'; // API donde vamos a traer los datos.
// // estados: 0 no iniciado - 1 cargando, aún no se llama a send - 2 cuando ya se ejecuto send
// // 3 interactuando con la solicitud - 4 se ha completado la llamada.
// // status: 200 solicitud correcta - 400 errores - 500 errores del servidor.
// function fetchData(urlApi, callback) { // función donde generamos la conexión, recibe urlApi y un callback.
//     let xhttp = new XMLHttpRequest(); // generamos una nueva instancia más corta en xhttp.
//     xhttp.open('GET', urlApi, true); // abrimos una conexión con el método GET, urlApi y true para asincronismo.
//     xhttp.onreadystatechange = function (event) { // cuando este cambio suceda, escuchamos el estado:
//         if (xhttp.readyState === 4) { // comparamos el estado que sea igual a 4 (completado).
//             if (xhttp.status === 200) { // comparamos el estatus sea igual a 200 (solicitud correcta).
//                 callback(null, JSON.parse(xhttp.responseText)); // retornamos callback null en error. Parse de datos.
//             } else { // si lo anterior no ocurre:
//                 const error = new Error('Error' + urlApi); // generamos un nuevo error + urlApi.
//                 return callback(error, null); // retornamos callback con el error y null(para los datos).
//             };
//         };
//     };
//     xhttp.send(); // Enviamos el llamado o solitud.
// };

// *// en el ejemplo se hacen varios llamados a modo de ejemplo, en el setTimeout del fi1nal se muestra la misma
// // información de otra posición solo con el primer llamado, incluyendo el precio.
// fetchData(`${API}/products`, function (error1, data1) { // llamamos la función con argumentos de url y func anónima.
//     if (error1) return console.error(error1); // si se genera error retornamos error, info en data 1.
//     fetchData(`${API}/products/${data1[0].id}`, function(error2, data2) { // volvemos a llamar a la función.
//         if (error2) return console.error(error2); // retornamos error2 (si se produce) e info guardada en data2.
//         fetchData(`${API}/categories/${data2?.category?.id}`, function(error3, data3) { // 3er llamado a la func.
//             if (error3) return console.error(error3); // retorn. error3 (si se produce). Info guardada en data3.
//             console.log(data1[0]); // mostramos los datos de la primer llamada (estudiar la api).
//             console.log(data2.title); // mostramos los datos de la 2da llamada.
//             console.log(data3.name); // 3er llamada.
//         });
//     });
// });

