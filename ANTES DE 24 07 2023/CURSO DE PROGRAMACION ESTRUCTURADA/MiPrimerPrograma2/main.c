#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int integerA;
    int integerB;
    int cambio;

    //Lectura del usuario apra cada numero.
    printf("Ingresa el valor del entero A: ");

    scanf("%i", &integerA);

    printf("Ingresa el valor del entero A: ");

    scanf("%i", &integerB);

    //Cambio de variables
    cambio=integerA;
    integerA=integerB;
    integerB=cambio;

    //Impresion de los enteros
    printf("El entero A es: %i\n", integerA);
    printf("El entero B es: %i\n", integerB);

    //En la siguiente linea estamos imprimiendo mi variable integerA
    //printf("El valor de nuestro entero A es: %i, \nEl valor de mi flotnate A es: %f, \nEl valor de mi double A es: %f, \nEl valor de mi caracter A es: %c ", integerA, floatA,doubleA,letterA );

    return 0;
}
