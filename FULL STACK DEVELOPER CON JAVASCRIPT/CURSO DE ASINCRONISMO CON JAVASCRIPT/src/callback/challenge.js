const XMLHttpRequest =require('xmlhttprequest');
const API = 'https://api.escuelajs.co/api/v1';

function fetchData(urlAPI, callback) {
    let xhttp = new XMLHttpRequest();

    xhttp.open('GET', urlAPI, true);
    xhttp.onreadystatechange =function (event) {
        if (xhttp.readyState === 4) {
            if (xhttp.status === 200) {
                callback(null, JSON.parse(xhttp.responseText))
            }
        }else{
            const error = new Error('Error'+ urlAPI);
            return callback(error, null);
        }
    }
    xhttp.send();
}