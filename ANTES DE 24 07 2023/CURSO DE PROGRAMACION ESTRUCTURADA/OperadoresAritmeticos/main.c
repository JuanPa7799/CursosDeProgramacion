#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int rSum;
    float rRes;

    float rMult;
    int rMod;

    rSum = 7+3;
    rRes = 7.1 - 3.1;
    rDiv = 7.0 / 3.0;
    rMult = 7*3;
    rMod = 7 % 3 ;

    printf("Resultado de la suma: %i\n", rSum);
    printf("Resultado de la resta: %f\n", rRes);
    printf("Resultado de la division: %f\n", rDiv);
    printf("Resultado de la multiplicacion: %f\n", rMult);
    printf("Resultado del modulo: %i\n", rMod);*/

    float ar;
    float vol;
    float al;
    float radio;

    printf("Ingresa el valor del radio: \n");
    scanf("%f", &radio);

    printf("Ingresa el valor de la altura del cilindro: \n");
    scanf("%f", &al);

    ar=3.1416*radio;

    vol=ar*al;

    printf("El area de la base del cilindro es: %f\n", ar);
    printf("El volumen del cilidro es: %f\n", vol);

    float grF;
    double grC;
    float div;

    printf("Ingresa el valor de la temperatura en grados Fahrenheit: \n");
    scanf("%f", &grF);

    grC = (grF - 32) ;
    div= 5.0/9.0;
    grF =((grC)*(div));
    grC = grF;

    printf("La temperatura en grados Celcius es: %f\n", grC);

    return 0;
}
