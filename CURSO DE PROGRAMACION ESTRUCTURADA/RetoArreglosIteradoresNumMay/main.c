#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a;
    int may=0;
    printf("Defina el tamaño del arreglo: ");
    scanf("%i", &a);

    int integerArray[a];

    for(int i = 0;i < a; i++)
    {
        printf("Valor (%i): ", i);
        scanf("%i\n", &integerArray[i]);
        if (integerArray[i]>may)
        {
            may=integerArray[i];
        }
    }

    printf("El numero mayor es: %i", may);

    return 0;
}
