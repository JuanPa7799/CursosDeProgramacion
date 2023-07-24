#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Iteradores For\n");

    int upperLim, bottomLim;

    printf("Imprimir en orden decendiente\n");

    printf("Ingresar limite suoerior;\n");
    scanf("%i", &upperLim);

    printf("Ingresar limite inferior;\n");
    scanf("%i", &bottomLim);

    for(int i=upperLim; i >= bottomLim; i--)
    {
        printf("Numeo: %i\n", i);
    }


    return 0;
}
