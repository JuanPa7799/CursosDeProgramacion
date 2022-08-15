#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Cadena de caracteres\n");

    char nameC[50];

    int size;

    printf("Ingresar el nombre con gets: \n");

    gets(nameC);

    printf("El nombre es: ");
    puts(nameC);

    size=strlen(nameC);

    printf("\n El tamaño de la cadena es: %i \n", size);
    return 0;
}
