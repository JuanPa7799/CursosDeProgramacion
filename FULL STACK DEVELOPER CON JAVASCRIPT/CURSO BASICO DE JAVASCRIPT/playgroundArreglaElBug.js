// En este desafío debes ayudarnos a arreglar la función solution.

// Esta recibe un array cars y debería retornar el array filtrado únicamente con los objetos que tengan la propiedad licensePlate.

// Pero no está funcionando.

// La función solo devuelve un objeto con el primer elemento que cumple los requisitos, no estamos recibiendo los demás elementos del array que también deberían pasar el filtro.

// ¿Nos ayudas? ¿Cómo solucionarías el error?


export function solution(cars) {
    // 👇 Este es el código que no funciona
    // return cars.find(function (car) {
        //! El error estuvo  querer usar find, ya quesolo devuleve el priemr valor que cumpla, mientras que filter devuelve todos.
    return cars.filter(function (car) {
      if (car.licensePlate) {
        return true;
      } else {
        return false;
      }
    });
  }
  