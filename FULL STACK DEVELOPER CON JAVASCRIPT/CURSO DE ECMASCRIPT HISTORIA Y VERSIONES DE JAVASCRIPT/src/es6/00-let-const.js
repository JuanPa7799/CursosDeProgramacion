var lastName = "Juan"
lastName =  " Oscar"
console.log(lastName);

let fruit = "Apple"; 
fruit = "Kiwi";
console.log(fruit);

const animal= "Dog";
animal= "cat";
console.log(animal);

const fruits = () =>{
    if (true) {
        var fruit1= "Apple"; // Funcion scope
        let fruit2= "Kiwi"; // Block scope
        const fruit3 = "Banana"; // Block scope
    }
    console.log(fruit1);
    console.log(fruit2);
    console.log(fruit3);
}

fruits();


