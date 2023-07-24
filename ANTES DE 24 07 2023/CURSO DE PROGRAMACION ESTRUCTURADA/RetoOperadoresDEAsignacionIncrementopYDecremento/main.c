#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int entero;

    x+=(x*2);
    printf("El valor de x es: %i\n", x);

    printf("Ingresa el valor de un entero para las operaciones a realizar:\n");
    scanf("%i", &entero);

    entero%=5;
    entero++;

    printf("El valor del entero es: %i\n", entero);

    return 0;
}
