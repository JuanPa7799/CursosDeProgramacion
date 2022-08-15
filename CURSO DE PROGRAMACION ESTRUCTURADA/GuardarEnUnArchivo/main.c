#include <stdio.h>
#include <stdlib.h>

struct personalData
{
    char name[20];
    char lastName[20];
    int age;
};

int main()
{
    printf("Estructura de datosd\n");

    struct personalData person;

    FILE *archivo;

    //archivo = fopen("DatosPresonales001.dat", "wb");
    archivo = fopen("DatosPresonales001.dat", "rb");

    if(archivo !=NULL)
    {
        printf("El archivo se ha creado exitosamente. Comprueba en la carpeta que se ha creado . \n");

        /*fflush(stdin);

        printf("Leer los datos: \n");
        printf("Ingresar nombre: \n");
        gets(person.name);

        printf("Ingresar apellido: \n");
        gets(person.lastName);

        printf("Ingresar edad: \n");
        scanf("%i", &person.age);

        printf("Imprimir datos: \n");
        printf("%s \n", person.name);
        printf("%s \n", person.lastName);
        printf("%i \n", person.age);

        fwrite(&person, sizeof(person), 1, archivo);*/

        fread(&person, sizeof(person), 1, archivo);

        printf("Imprimir los datos \n");
        printf("Nombre: %s \n", person.name);
        printf("Apellido: %s \n", person.lastName);
        printf("Edad: %i \n", person.age);

        fclose(archivo);

    }else{
        printf("El archivo no se ha creado");
    }



    return 0;
}
