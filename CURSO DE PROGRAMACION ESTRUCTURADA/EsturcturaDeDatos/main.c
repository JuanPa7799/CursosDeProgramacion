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

    return 0;
}
