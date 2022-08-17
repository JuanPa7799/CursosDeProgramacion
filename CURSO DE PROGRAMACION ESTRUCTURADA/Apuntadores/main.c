#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Apuntadores\n");

    float val;

    float *apVal;

    apVal = &val;

    *apVal = 3.1416;

    printf("EL valor de la variable val es: %f\n", val);

    return 0;
}


//Asignar el valor de una variable desde un apuntador.
int maeistra()
{
    printf("Apuntadores.\n\n");

    //Variable que vamos a modificar desde su posicion en memoria.
    float val;
    //Variable apuntador.
    float *apVal;

    //Guardamos la posicion de memoria de la variable val en el apuntador.
    apVal = &val;

    //Asignamos un valor float a la posicion de memoria guardada en el apuntador.
    *apVal = 3.1416;

    //Comprobamos que la variable se lleno desde el apuntador.
    printf("El valor de la variable es: %f\n", val);

    return 0;
}
