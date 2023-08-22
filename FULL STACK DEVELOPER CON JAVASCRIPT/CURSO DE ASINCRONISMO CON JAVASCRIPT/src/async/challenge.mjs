import fetch from "node-fetch";
// var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
const API = 'https://api.escuelajs.co/api/v1';

async function fetchData(urlAPI) {
    const response = await fetch (urlAPI);
    const data = await response.json();
    return data;
}

const anotherFunction = async (urlApi) => {
    try {
        console.log('try succses');
        const products = await fetchData(`${urlApi}/products`);
        console.log('products succses');
        const product = await fetchData(`${urlApi}/products/${products[0].id}`);
        console.log('product id succses');
        const category = await fetchData(`${urlApi}/categories/${product.category.id}`);
        console.log('products category succses');

        console.log(products);
        console.log(product);
        console.log(category);
        
    } catch (error) {
        console.error(error);
    }
}

anotherFunction(API);





