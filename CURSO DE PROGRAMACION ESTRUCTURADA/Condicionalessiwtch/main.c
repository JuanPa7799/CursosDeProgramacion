#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Condicional Switch\n");

    int option;

    scanf("%i", &option);

    switch (option)
    {

    case 1:
        printf("Elejiste la opcion mumero 1\n");
        break;
    case 2:
        printf("Elejiste la opcion mumero 2\n");
        break;
    case 3:
        printf("Elejiste la opcion mumero 3\n");
        break;
    default:
        printf("Elejiste una opcion inavalida");
        break;
    }

    return 0;
}
