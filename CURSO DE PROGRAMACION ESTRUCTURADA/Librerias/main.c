#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{
    printf("Libreria\n");

    float firstValue = 10;
    float secondValue = 15;
    float result;
    int option;

    printf("Soy una calc \n");
    printf("Que operacion deseas realizar?\n");
    printf("1.-Suma \n");
    printf("2.-Resta \n");
    printf("3.-Multiplicacion \n");
    printf("4.-Division \n");

    scanf("%i", &option);

    switch (option)
    {
        case 1:
            result = additionP(firstValue, secondValue);
            break;
        case 2:
            result=substraccionP(firstValue, secondValue);
            break;
        case 3:
            result=multiplicationp(firstValue, secondValue);
            break;
        case 4:
            result=divisionP(firstValue, secondValue);
            break;
        default:
            printf("Opcion invalida, vuelve a elgir\n");
            main();
            break;

    }
    printf("El resultado es: %f", result);

    return 0;
}
