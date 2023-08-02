/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

const n = parseInt(readline()); // the number of temperatures to analyse
var inputs = readline().split(' ');
for (let i = 0; i < n; i++) {
    const t = parseInt(inputs[i]);// a temperature expressed as an integer ranging from -273 to 5526
}

function mostCloseToCero(before, newone){
    before2= Math.abs(before);
    newone2= Math.abs(newone);
    if(before==0 && newone==0){
        return 0;
    }else if(before2<newone2){
        return before;
    }else if(before2==newone2 && (before >0 || newone>0 )){
        return before2;
    }else if(before2==newone2&& (before >0 && newone>0 ) ){
        return before;
    }else{
        return newone;
    }
}
if (n==0){
    result=0
}else{
    var result=inputs[1];
    
    for(var num of inputs){
        result=mostCloseToCero(result, num);
    }
}


console.log(result);