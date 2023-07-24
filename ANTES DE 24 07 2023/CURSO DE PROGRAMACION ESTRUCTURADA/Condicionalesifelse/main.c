#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf(" Condicon if, else, else if\n");
    float valA, valB, valc;
    valA = 50;
    valB = 100;
    valc = 150;

    printf("Condicion: \n");

    if (valA == valB)
    {
        printf("No se va acumplir esta condicion");
    }    else if (valB == valc)
    {
        printf("Esta tampoco se va a cumplir");
    }    else
    {
        printf("Ninguna condicion se ccumplio \n");
        printf("Despues de esta linea va a terminar");
    }

    return 0;
}
