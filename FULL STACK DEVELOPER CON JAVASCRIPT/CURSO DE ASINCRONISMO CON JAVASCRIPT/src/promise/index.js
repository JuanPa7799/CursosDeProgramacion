const promise = new Promise(function (resolve, reject) {
    resolve ('Hey');
});

const cows = 9; 

const countCows = new Promise((resolve, reject) => {
    if (cows > 10) {
        resolve(`We have enough cows (${cows}) for the milk request on the farm`);
    }else{
        reject(`There is now cows (${cows}) on the farm`);
    }
});

countCows.then((result)=>{
    console.log(result);
}).catch((error)=>{
    console.log(error);
}).finally (()=>console.log(`Finally`));