#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Condicion if\n");

    float valA, valB, valc;
    valA = valB = 100;

    printf("Primera condicion\n");
    if(valA == valB)
        printf("Ambos son iguales\n");

    printf("Segunda condicion\n");

    if (valA == valB)
    {
        printf("Ambos son iguales \n");
        valc = valA+valB;
        printf("La suma de ambos numeros es: %f\n", valc);
    }

    return 0;
}
