// const h1 = document.querySelector("h1");
// const p = document.querySelector("p");
// const parrafito = document.getElementsByClassName("parrafito");
// const pid = document.getElementById("pid");
// const input = document.querySelector("input");


// console.log(input.value);


// console.log({
//     h1,
//     p,
//     parrafito,
//     pid,
//     input
// });

// h1.innerHTML= "Patito <br> Feo"; //! Nos permite modificar el html dentro de nuestro HMTL
// h1.innerText= "Patito <br> Feo"; //! Nos permite modificar el puro texto dentro de nuestro HMTL
// console.log(h1.getAttribute("class"));
// h1.setAttribute("class", "rojo");


// h1.classList.add("morado");
// h1.classList.remove("rojo");
// h1.classList.toogle("rojo"); //!Aternar
// h1.classList.contains("rojo"); //!Condicional si la clase tiene lo que estemso preugntando.


// input.value=12779;

// console.log(document.createElement("img"));     

// const img= document.createElement("img");

// img.setAttribute("src", "https://images.pexels.com/photos/17759970/pexels-photo-17759970/free-photo-of-madera-ligero-carretera-paisaje.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1");
// console.log(img);
// pid.innerHTML="";
// pid.appendChild(img);

const h1 = document.querySelector("h1");
const form = document.querySelector("#form"); 
const input1 = document.querySelector("#calculo1");
const input2 = document.querySelector("#calculo2");
const btn = document.querySelector("#btnCalcular");
const pResult = document.querySelector("#result");


// btn.addEventListener("click", btnOnClick); //!Aqui no se deben llamar los parentesis el addEventListener ya pone lso parentesis al seugndo parametro al saber que es una funcion.

// function btnOnClick() {
    //     //Number(), paseInt
    //     console.log(Number(input1.value) + parseInt(input2.value));
    //     const sumaInputs=Number(input1.value) + parseInt(input2.value) 
    //     pResult.innerText = "Resultado: " + sumaInputs;
    // }

// form.addEventListener("submit", sumarInpuValues);

// function sumarInpuValues(event) {

//     console.log({event});
//     event.preventDefault();
//     //Number(), paseInt
//     console.log(Number(input1.value) + parseInt(input2.value));
//     const sumaInputs=Number(input1.value) + parseInt(input2.value) 
//     pResult.innerText = "Resultado: " + sumaInputs;
// }

form.addEventListener("click", sumarInpuValues);

function sumarInpuValues(event) {

    //console.log({event});
    //event.preventDefault();
    //Number(), paseInt
    console.log(Number(input1.value) + parseInt(input2.value));
    const sumaInputs=Number(input1.value) + parseInt(input2.value) 
    pResult.innerText = "Resultado: " + sumaInputs;
}










