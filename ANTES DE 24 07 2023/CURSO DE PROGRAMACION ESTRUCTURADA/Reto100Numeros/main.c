#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Reto x numeros naturales\n");

    int a, b;
    a=1;
    b=0;
    int value;

    printf("Ingresa cuantos numeros quieres que se impriman: \n");
    scanf("%i", &value);
    value++;

    do
    {
        printf("%i, ", a);
        a++;
        b++;
        if(b == 10)
        {
            printf("\n");
            b=0;
        }
    }while (a != value);

    printf("\nSimulacion terminada");

    return 0;
}
