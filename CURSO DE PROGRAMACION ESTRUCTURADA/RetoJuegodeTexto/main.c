#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Te encuentras en un sueño y tienes trs caminos\n");
    printf("Escribe 1 si quieres ir por el camino de dulces\n");
    printf("Escribe 2 si quieres ir por el camino de madera\n");
    printf("Escribe 3 si quieres ir por el camino de gatitos\n");
    printf("Escribe otro numero si quieres acabar la simulacion\n");

    int option;

    scanf("%i", &option);

    switch (option)
    {

    case 1:
        printf("Moriste. vuelve a intentarlo\n");
        main();
        break;
    case 2:
        printf("Moriste. vuelve a intentarlo\n");
        main();
        break;
    case 3:
        printf("Los gatitos lindos te llevan a una puerta y al cruzarla te despiertas.\n FIN DEL JUEGO");
        break;
    default:
        printf("Elejiste una opcion inavalida. \nFIN DEL JUEGO");
        break;
    }

    return 0;
}
