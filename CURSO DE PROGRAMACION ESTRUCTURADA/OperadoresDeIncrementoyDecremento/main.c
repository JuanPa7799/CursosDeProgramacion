#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Operadores de incremento y decremento\n");

    int value, res;

    value = 25;

    res = value++;
    printf("Resultado: %i\n", res);

    value = 25;

    res=++value;
    printf("Reusltado: %i\n", res);

    value = 25;

    res=value--;
    printf("Reusltado: %i\n", res);

    value = 25;

    res=--value;
    printf("Reusltado: %i\n", res);


    return 0;
}
